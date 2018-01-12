//
// Created by Maxime SITRUK on 02/01/2018.
//

#include "AbstractAnt.h"

int AbstractAnt::getType() const {
    return type;
}

void AbstractAnt::setType(int type) {
    AbstractAnt::type = type;
}
