//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_ANTHILL_H
#define FOURMILIERE_ANTHILL_H


#include "AbstractAnt.h"
#include "AntFactory.h"
#include <iostream>
#include <vector>
using namespace std;

class AntHill {

public:
    AntHill();
    vector<AbstractAnt> anthillRegistry;
    void generateColony(int id);
    const vector<AbstractAnt> &getAnthillRegistry() const;
    void setAnthillRegistry(const vector<AbstractAnt> &anthillRegistry);
    int getId() const;
    void setId(int id);
    void addWorker();
    void addWarrior();
    AntFactory antFactory;
private:
    int id;
};


#endif //FOURMILIERE_ANTHILL_H
