#include "Musica.h"

using namespace std;

Musica::Musica(string nome, string categoria) : nome(nome), categoria(categoria) {}

string Musica::getNome() const {
    return nome;
}

string Musica::getCategoria() const {
    return categoria;
}
