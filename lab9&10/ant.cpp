#include "ant.h"
#include <iostream>

using namespace std;

Ant::Ant(const string& name, int weight, int lifespanDays, const string& color, int carryCapacity)
    : Insect(name, weight, lifespanDays, color), carryCapacity(carryCapacity) {
}

void Ant::move() const {
    cout << "La hormiga camina en una fila.\n";
}

void Ant::makeSound() const {
    cout << "La hormiga se comunica principalmente mediante senales quimicas.\n";
}

void Ant::describe() const {
    cout << "Tipo: Hormiga\n";
    cout << "Nombre: " << name << "\n";
    cout << "Peso: " << weight << " mg\n";
    cout << "Dias de vida: " << lifespanDays << " dias\n";
    cout << "Color: " << color << "\n";
    cout << "Capacidad de carga: " << carryCapacity << " mg\n";
}
