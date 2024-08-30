#include "Musica.h"
#include "Playlist.h"
#include <iostream>

using namespace std;

int main() {
    Playlist playlist;

    playlist.adicionarMusica(Musica("Musica1", "Rock"));
    playlist.adicionarMusica(Musica("Musica2", "Pop"));
    playlist.adicionarMusica(Musica("Musica3", "Rock"));
    playlist.adicionarMusica(Musica("Musica4", "Jazz"));

    cout << "Playlist antes da ordenacao:\n";
    playlist.imprimirPlaylist();

    playlist.ordenarPorCategoria();

    cout << "\nPlaylist depois da ordenacao por categoria:\n";
    playlist.imprimirPlaylist();

    return 0;
}
