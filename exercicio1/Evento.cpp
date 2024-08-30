#include "Evento.h" 

using namespace std; 

Evento::Evento(string descricao, string dataHora) { 

    this->descricao = descricao; 

    this->dataHora = dataHora; 

} 

 

void Evento::imprimirEvento() { 

    cout << "Descrição: " << descricao << " -Data e Hora: " << dataHora << '\n'; 

} 

 

string Evento::getDataHora() { 

    return dataHora; 

} 