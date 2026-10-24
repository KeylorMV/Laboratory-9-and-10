#include "insect.h"
using namespace std;

Insect::Insect(string name, int weight, int lifespandDays, string color)
{
	this->name = name;
	this->weight = weight;
	this->lifespandDays = lifespandDays;
	this->color = color;
}

Insect::~Insect()
{
	std::cout << "Destroid\n";
}
