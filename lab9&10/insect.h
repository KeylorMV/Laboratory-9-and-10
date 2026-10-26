#pragma once

#include <string>

class Insect {
protected:
    std::string name;
    int weight;
    int lifespanDays;
    std::string color;

public:
    Insect(const std::string& name, int weight, int lifespanDays, const std::string& color);
    virtual ~Insect();

    virtual void move() const = 0;
    virtual void makeSound() const = 0;
    virtual void describe() const = 0;

    std::string getName() const;
    int getWeight() const;
    int getLifespanDays() const;
};
