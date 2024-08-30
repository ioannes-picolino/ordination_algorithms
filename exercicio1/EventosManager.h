#ifndef EVENTOSMANAGER_H 

#define EVENTOSMANAGER_H 

 

#include <vector> 

#include "Evento.h" 

using namespace std;
 

class EventosManager { 

private: 

    vector <Evento> eventos; 

 

public: 

    void adicionarEvento(Evento evento); 

    void ordenarEventos(); 

    void imprimirEventos(); 

}; 

 

#endif 