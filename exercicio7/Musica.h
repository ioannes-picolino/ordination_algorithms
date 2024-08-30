#ifndef MUSICA_H
#define MUSICA_H

#include <string>

using namespace std;

class Musica {
private:
    string nome;
    string categoria;

public:
    Musica(std::string nome, std::string categoria);
    
    string getNome() const;
    string getCategoria() const;
};

#endif
