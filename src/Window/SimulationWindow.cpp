//
// Created by Maxime SITRUK on 02/01/2018.
//

#include <zconf.h>
#include <vector>
#include "SimulationWindow.h"

void SimulationWindow::run(int loopCount, Map map) {

    WINDOW *my_wins[map.getMapArray().size()];
    PANEL  *my_panels[map.getMapArray().size()];
    vector<Tile> mapArray = map.getMapArray();
    int lines = 3, cols = 6, y = 0, x = 0, i, color;
    string buffer;

    initscr();

    start_color();
//    init_pair(1, COLOR_GREEN, COLOR_RED);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
//    COLOR_BLACK   0

//    COLOR_RED     1
//    COLOR_GREEN   2
//    COLOR_YELLOW  3
//    COLOR_BLUE    4
//    COLOR_MAGENTA 5
//    COLOR_CYAN    6

//    COLOR_WHITE   7 ITEMS


    cbreak();
    noecho();



    for (i = 0; i < map.getMapArray().size(); i++){
        my_wins[i] = newwin(lines, cols, y, x);

        switch (mapArray[i].getType()){
            case 0:{
                buffer = "  ";
                break;
            }
            case 1:{
                buffer = " Qu";
                break;
            }
            case 2:{
                buffer = " Wa";
                break;
            }
            case 3:{
                buffer = " Tr";
                break;
            }
            case 4:{
                buffer = " If";
                break;
            }
            case 5:{
                buffer = " Iw";
                break;
            }
        }

        if (mapArray[i].getType() == 1 || mapArray[i].getType() == 2 || mapArray[i].getType() == 3){
            color = mapArray[i].getColonyId();
        }
        else if (mapArray[i].getType() == 4){
            color = 4;
        }
        else if (mapArray[i].getType() == 5){
            color = 5;
        }
        else {
            color = 7;
        }

        wattron(my_wins[i], COLOR_PAIR(color));
//        printf("debug : %d \n", mapArray[i].getColonyId());
        mvwprintw(my_wins[i], 1, 1, buffer.c_str());
        wattroff(my_wins[i], COLOR_PAIR(color));


        box(my_wins[i], 0, 0);
        my_panels[i] = new_panel(my_wins[i]);

        x = x + 6;

        if(x == map.getWidth()*6){
            x = 0;
            y = y + 3;
        }

    }

    /* Update the stacking order. 2nd panel will be on top */
    update_panels();

    /* Show it on the screen */
    doupdate();




    mapArray.clear();
    mapArray.shrink_to_fit();


//    getch();
    endwin();
    refresh();
    for (int j = 0; j < map.getMapArray().size(); j++) {
        del_panel(my_panels[j]);
    }
}
