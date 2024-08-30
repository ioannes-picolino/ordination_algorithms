// Jogador.cpp
#include "Jogador.h"

using namespace std;

Jogador::Jogador(string nome, int pontuacao) : nome(nome), pontuacao(pontuacao) {}

string Jogador::getNome() const {
    return nome;
}

int Jogador::getPontuacao() const {
    return pontuacao;
}
