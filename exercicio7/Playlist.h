#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "Musica.h"

class Playlist {
private:
    std::vector<Musica> musicas;

public:
    void adicionarMusica(const Musica& musica);
    void ordenarPorCategoria();
    void imprimirPlaylist() const;
};

#endif
