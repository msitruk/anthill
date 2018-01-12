//
// Created by Maxime SITRUK on 02/01/2018.
//

#ifndef FOURMILIERE_CHOICEWINDOW_H
#define FOURMILIERE_CHOICEWINDOW_H


#include <curses.h>
#include <menu.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

class ChoiceWindow {

public:
    bool askForNewSimulationScreen();
    int askMapSizeScreen();
    int askItemPopRateScreen();
    int askQueenNumberScreen(int mapSize);
private:
    void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
    int getUserChoice(vector<string>, char *msg);
};


#endif //FOURMILIERE_CHOICEWINDOW_H
