#include "FlyingInsect.h"
#include <iostream>

using namespace std;

FlyingInsect::FlyingInsect(const string& name, int weight, int lifespanDays, const string& color, float wingSpan)
    : Insect(name, weight, lifespanDays, color), wingSpan(wingSpan) {
}

void FlyingInsect::move() const {
    cout << "Se desplaza volando.\n";
}

void FlyingInsect::describe() const {
    cout << "Nombre: " << name << "\n";
    cout << "Peso: " << weight << " mg\n";
    cout << "Vida estimada: " << lifespanDays << " dias\n";
    cout << "Color: " << color << "\n";
    cout << "Envergadura: " << wingSpan << " cm\n";
}
