#pragma once
#include "FlyingInsect.h"
class Butterfly : public FlyingInsect {
private:
	bool migratory;
public:
	Butterfly(std::string name, int  weight, int lifespandDays,std::string color, std::string wingSpan);
	void move() override;
	void makeSound()override;
	void describe()override;
};

