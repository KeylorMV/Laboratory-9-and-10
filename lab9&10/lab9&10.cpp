#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

#include "colony.h"
#include "ant.h"
#include "beetle.h"
#include "Butterfly.h"

using namespace std;

int readInt(const string& message, int minimum, int maximum) {
    string text;

    while (true) {
        cout << message;

        if (!getline(cin, text)) {
            throw runtime_error("Entrada finalizada.");
        }

        try {
            size_t processed;
            int value = stoi(text, &processed);

            if (processed != text.size()) {
                throw invalid_argument("Ingrese solo un numero entero.");
            }

            if (value < minimum || value > maximum) {
                throw out_of_range("Numero fuera del rango permitido.");
            }

            return value;
        }
        catch (const exception& error) {
            cout << "Entrada invalida: " << error.what() << "\n";
            cout << "Rango permitido: "
                << minimum << " a " << maximum << ".\n";
        }
    }
}

string readText(const string& message) {
    string text;

    while (true) {
        cout << message;

        if (!getline(cin, text)) {
            throw runtime_error("Entrada finalizada.");
        }

        if (text.find_first_not_of(" \t\r") != string::npos) {
            return text;
        }

        cout << "El texto no puede estar vacio.\n";
    }
}

float readWingSpan() {
    string text;

    while (true) {
        cout << "Envergadura de las alas (cm): ";

        if (!getline(cin, text)) {
            throw runtime_error("Entrada finalizada.");
        }

        try {
            size_t processed;
            float value = stof(text, &processed);

            if (processed != text.size() ||
                !(value > 0 && value <= numeric_limits<float>::max())) {
                throw invalid_argument("Ingrese un numero positivo finito.");
            }

            return value;
        }
        catch (const exception&) {
            cout << "Valor invalido. Use punto para los decimales.\n";
        }
    }
}

Insect* createInsect() {
    cout << "\n1. Hormiga\n";
    cout << "2. Escarabajo\n";
    cout << "3. Mariposa\n";

    int type = readInt("Tipo: ", 1, 3);

    string name = readText("Nombre: ");
    int weight = readInt("Peso (mg): ", 1, 1000000);
    int lifespan = readInt("Vida estimada (dias): ", 1, 1000000);
    string color = readText("Color: ");

    if (type == 1) {
        int capacity = readInt(
            "Capacidad de carga (mg): ", 1, 1000000
        );

        return new Ant(name, weight, lifespan, color, capacity);
    }

    if (type == 2) {
        int hardness = readInt(
            "Dureza del caparazon (1-10): ", 1, 10
        );

        return new Beetle(name, weight, lifespan, color, hardness);
    }

    float wingSpan = readWingSpan();

    bool migratory = readInt(
        "Es migratoria? (1 = Si, 0 = No): ", 0, 1
    ) == 1;

    return new Butterfly(
        name, weight, lifespan, color, wingSpan, migratory
    );
}

void addInsect(Colony& colony, bool atBeginning) {
    Insect* insect = createInsect();

    try {
        if (atBeginning) {
            colony.addAtBeginning(insect);
        }
        else {
            colony.addAtEnd(insect);
        }
    }
    catch (...) {
        
        delete insect;
        throw;
    }

    cout << "Insecto agregado.\n";
}

int main() {
    Colony colony;
    int option = -1;

    do {
        cout << "\n===== COLONIA DE INSECTOS =====\n";
        cout << "1. Agregar al principio\n";
        cout << "2. Agregar al final\n";
        cout << "3. Mostrar todos\n";
        cout << "4. Eliminar por posicion\n";
        cout << "5. Mostrar cantidad\n";
        cout << "6. Mostrar peso total\n";
        cout << "7. Mostrar peso promedio\n";
        cout << "0. Salir\n";

        try {
            option = readInt("Opcion: ", 0, 7);

            switch (option) {
            case 1:
                addInsect(colony, true);
                break;

            case 2:
                addInsect(colony, false);
                break;

            case 3:
                colony.showAll();
                break;

            case 4: {
                if (colony.getCount() == 0) {
                    cout << "La colonia esta vacia.\n";
                    break;
                }

                colony.showAll();

                int position = readInt(
                    "Posicion a eliminar: ", 1, colony.getCount()
                );

                if (colony.removeAt(position)) {
                    cout << "Insecto eliminado.\n";
                }
                else {
                    cout << "No se pudo eliminar.\n";
                }

                break;
            }

            case 5:
                cout << "Cantidad: " << colony.getCount() << "\n";
                break;

            case 6:
                cout << "Peso total: "
                    << colony.getTotalWeight() << " mg\n";
                break;

            case 7:
                cout << "Peso promedio: "
                    << colony.getAverageWeight() << " mg\n";
                break;

            case 0:
                cout << "Programa finalizado.\n";
                break;
            }
        }
        catch (const exception& error) {
            cout << "Error: " << error.what() << "\n";

            if (!cin) {
                return 1;
            }
        }
    } while (option != 0);

    return 0;
}