#include "Colony.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Colony::Colony() {}

Colony::~Colony() {
    const Node<Insect*>* current = insects.getHead();

    while (current != nullptr) {
        delete current->getData();
        current = current->getNext();
    }

    insects.clear();
}

void Colony::addAtBeginning(Insect* insect) {
    if (insect == nullptr) {
        throw invalid_argument("Insect cannot be null.");
    }

    const Node<Insect*>* current = insects.getHead();

    while (current != nullptr) {
        if (current->getData() == insect) {
            throw invalid_argument(
                "Insect is already in the colony."
            );
        }

        current = current->getNext();
    }

    insects.insertFirst(insect);
}

void Colony::addAtEnd(Insect* insect) {
    if (insect == nullptr) {
        throw invalid_argument("Insect cannot be null.");
    }

    const Node<Insect*>* current = insects.getHead();

    while (current != nullptr) {
        if (current->getData() == insect) {
            throw invalid_argument(
                "Insect is already in the colony."
            );
        }

        current = current->getNext();
    }

    insects.insertLast(insect);
}

void Colony::showAll() const {
    if (insects.isEmpty()) {
        cout << "La colonia esta vacia.\n";
        return;
    }

    const Node<Insect*>* current = insects.getHead();
    int position = 1;

    while (current != nullptr) {
        Insect* insect = current->getData();

        cout << "\nInsecto #" << position << "\n";
        insect->describe();
        insect->move();
        insect->makeSound();
        cout << "--------------------\n";

        current = current->getNext();
        ++position;
    }
}

bool Colony::removeAt(int position) {
    if (position < 1 || position > insects.size()) {
        return false;
    }

    const Node<Insect*>* current = insects.getHead();
    int currentPosition = 1;

    while (currentPosition < position) {
        current = current->getNext();
        ++currentPosition;
    }

    Insect* insect = current->getData();

    if (insects.remove(insect)) {
        delete insect;
        return true;
    }

    return false;
}

int Colony::getCount() const {
    return insects.size();
}

int Colony::getTotalWeight() const {
    int total = 0;
    const Node<Insect*>* current = insects.getHead();

    while (current != nullptr) {
        total += current->getData()->getWeight();
        current = current->getNext();
    }

    return total;
}

double Colony::getAverageWeight() const {
    if (insects.isEmpty()) {
        return 0.0;
    }

    return static_cast<double>(getTotalWeight()) / getCount();
}