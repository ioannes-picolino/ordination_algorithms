// Jogador.h
#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

using namespace std;

class Jogador {
private:
    string nome;
    int pontuacao;

public:
    Jogador(string nome, int pontuacao);
    string getNome() const;
    int getPontuacao() const;
};

#endif
