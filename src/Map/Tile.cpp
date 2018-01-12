//
// Created by Maxime SITRUK on 03/01/2018.
//

#include "Tile.h"

int Tile::getColonyId() const {
    return colonyId;
}

void Tile::setColonyId(int colonyId) {
    Tile::colonyId = colonyId;
}

int Tile::getType() const {
    return type;
}

void Tile::setType(int type) {
    Tile::type = type;
}

AbstractAnt *Tile::getAnt() const {
    return ant;
}

void Tile::setAnt(AbstractAnt *ant) {
    Tile::ant = ant;
}

int Tile::getIndex() const {
    return index;
}

void Tile::setIndex(int index) {
    Tile::index = index;
}

//Tile::~Tile() {
//}

void Tile::destroyAnt() {
    delete ant;
}
