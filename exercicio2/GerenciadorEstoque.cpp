// GerenciadorEstoque.cpp

#include "GerenciadorEstoque.h"
#include <algorithm>
#include <iostream>

using namespace std; 

void GerenciadorEstoque::adicionarProduto(Produto produto) {
    produtos.push_back(produto);
}

void GerenciadorEstoque::ordenarProdutosPorEstoque() {
    int n = produtos.size();
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (produtos[j].getNivelEstoque() < produtos[min_idx].getNivelEstoque()) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Produto temp = produtos[i];
            produtos[i] = produtos[min_idx];
            produtos[min_idx] = temp;
        }
    }
}

void GerenciadorEstoque::imprimirProdutos() {
    for (size_t i = 0; i < produtos.size(); i++) {
        cout << "Nome: " << produtos[i].getNome() << ", Nível de Estoque: " << produtos[i].getNivelEstoque() << '\n';
    }
}
