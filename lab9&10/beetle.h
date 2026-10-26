#pragma once
#include "Insect.h"

// Clase concreta: la dureza del caparazon distingue al escarabajo.
class Beetle : public Insect {
private:
    int shellHardness;

public:
    Beetle(const std::string& name, int weight, int lifespanDays, const std::string& color, int shellHardness);

    void move() const override;
    void makeSound() const override;
    void describe() const override;
};

