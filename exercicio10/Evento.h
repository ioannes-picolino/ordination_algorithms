// Evento.h
#ifndef EVENTO_H
#define EVENTO_H

#include <string>

using namespace std;

class Evento {
private:
    string nome;
    string data;
    string horario;

public:
    Evento(string nome, string data, string horario);
    string getNome() const;
    string getData() const;
    string getHorario() const;
};

#endif
