#pragma once
#include "FlyingInsect.h"
class Butterfly : public FlyingInsect {
private:
	bool migratory;
public:
    Butterfly(const std::string& name, int weight, int lifespanDays, const std::string& color, float wingSpan, bool migratory);

    void move() const override;
    void makeSound() const override;
    void describe() const override;
};

