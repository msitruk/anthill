//
// Created by Maxime SITRUK on 04/01/2018.
//

#include "AntFactory.h"


AbstractAnt * AntFactory::create(int antType) {
    AbstractAnt *ant = NULL;

    switch(antType){
        case 1:{
            ant = new AntQueen;
            break;
        }
        case 2:{
            ant = new AntWarrior;
            break;
        }
        case 3:{
            ant = new AntWorker;
            break;
        }
        default:{
            return NULL;
        }
    }
    ant->setType(antType);
    return ant;
}
