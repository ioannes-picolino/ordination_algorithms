// GerenciadorEstoque.h

#ifndef GERENCIADORESTOQUE_H
#define GERENCIADORESTOQUE_H

#include <vector>
#include "Produto.h"

class GerenciadorEstoque {
private:
    std::vector<Produto> produtos;

public:
    void adicionarProduto(Produto produto);
    void ordenarProdutosPorEstoque();
    void imprimirProdutos();
};

#endif
