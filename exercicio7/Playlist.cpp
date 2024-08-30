#include "Playlist.h"
#include <iostream>

using namespace std;

void Playlist::adicionarMusica(const Musica& musica) {
    musicas.push_back(musica);
}

void Playlist::ordenarPorCategoria() {
    for (size_t i = 1; i < musicas.size(); i++) {
        Musica chave = musicas[i];
        int j = i - 1;

        while (j >= 0 && musicas[j].getCategoria() > chave.getCategoria()) {
            musicas[j + 1] = musicas[j];
            j = j - 1;
        }

        musicas[j + 1] = chave;
    }
}

void Playlist::imprimirPlaylist() const {
    for (const Musica& musica : musicas) {
        cout << "Nome: " << musica.getNome() << ", Categoria: " << musica.getCategoria() << '\n';
    }
}
