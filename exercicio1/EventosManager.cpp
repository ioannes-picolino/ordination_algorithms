#include "EventosManager.h" 

#include <algorithm> 

 using namespace std;

void EventosManager::adicionarEvento(Evento evento) { 

    eventos.push_back(evento); 

} 

 

void EventosManager::ordenarEventos() { 
    int n = eventos.size();
    for (int i = 1; i < n; i++){
        Evento chave = eventos[i];
        int j = i - 1;

        while (j>=0 && eventos[j].getDataHora() > chave.getDataHora()){
            eventos[j + 1] = eventos[j];
            j = j -1;
        }
        eventos[j + 1] = chave;
    }
} 

 

void EventosManager::imprimirEventos() { 

    for (Evento evento : eventos) 
    { 

        evento.imprimirEvento(); 

    } 

} 