#pragma once
#include "Insect.h"

class FlyingInsect : public Insect {
protected:
	float wingSpan;

public:
	FlyingInsect(std::string name, int weight, int lifespandDayas, std::string color, float wingSpan);
	void move() override;

	void describe()override;
};

