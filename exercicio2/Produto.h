// Produto.h

#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
private:
    std::string nome;
    int nivelEstoque;

public:
    Produto(std::string nome, int nivelEstoque);
    
    std::string getNome();
    int getNivelEstoque();
    void setNivelEstoque(int novoNivel);
};

#endif
