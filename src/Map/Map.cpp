//
// Created by Maxime SITRUK on 02/01/2018.
//

#include "Map.h"

Map::Map(int mapSize) {
    if (mapSize == 1){
        width = 23;
        height = 7;

        for (int i = 0; i < (width*height);i++){
            Tile tile;
            tile.setType(0);
            tile.setIndex(i);
            mapArray.push_back(tile);
        }
    }
    else if (mapSize == 2){
        width = 23;
        height = 14;

        for (int i = 0; i < (width*height);i++){
            Tile tile;
            tile.setType(0);
            mapArray.push_back(tile);
        }
    }
}

const vector<Tile> &Map::getMapArray() const {
    return mapArray;
}

void Map::setMapArray(const vector<Tile> &mapArray) {
    Map::mapArray = mapArray;
}

int Map::getWidth() const {
    return width;
}

void Map::setWidth(int width) {
    Map::width = width;
}

int Map::getHeight() const {
    return height;
}

void Map::setHeight(int height) {
    Map::height = height;
}

