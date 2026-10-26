#include "Butterfly.h"
#include <iostream>

using namespace std;

Butterfly::Butterfly(const string& name, int weight, int lifespanDays, const string& color, float wingSpan, bool migratory)
    : FlyingInsect(name, weight, lifespanDays, color, wingSpan), migratory(migratory) {
}

void Butterfly::move() const {
    cout << "La mariposa vuela entre las flores.\n";
}

void Butterfly::makeSound() const {
    cout << "La mariposa no emite un sonido escuchable.\n";
}

void Butterfly::describe() const {
    cout << "Tipo: Mariposa\n";
    FlyingInsect::describe();
    cout << "Migratoria: " << (migratory ? "Si" : "No") << "\n";
}
