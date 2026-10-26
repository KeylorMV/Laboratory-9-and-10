#pragma once
#include "Insect.h"
#include "List.h"

// Colony es la duena de todos los insectos almacenados en su lista.
class Colony {
private:
    List<Insect*> insects;

public:
    Colony();
    ~Colony();

    Colony(const Colony& other) = delete;
    Colony& operator=(const Colony& other) = delete;

    void addAtBeginning(Insect* insect);
    void addAtEnd(Insect* insect);
    void showAll() const;
    bool removeAt(int position);
    int getCount() const;
    int getTotalWeight() const;
    double getAverageWeight() const;
};

