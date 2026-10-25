#include "Butterfly.h"
using namespace std;
Butterfly::Butterfly(string name, int weight, int lifespanDays, string color, float wingSpan, bool migratory) : FlyingInsect(name, weight, lifespanDays, color, wingSpan) {
	this->migratory = migratory;
}

void Butterfly::move()
{
	cout << "flying";
}

void Butterfly::makeSound()
{
	cout << "  ";
}
void Butterfly::describe() {
	cout << "\nInsecto volador" << "\n";
	cout << "Nombre:" << name << "\n";
	cout << "Peso: " << weight << "\n";
	cout << "Dias de vida: " << lifespandDays << "\n";
	cout << "Color: " << color << "\n";
	cout << "Envergadura de las alas: " << wingSpan<<"\n";
	cout << "Migra: Si\n";


