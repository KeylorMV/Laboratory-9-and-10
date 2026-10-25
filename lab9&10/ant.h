#pragma once
#include "Insect.h"

// Clase concreta: la capacidad de carga es propia de la hormiga.
class Ant : public Insect {
private:
    int carryCapacity;

public:
    Ant(const std::string& name, int weight, int lifespanDays, const std::string& color, int carryCapacity);

    void move() const override;
    void makeSound() const override;
    void describe() const override;
};

