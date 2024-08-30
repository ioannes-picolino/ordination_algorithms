// main.cpp
#include <iostream>
#include <vector>
#include "Evento.h"

using namespace std;

void insertionSort(vector<Evento>& eventos) {
    int n = eventos.size();

    for (int i = 1; i < n; i++) {
        Evento key = eventos[i];
        int j = i - 1;

        while (j >= 0 && eventos[j].getData() > key.getData()) {
            eventos[j + 1] = eventos[j];
            j = j - 1;
        }
        eventos[j + 1] = key;
    }
}

int main() {
    vector<Evento> eventos = {{"Palestra 1", "2022-10-15", "09:00"},
                                   {"Workshop 1", "2022-10-14", "14:30"},
                                   {"Coffee Break", "2022-10-15", "10:30"},
                                   {"Palestra 2", "2022-10-14", "16:00"}};

    insertionSort(eventos);

    cout << "Agenda da Conferência (ordenada por data e horário):" << '\n';
    for (const Evento& evento : eventos) {
        cout << evento.getNome() << " - Data: " << evento.getData() << " - Horário: " << evento.getHorario() << '\n';
    }

    return 0;
}
