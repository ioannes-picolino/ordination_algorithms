#include <iostream> 

#include "Evento.h" 

#include "EventosManager.h" 

 using namespace std;

int main() { 

    Evento evento1("Evento 1", "2022-10-01 12:30:00"); 

    Evento evento2("Evento 2", "2022-10-01 10:45:00"); 

    Evento evento3("Evento 3", "2022-10-01 15:20:00"); 

 

    EventosManager manager; 

    manager.adicionarEvento(evento1); 

    manager.adicionarEvento(evento2); 

    manager.adicionarEvento(evento3); 

 

    cout << "Eventos não ordenados: " << '\n'; 

    manager.imprimirEventos(); 

 

    manager.ordenarEventos(); 

 

    cout << "\nEventos ordenados: " << '\n'; 

    manager.imprimirEventos(); 

 

    return 0; 

} 