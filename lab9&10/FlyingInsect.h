#pragma once
#include "Insect.h"

class FlyingInsect : public Insect {
protected:
	std::string wingSpan;

public:
	FlyingInsect(std::string name, int weight, int lifespandDayas, std::string color, std::string wingSpan);
	void move() override;

	void describe()override;
};

