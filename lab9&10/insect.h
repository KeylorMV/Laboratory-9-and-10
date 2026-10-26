#pragma once

#include <string>

// Clase base abstracta: representa las caracteristicas comunes de los insectos.
class Insect {
protected:
    std::string name;
    int weight;
    int lifespanDays;
    std::string color;

public:
    Insect(const std::string& name, int weight, int lifespanDays, const std::string& color);
    virtual ~Insect();

    // Cada insecto concreto debe definir su propio comportamiento.
    virtual void move() const = 0;
    virtual void makeSound() const = 0;
    virtual void describe() const = 0;

    std::string getName() const;
    int getWeight() const;
    int getLifespanDays() const;
};
