//
// Created by Maxime SITRUK on 02/01/2018.
//

#include "GameEngine.h"

GameEngine::GameEngine(){
}

void GameEngine::run(){
ChoiceWindow choiceWindow;
bool simulateOrNot = true;

    while (simulateOrNot){
    clear();
    simulateOrNot = choiceWindow.askForNewSimulationScreen();

        if(simulateOrNot){
        mapSize = choiceWindow.askMapSizeScreen();

            if(mapSize > 0){
            itemRatePop = choiceWindow.askItemPopRateScreen();

                if(itemRatePop > 0){
                    queenNumber = choiceWindow.askQueenNumberScreen(mapSize);

                    if (queenNumber > 0){
                        simulate();
                    }
                }
            }
        }
    }
}

void GameEngine::simulate() {

    //On initialise l'écran d'affichage de la simulation
    SimulationWindow simulationWindow;

    //On cree la map à la bonne taille
    Map map(mapSize);

    //On cree le nombre de colonie nécéssaire
    vector<AntHill> anthillArray(queenNumber);
    for (int i = 0; i < queenNumber; i++) {
        anthillArray[i].generateColony(i+1);
    }

    //On initialise un compteur de tour pour le repop de la nouriture
//    int loopCount = itemRatePop;
    int loopCount = 0;

    //On place les colonies sur la map
    map = initialPlacement(map, anthillArray);

    //Boucle de la simulation tant qu'il reste plus de deux Queen
//    while(getAliveQueenNumber(anthillArray) > 1){
    while(loopCount != 300){
        clear();

        //On place les item en fonction de itemRatePop
//        if (loopCount == itemRatePop){
//            map.addItemsOnMap();
//            loopCount = 0;
//        }


        //On affiche la map
        simulationWindow.run(loopCount, map);

        if(colonyToFeed.size() > 0){
            cout << "colonyToFeed IF" << endl;
            for (int i = 0; i < colonyToFeed.size(); i++) {
                cout << colonyToFeed[i] << endl;
                generateThreeNewAntAnyWhere(map.getMapArray(), colonyToFeed[i]);
            }
            colonyToFeed.clear();
        }

        // Calcul déplacements
        map = calculate(map, loopCount);

        //On ajoute 1 à loopCount pour gérer itemRatePop
        loopCount++;
//        usleep(100000);
    }
}

