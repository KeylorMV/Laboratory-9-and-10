#include "Colony.h"
#include <iostream>

using namespace std;

// Esta funcion permite recorrer la lista y ejecutar metodos virtuales.
void showInsectDetails(Insect* insect, int position) {
    if (insect == nullptr) {
        return;
    }

    cout << "\n----- Insecto " << position << " -----\n";
    insect->describe();
    cout << "Movimiento: ";
    insect->move();
    cout << "Sonido: ";
    insect->makeSound();
}

Colony::Colony() {
}

Colony::~Colony() {
    // Se eliminan los insectos y los nodos hasta dejar vacia la lista.
    while (insects.getSize() > 0) {
        removeAt(1);
    }
}

void Colony::addAtBeginning(Insect* insect) {
    if (insect != nullptr) {
        insects.insertFront(insect);
    }
}

void Colony::addAtEnd(Insect* insect) {
    if (insect != nullptr) {
        insects.insertBack(insect);
    }
}

void Colony::showAll() const {
    if (insects.getSize() == 0) {
        cout << "La colonia esta vacia.\n";
        return;
    }

    // Todos los objetos se recorren como Insect*; virtual elige el metodo real.
    insects.traverse(showInsectDetails);
}

bool Colony::removeAt(int position) {
    Insect* const* item = insects.getAt(position - 1);
    if (item == nullptr) {
        return false;
    }

    // Se conserva el puntero antes de eliminar el nodo que lo guardaba.
    Insect* insect = *item;
    if (!insects.remove(insect)) {
        return false;
    }

    delete insect;
    return true;
}

int Colony::getCount() const {
    return insects.getSize();
}

int Colony::getTotalWeight() const {
    int total = 0;

    for (int i = 0; i < insects.getSize(); i++) {
        Insect* const* item = insects.getAt(i);
        total += (*item)->getWeight();
    }

    return total;
}

double Colony::getAverageWeight() const {
    if (insects.getSize() == 0) {
        return 0.0;
    }

    return static_cast<double>(getTotalWeight()) / insects.getSize();
}