// main.cpp
#include <iostream>
#include <vector>
#include "Jogador.h"

using namespace std;

void selectionSort(std::vector<Jogador>& jogadores) {
    int n = jogadores.size();

    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (jogadores[j].getPontuacao() > jogadores[max_idx].getPontuacao()) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(jogadores[i], jogadores[max_idx]);
        }
    }
}

int main() {
    vector<Jogador> jogadores = {{"Maria", 100}, {"João", 80}, {"Carlos", 120}, {"Davi", 90}};

    selectionSort(jogadores);

    cout << "Ranking dos jogadores (ordem decrescente de pontuação):" << '\n';
    for (const Jogador& jogador : jogadores) {
        cout << jogador.getNome() << " - Pontuação: " << jogador.getPontuacao() << '\n';
    }

    return 0;
}
