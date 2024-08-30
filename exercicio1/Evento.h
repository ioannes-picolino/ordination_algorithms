#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <string>

using namespace std;

class Evento {
    private:
    string descricao;
    string dataHora;
    
    public:
    Evento (string descricao, string dataHora);
    void imprimirEvento();
    string getDataHora();
};

#endif