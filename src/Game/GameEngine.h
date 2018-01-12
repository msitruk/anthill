//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_GAMEENGINE_H
#define FOURMILIERE_GAMEENGINE_H

#include <iostream>
#include <zconf.h>
#include <math.h>
#include "../Window/ChoiceWindow.h"
#include "../Window/SimulationWindow.h"
#include "../Ant/AntHill.h"
#include "../Map/Map.h"

using namespace std;

class GameEngine {

public:
    GameEngine();
    void run();
    vector<int> colonyToFeed;

private:
    int mapSize;
    int itemRatePop;
    int queenNumber;
    vector <AntHill> anthillArray;
    void simulate();
    Map initialPlacement(Map map, vector<AntHill> anthillArray);
    Map calculate(Map map, int i);

    void getRight(vector<Tile> *validDirectionsTiles, Map map, int i);

    void getLeft(vector<Tile> *validDirectionsTiles, Map map, int i);

    void getTop(vector<Tile> *validDirectionsTiles, Map map, int i);

    void getBottom(vector<Tile> *validDirectionsTiles, Map map, int i);

    vector<Tile> getValidDirectionsTiles(Map map, int i);

    void move(vector<Tile> validDirectionsTiles, int i, Map *map);

    void emptyTile(Tile *pTile);

    void warriorMove(vector<Tile> validDirectionsTiles, int i, Map *map);

    void workerMove(vector<Tile> validDirectionsTiles, int i, Map *map);

    vector<Tile> generateThreeNewAntAnyWhere(vector<Tile> mapArray, int colonyId);
};


#endif //FOURMILIERE_GAMEENGINE_H
