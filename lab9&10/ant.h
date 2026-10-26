#pragma once
#include "Insect.h"

class Ant : public Insect {
private:
    int carryCapacity;

public:
    Ant(const std::string& name, int weight, int lifespanDays, const std::string& color, int carryCapacity);

    void move() const override;
    void makeSound() const override;
    void describe() const override;
};

