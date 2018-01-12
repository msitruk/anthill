//
// Created by Maxime SITRUK on 04/01/2018.
//

#ifndef FOURMILIERE_ANTFACTORY_H
#define FOURMILIERE_ANTFACTORY_H

#include "AntQueen.h"
#include "AntWarrior.h"
#include "AntWorker.h"
#include <string>
#include "AbstractAnt.h"
using namespace std;

class AntFactory {
public:
    static AbstractAnt * create(int antType);
};


#endif //FOURMILIERE_ANTFACTORY_H