Map GameEngine::initialPlacement(Map map, vector<AntHill> anthillArray) {
    vector<Tile> mapArray = map.getMapArray();
    for (int i = 0; i < queenNumber; i++){
//        switch (mapSize){
//            case 1:
                //ants
                if (i == 0){
                    mapArray[72].setType(anthillArray[i].anthillRegistry[0].getType());
                    mapArray[72].setColonyId(anthillArray[i].getId());
                    mapArray[72].setAnt(&anthillArray[i].anthillRegistry[0]);

                    mapArray[73].setType(anthillArray[i].anthillRegistry[1].getType());
                    mapArray[73].setColonyId(anthillArray[i].getId());
                    mapArray[73].setAnt(&anthillArray[i].anthillRegistry[1]);

                    mapArray[49].setType(anthillArray[i].anthillRegistry[2].getType());
                    mapArray[49].setColonyId(anthillArray[i].getId());
                    mapArray[49].setAnt(&anthillArray[i].anthillRegistry[2]);

                    mapArray[95].setType(anthillArray[i].anthillRegistry[3].getType());
                    mapArray[95].setColonyId(anthillArray[i].getId());
                    mapArray[95].setAnt(&anthillArray[i].anthillRegistry[3]);
                }
                else if (i == 1){
                    mapArray[88].setType(anthillArray[i].anthillRegistry[0].getType());
                    mapArray[88].setColonyId(anthillArray[i].getId());
                    mapArray[88].setAnt(&anthillArray[i].anthillRegistry[0]);

                    mapArray[87].setType(anthillArray[i].anthillRegistry[1].getType());
                    mapArray[87].setColonyId(anthillArray[i].getId());
                    mapArray[87].setAnt(&anthillArray[i].anthillRegistry[1]);

                    mapArray[65].setType(anthillArray[i].anthillRegistry[2].getType());
                    mapArray[65].setColonyId(anthillArray[i].getId());
                    mapArray[65].setAnt(&anthillArray[i].anthillRegistry[2]);

                    mapArray[111].setType(anthillArray[i].anthillRegistry[3].getType());
                    mapArray[111].setColonyId(anthillArray[i].getId());
                    mapArray[111].setAnt(&anthillArray[i].anthillRegistry[3]);
                }
                else if (i == 2){
                    mapArray[210].setType(anthillArray[i].anthillRegistry[0].getType());
                    mapArray[210].setColonyId(anthillArray[i].getId());
                    mapArray[210].setAnt(&anthillArray[i].anthillRegistry[0]);

                    mapArray[211].setType(anthillArray[i].anthillRegistry[1].getType());
                    mapArray[211].setColonyId(anthillArray[i].getId());
                    mapArray[211].setAnt(&anthillArray[i].anthillRegistry[1]);

                    mapArray[187].setType(anthillArray[i].anthillRegistry[2].getType());
                    mapArray[187].setColonyId(anthillArray[i].getId());
                    mapArray[187].setAnt(&anthillArray[i].anthillRegistry[2]);

                    mapArray[233].setType(anthillArray[i].anthillRegistry[3].getType());
                    mapArray[233].setColonyId(anthillArray[i].getId());
                    mapArray[233].setAnt(&anthillArray[i].anthillRegistry[3]);

                }
                //items
                mapArray[57].setType(4);
                mapArray[103].setType(5);
//                mapArray[0].setType(5);
//                mapArray[5].setType(5);
//                mapArray[10].setType(5);
//                mapArray[15].setType(5);
//                mapArray[25].setType(5);
//            break;
//            case 2:{
//
//            }
//        }
    }

    map.setMapArray(mapArray);
    mapArray.clear();
    mapArray.shrink_to_fit();

    return map;
}

Map GameEngine::calculate(Map map, int loopcount) {
    vector<Tile> mapArray = map.getMapArray();

    for (int i = 0; i < mapArray.size(); i++){
        if (mapArray[i].getType() > 1 && mapArray[i].getType() < 4){
            //Get valid direction
//            cout << i << endl;
            vector<Tile> validDirectionsTiles = getValidDirectionsTiles(map, i);
//            for (int j = 0; j < validDirectionsTiles.size(); ++j) {
//                cout << validDirectionsTiles[j].getType() << endl;
//            }
            move(validDirectionsTiles, i, &map);
        }
    }
    mapArray.clear();
    mapArray.shrink_to_fit();
    return map;
}

vector<Tile> GameEngine::getValidDirectionsTiles(Map map, int i) {
    vector<Tile> validDirectionsTiles;
    getRight(&validDirectionsTiles, map, i);
    getLeft(&validDirectionsTiles, map, i);
    getTop(&validDirectionsTiles, map, i);
    getBottom(&validDirectionsTiles, map, i);
    return validDirectionsTiles;
}

void GameEngine::getRight(vector<Tile> *validDirectionsTiles, Map map, int i) {
    vector<Tile> mapArray = map.getMapArray();
    if (i+1 > map.getMapArray().size()){
        return;
    }
    else if (floor((i/map.getWidth())+1) != floor(((i+1)/map.getWidth())+1)){
        return;
    }
    validDirectionsTiles->push_back(mapArray[i+1]);
    mapArray.clear();
    mapArray.shrink_to_fit();
}

void GameEngine::getLeft(vector<Tile> *validDirectionsTiles, Map map, int i) {
    vector<Tile> mapArray = map.getMapArray();
    if (i-1 < 0){
        return;
    }
    else if (floor((i/map.getWidth())+1) != floor(((i-1)/map.getWidth())+1)){
        return;
    }
    validDirectionsTiles->push_back(mapArray[i-1]);
    mapArray.clear();
    mapArray.shrink_to_fit();
}

