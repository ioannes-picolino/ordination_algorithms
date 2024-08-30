// Evento.cpp
#include "Evento.h"

using namespace std;

Evento::Evento(string nome, string data, string horario) : nome(nome), data(data), horario(horario) {}

string Evento::getNome() const {
    return nome;
}

string Evento::getData() const {
    return data;
}

string Evento::getHorario() const {
    return horario;
}
