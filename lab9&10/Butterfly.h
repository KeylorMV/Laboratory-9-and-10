#pragma once
#include "FlyingInsect.h"
class Butterfly : public FlyingInsect {
private:
	bool migratory;
public:
	Butterfly(std::string name, int  weight, int lifespandDays, std::string color, float wingSpan, bool migratory);
	void move() override;
	void makeSound()override;
	void describe()override;
};

