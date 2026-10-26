#include "Beetle.h"
#include <iostream>

using namespace std;

Beetle::Beetle(const string& name, int weight, int lifespanDays, const string& color, int shellHardness)
    : Insect(name, weight, lifespanDays, color), shellHardness(shellHardness) {
}

void Beetle::move() const {
    cout << "El escarabajo avanza sobre el suelo.\n";
}

void Beetle::makeSound() const {
    cout << "El escarabajo produce un leve sonido al desplazarse.\n";
}

void Beetle::describe() const {
    cout << "Tipo: Escarabajo\n";
    cout << "Nombre: " << name << "\n";
    cout << "Peso: " << weight << " mg\n";
    cout << "Vida estimada: " << lifespanDays << " dias\n";
    cout << "Color: " << color << "\n";
    cout << "Dureza del caparazon (1-10): " << shellHardness << "\n";
}
