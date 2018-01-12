//
// Created by Maxime SITRUK on 03/01/2018.
//

#ifndef FOURMILIERE_TILEMAP_H
#define FOURMILIERE_TILEMAP_H


#include "../Ant/AbstractAnt.h"

class Tile {
public:
    int getColonyId() const;
    void setColonyId(int colonyId);
    int getType() const;
    void setType(int type);
    AbstractAnt *getAnt() const;
    void setAnt(AbstractAnt *ant);
    int getIndex() const;
    void setIndex(int index);

    void destroyAnt();

private:
public:
//    virtual ~Tile();

private:
    AbstractAnt *ant;
    int colonyId;
    int type;
    int index;
};



#endif //FOURMILIERE_TILEMAP_H
