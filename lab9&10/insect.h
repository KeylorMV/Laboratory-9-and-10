#pragma once
#include <iostream>
#include<string>
class Insect
{
protected:
	std::string name;
	int weight;
	int lifespandDays;
	std::string color;
public:
	Insect(std::string name, int weight, int lifespandDays, std::string color);
	virtual void move() = 0;
	virtual void makeSound() = 0;
	virtual void describe() = 0;
	virtual ~Insect();
};

