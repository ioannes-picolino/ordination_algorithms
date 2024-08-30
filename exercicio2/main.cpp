// main.cpp

#include <iostream>
#include "Produto.h"
#include "GerenciadorEstoque.h"

int main() {
    Produto p1("Produto A", 50);
    Produto p2("Produto B", 30);
    Produto p3("Produto C", 20);

    GerenciadorEstoque gerenciador;
    gerenciador.adicionarProduto(p1);
    gerenciador.adicionarProduto(p2);
    gerenciador.adicionarProduto(p3);

    std::cout << "Produtos antes da ordenacao por estoque:" << std::endl;
    gerenciador.imprimirProdutos();

    gerenciador.ordenarProdutosPorEstoque();

    std::cout << "\nProdutos depois da ordenacao por estoque:" << std::endl;
    gerenciador.imprimirProdutos();

    return 0;
}
