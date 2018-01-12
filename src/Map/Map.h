//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_MAP_H
#define FOURMILIERE_MAP_H

#include <iostream>
#include <vector> //Ne pas oublier !
#include "Tile.h"

using namespace std;

class Map {
public:
    const vector<Tile> &getMapArray() const;
    void setMapArray(const vector<Tile> &mapArray);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    Map(int mapSize);

private:
    int width;
    int height;
    vector<Tile> mapArray;
};


#endif //FOURMILIERE_MAP_H
