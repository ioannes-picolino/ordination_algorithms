// Produto.cpp

#include "Produto.h"

Produto::Produto(std::string nome, int nivelEstoque) {
    this->nome = nome;
    this->nivelEstoque = nivelEstoque;
}

std::string Produto::getNome() {
    return nome;
}

int Produto::getNivelEstoque() {
    return nivelEstoque;
}

void Produto::setNivelEstoque(int novoNivel) {
    nivelEstoque = novoNivel;
}
