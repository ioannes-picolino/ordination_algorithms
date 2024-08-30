#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// Classe Contato
class Contato {
private:
    std::string nome;
    std::string telefone;
    std::string email;
    bool favorito;

public:
    // Construtor padrão
    Contato() : nome(""), telefone(""), email(""), favorito(false) {}

    // Construtor com parâmetros
    Contato(const std::string& nome, const std::string& telefone, const std::string& email, bool favorito = false)
        : nome(nome), telefone(telefone), email(email), favorito(favorito) {}

    // Getters
    std::string getNome() const { return nome; }
    std::string getTelefone() const { return telefone; }
    std::string getEmail() const { return email; }
    bool isFavorito() const { return favorito; }

    // Setters
    void setNome(const std::string& nome) { this->nome = nome; }
    void setTelefone(const std::string& telefone) { this->telefone = telefone; }
    void setEmail(const std::string& email) { this->email = email; }
    void setFavorito(bool favorito) { this->favorito = favorito; }

    // Método para exibir os dados do contato
    void exibirContato() const {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Telefone: " << telefone << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Favorito: " << (favorito ? "Sim" : "Não") << std::endl;
    }
};

// Estrutura da Árvore AVL
struct Node {
    Contato contato;
    Node* left;
    Node* right;
    int height;

    Node(const Contato& contato) : contato(contato), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* N) {
        return N ? N->height : 0;
    }

    int getBalance(Node* N) {
        return N ? height(N->left) - height(N->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, const Contato& contato) {
        if (!node) return new Node(contato);

        if (contato.getNome() < node->contato.getNome())
            node->left = insert(node->left, contato);
        else if (contato.getNome() > node->contato.getNome())
            node->right = insert(node->right, contato);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && contato.getNome() < node->left->contato.getNome())
            return rightRotate(node);

        if (balance < -1 && contato.getNome() > node->right->contato.getNome())
            return leftRotate(node);

        if (balance > 1 && contato.getNome() > node->left->contato.getNome()) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && contato.getNome() < node->right->contato.getNome()) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, const std::string& nome) {
        if (!root) return root;

        if (nome < root->contato.getNome())
            root->left = deleteNode(root->left, nome);
        else if (nome > root->contato.getNome())
            root->right = deleteNode(root->right, nome);
        else {
            if ((!root->left) || (!root->right)) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->contato = temp->contato;
                root->right = deleteNode(root->right, temp->contato.getNome());
            }
        }

        if (!root) return root;

        root->height = 1 + std::max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(Node* root) const {
        if (root) {
            inOrder(root->left);
            root->contato.exibirContato();
            inOrder(root->right);
        }
    }

    void inOrderFavoritos(Node* root) const {
        if (root) {
            inOrderFavoritos(root->left);
            if (root->contato.isFavorito())
                root->contato.exibirContato();
            inOrderFavoritos(root->right);
        }
    }

    Node* search(Node* root, const std::string& nome) const {
        if (!root || root->contato.getNome() == nome)
            return root;

        if (root->contato.getNome() < nome)
            return search(root->right, nome);

        return search(root->left, nome);
    }

    void exportToCSV(Node* root, std::ofstream& file) const {
        if (root) {
            exportToCSV(root->left, file);
            file << root->contato.getNome() << ","
                 << root->contato.getTelefone() << ","
                 << root->contato.getEmail() << ","
                 << (root->contato.isFavorito() ? "Sim" : "Não") << std::endl;
            exportToCSV(root->right, file);
        }
    }

    void importFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        std::string line, nome, telefone, email, favoritoStr;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::getline(ss, nome, ',');
            std::getline(ss, telefone, ',');
            std::getline(ss, email, ',');
            std::getline(ss, favoritoStr, ',');

            bool favorito = (favoritoStr == "Sim");
            Contato contato(nome, telefone, email, favorito);
            root = insert(root, contato);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(const Contato& contato) {
        root = insert(root, contato);
    }

    void deleteNode(const std::string& nome) {
        root = deleteNode(root, nome);
    }

    Node* search(const std::string& nome) const {
        return search(root, nome);
    }

    void inOrder() const {
        inOrder(root);
    }

    void inOrderFavoritos() const {
        inOrderFavoritos(root);
    }

    void exportToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            exportToCSV(root, file);
            file.close();
        }
    }

    void importFromCSV(const std::string& filename) {
        importFromCSV(filename);
    }
};

// Função de menu
void exibirMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Adicionar um novo contato" << std::endl;
    std::cout << "2. Remover um contato existente" << std::endl;
    std::cout << "3. Buscar por um contato específico" << std::endl;
    std::cout << "4. Listar todos os contatos em ordem alfabética" << std::endl;
    std::cout << "5. Listar os favoritos" << std::endl;
    std::cout << "6. Exportar contatos para CSV" << std::endl;
    std::cout << "7. Importar contatos de CSV" << std::endl;
    std::cout << "8. Sair" << std::endl;
}

int main() {
    AVLTree tree;
    int opcao;
    std::string nome, telefone, email, filename;
    bool favorito;

    do {
        exibirMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura da opção

        switch (opcao) {
            case 1: {
                std::cout << "Digite o nome: ";
                std::getline(std::cin, nome);
                std::cout << "Digite o telefone: ";
                std::getline(std::cin, telefone);
                std::cout << "Digite o email: ";
                std::getline(std::cin, email);
                std::cout << "É favorito (1 para sim, 0 para não): ";
                std::cin >> favorito;
                tree.insert(Contato(nome, telefone, email, favorito));
                std::cout << "Contato adicionado com sucesso!" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Digite o nome do contato a ser removido: ";
                std::getline(std::cin, nome);
                tree.deleteNode(nome);
                std::cout << "Contato removido com sucesso!" << std::endl;
                break;
            }
            case 3: {
                std::cout << "Digite o nome do contato a ser buscado: ";
                std::getline(std::cin, nome);
                Node* contatoBuscado = tree.search(nome);
                if (contatoBuscado) {
                    std::cout << "Contato encontrado:" << std::endl;
                    contatoBuscado->contato.exibirContato();
                } else {
                    std::cout << "Contato não encontrado." << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Lista de contatos em ordem alfabética:" << std::endl;
                tree.inOrder();
                break;
            }
            case 5: {
                std::cout << "Lista de contatos favoritos:" << std::endl;
                tree.inOrderFavoritos();
                break;
            }
            case 6: {
                std::cout << "Digite o nome do arquivo para exportar: ";
                std::getline(std::cin, filename);
                tree.exportToCSV(filename);
                std::cout << "Contatos exportados com sucesso!" << std::endl;
                break;
            }
            case 7: {
                std::cout << "Digite o nome do arquivo para importar: ";
                std::getline(std::cin, filename);
                tree.importFromCSV(filename);
                std::cout << "Contatos importados com sucesso!" << std::endl;
                break;
            }
            case 8:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 8);

    return 0;
}