void GameEngine::getTop(vector<Tile> *validDirectionsTiles, Map map, int i) {
    vector<Tile> mapArray = map.getMapArray();
    if(i < map.getWidth()){
        return;
    }
    validDirectionsTiles->push_back(mapArray[i-map.getWidth()]);
    mapArray.clear();
    mapArray.shrink_to_fit();
}

void GameEngine::getBottom(vector<Tile> *validDirectionsTiles, Map map, int i) {
    vector<Tile> mapArray = map.getMapArray();
    if(floor((i/map.getWidth())+1) == map.getHeight()){
        return;
    }
    validDirectionsTiles->push_back(mapArray[i+map.getWidth()]);
    mapArray.clear();
    mapArray.shrink_to_fit();
}

void GameEngine::move(vector<Tile> validDirectionsTiles, int i, Map *map) {
    if (validDirectionsTiles.size() == 0){
        return;
    }
    else{
        vector<Tile> mapArray = map->getMapArray();
//        random_shuffle(validDirectionsTiles.begin(),validDirectionsTiles.end());
//        for (int j = 0; j < validDirectionsTiles.size(); j++){
//            if (validDirectionsTiles[j].getType() == 0){
//                mapArray[validDirectionsTiles[j].getIndex()].setType(mapArray[i].getType());
//                mapArray[validDirectionsTiles[j].getIndex()].setAnt(mapArray[i].getAnt());
//                mapArray[validDirectionsTiles[j].getIndex()].setColonyId(mapArray[i].getColonyId());
//                emptyTile(&mapArray[i]);
//                map->setMapArray(mapArray);
//                return;
//            }
//        }
//        cout << "move" << endl;
        if (mapArray[i].getType() == 2){
//            cout << "move2" << endl;
            warriorMove(validDirectionsTiles, i, map);
//            map->setMapArray(mapArray);
        }
        else if (mapArray[i].getType() == 3){
//            cout << "move3" << endl;
            workerMove(validDirectionsTiles, i, map);
//            map->setMapArray(mapArray);
        }
        mapArray.clear();
        mapArray.shrink_to_fit();
    }
}

void GameEngine::emptyTile(Tile *pTile) {
    pTile->setColonyId(-1);
    pTile->setAnt(nullptr);
    pTile->setType(0);
    pTile->destroyAnt();
}

void GameEngine::warriorMove(vector<Tile> validDirectionsTiles, int i, Map *map) {
//    cout << "warriorMove" << endl;
    vector<Tile> mapArray = map->getMapArray();
    random_shuffle(validDirectionsTiles.begin(),validDirectionsTiles.end());
    for (int j = 0; j < validDirectionsTiles.size(); j++){
        if (validDirectionsTiles[j].getType() == 0){
            mapArray[validDirectionsTiles[j].getIndex()].setType(mapArray[i].getType());
            mapArray[validDirectionsTiles[j].getIndex()].setAnt(mapArray[i].getAnt());
            mapArray[validDirectionsTiles[j].getIndex()].setColonyId(mapArray[i].getColonyId());
            emptyTile(&mapArray[i]);
            map->setMapArray(mapArray);
            mapArray.clear();
            mapArray.shrink_to_fit();
            return;
        }
    }
}

