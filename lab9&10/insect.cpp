#include "Insect.h"
#include <iostream>

using namespace std;

Insect::Insect(const string& name, int weight, int lifespanDays, const string& color)
    : name(name), weight(weight), lifespanDays(lifespanDays), color(color) {
}

Insect::~Insect() {
    cout << "Liberando insecto: " << name << "\n";
}

string Insect::getName() const {
    return name;
}

int Insect::getWeight() const {
    return weight;
}

int Insect::getLifespanDays() const {
    return lifespanDays;
}
