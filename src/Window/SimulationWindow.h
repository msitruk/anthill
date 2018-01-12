//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_MAPWINDOW_H
#define FOURMILIERE_MAPWINDOW_H

#include <ncurses.h>
#include <panel.h>
#include <vector>
#include "../Map/Tile.h"
#include "../Map/Map.h"

class SimulationWindow {

public:
    void run(int i, Map map);
};


#endif //FOURMILIERE_MAPWINDOW_H