void GameEngine::workerMove(vector<Tile> validDirectionsTiles, int i, Map *map) {
//    cout << "workerMove" << endl;
    vector<Tile> mapArray = map->getMapArray();
    random_shuffle(validDirectionsTiles.begin(),validDirectionsTiles.end());
    int foodFoundIndex = -1;
    for (int j = 0; j < validDirectionsTiles.size(); j++){
        if(validDirectionsTiles[j].getType() > 3){
            foodFoundIndex = j;
        }
    }

    if (foodFoundIndex > -1){
        mapArray[validDirectionsTiles[foodFoundIndex].getIndex()].setType(mapArray[i].getType());
        mapArray[validDirectionsTiles[foodFoundIndex].getIndex()].setAnt(mapArray[i].getAnt());
        mapArray[validDirectionsTiles[foodFoundIndex].getIndex()].setColonyId(mapArray[i].getColonyId());

//        mapArray = generateThreeNewAntAnyWhere(mapArray, mapArray[i].getColonyId());
        colonyToFeed.push_back(mapArray[i].getColonyId()+1);
        emptyTile(&mapArray[i]);
        map->setMapArray(mapArray);
        mapArray.clear();
        mapArray.shrink_to_fit();
        return;
    }
    else{
        for (int j = 0; j < validDirectionsTiles.size(); j++){
            if (validDirectionsTiles[j].getType() == 0){
                mapArray[validDirectionsTiles[j].getIndex()].setType(mapArray[i].getType());
                mapArray[validDirectionsTiles[j].getIndex()].setAnt(mapArray[i].getAnt());
                mapArray[validDirectionsTiles[j].getIndex()].setColonyId(mapArray[i].getColonyId());
                emptyTile(&mapArray[i]);
                map->setMapArray(mapArray);
                mapArray.clear();
                mapArray.shrink_to_fit();
                return;
            }
        }
    }
}

vector<Tile> GameEngine::generateThreeNewAntAnyWhere(vector<Tile> mapArray, int colonyId) {
    vector<Tile> mapArrayCopy = mapArray;
//    colonyId = 1;
    int generatedAntNumber = 0;
    random_shuffle(mapArrayCopy.begin(), mapArrayCopy.end());
    for (int i = 0; i < mapArrayCopy.size() && generatedAntNumber < 3; i++) {
        if(mapArrayCopy[i].getType() == 0){
            if(i % 2 == 0){
                cout << "generateThreeNewAntAnyWhere IF" << endl;
                cout << mapArrayCopy[i].getIndex() << endl;
                mapArray[mapArrayCopy[i].getIndex()].setType(3);
                cout << "generateThreeNewAntAnyWhere IF 1" << endl;
                mapArray[mapArrayCopy[i].getIndex()].setColonyId(colonyId);
                cout << "generateThreeNewAntAnyWhere IF 2" << endl;
                cout << colonyId << endl;
                anthillArray[colonyId].addWorker();
                cout << "generateThreeNewAntAnyWhere IF 3" << endl;
                cout << anthillArray[colonyId].anthillRegistry.size() << endl;
                int anthillRegistryIndexForNewAnt = anthillArray[colonyId].anthillRegistry.size();
                cout << "generateThreeNewAntAnyWhere IF 4" << endl;
                mapArray[mapArrayCopy[i].getIndex()].setAnt(&anthillArray[colonyId].anthillRegistry[anthillRegistryIndexForNewAnt]);
                cout << "generateThreeNewAntAnyWhere IF 5" << endl;
                generatedAntNumber++;
            }
            else {
                cout << "generateThreeNewAntAnyWhere ELSE" << endl;
                mapArray[mapArrayCopy[i].getIndex()].setType(2);
                cout << "generateThreeNewAntAnyWhere ELSE 1" << endl;
                mapArray[mapArrayCopy[i].getIndex()].setColonyId(colonyId);
                cout << "generateThreeNewAntAnyWhere ELSE 2" << endl;
//                anthillArray[colonyId].addWarrior();
                cout << "generateThreeNewAntAnyWhere ELSE 3" << endl;
                cout << anthillArray[colonyId].anthillRegistry.size() << endl;
                int anthillRegistryIndexForNewAnt = anthillArray[colonyId].anthillRegistry.size();
                cout << "generateThreeNewAntAnyWhere ELSE 4" << endl;
                mapArray[mapArrayCopy[i].getIndex()].setAnt(&anthillArray[colonyId].anthillRegistry[anthillRegistryIndexForNewAnt]);
                cout << "generateThreeNewAntAnyWhere ELSE 5" << endl;
                generatedAntNumber++;
            }
            mapArrayCopy[i].setType(99);
//            random_shuffle(mapArrayCopy.begin(), mapArrayCopy.end());
        }
    }
    mapArray.clear();
    mapArray.shrink_to_fit();
    return mapArray;
}

