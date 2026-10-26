#pragma once
#include "Insect.h"

class FlyingInsect : public Insect {
protected:
	float wingSpan;

public:
	FlyingInsect(const std::string& name, int weight, int lifespanDays, const std::string& color, float wingSpan);

	void move() const override;
	void describe() const override;
};

