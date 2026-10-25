#include "FlyingInsect.h"

using namespace std;


FlyingInsect::FlyingInsect(std::string name, int weight, int lifespanDays,string color, float wingSpan) : Insect (name, weight, lifespanDays, color) {};

void FlyingInsect::move()
{
	cout << "vuela\n";
}

