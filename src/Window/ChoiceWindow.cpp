//
// Created by Maxime SITRUK on 02/01/2018.
//

#include <panel.h>
#include "ChoiceWindow.h"

bool ChoiceWindow::askForNewSimulationScreen() {
    vector<string> choices;
    choices.push_back("Simulate");
    choices.push_back("Exit");

    return getUserChoice(choices, "Welcome");
}

int ChoiceWindow::askMapSizeScreen() {
    vector<string> choices;
    choices.push_back("Small");
    choices.push_back("Medium");
    choices.push_back("Big");
    choices.push_back("Back");

    return getUserChoice(choices, "Map size ?");
}

int ChoiceWindow::askItemPopRateScreen() {
    vector<string> choices;
    choices.push_back("Fast");
    choices.push_back("Normal");
    choices.push_back("Slow");
    choices.push_back("Back");

    return getUserChoice(choices, "Item repop time ?");
}

int ChoiceWindow::askQueenNumberScreen(int mapSize) {
    int userChoice;
    vector<string> choices;
    if (mapSize == 1){
        return 2;
    }
    else if (mapSize == 2){
        vector<string> choices;
        choices.push_back("3");
        choices.push_back("4");
        choices.push_back("Back");
        userChoice = getUserChoice(choices, "Queen number ?");
        if (userChoice == 1)
            return 3;
        else if (userChoice == 2)
            return 4;
        else if (userChoice == 0)
            return 0;
    }
    else if (mapSize == 3){
        vector<string> choices;
        choices.push_back("5");
        choices.push_back("6");
        choices.push_back("7");
        choices.push_back("8");
        choices.push_back("9");
        choices.push_back("Back");
        userChoice = getUserChoice(choices, "Queen number ?");
        if (userChoice == 1)
            return 5;
        else if (userChoice == 2)
            return 6;
        else if (userChoice == 3)
            return 7;
        else if (userChoice == 4)
            return 8;
        else if (userChoice == 5)
            return 9;
        else if (userChoice == 0)
            return 0;
    }
    return 0;
}

int ChoiceWindow::getUserChoice(vector<std::string> choicesAsStringVector, char *msg) {

    ITEM **my_items;
    int c;
    MENU *my_menu;
    WINDOW *my_menu_win;
    int n_choices, i, j;
    int userChoice = -1;

    const char *choices[choicesAsStringVector.size()+1];

    for (j = 0; j < choicesAsStringVector.size(); j++){
        choices[j] = choicesAsStringVector[j].c_str();
    }

    /* Initialize curses */
    clear();
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);

    /* Create items */
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
    for(i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], "");

    /* Crate menu */
    my_menu = new_menu((ITEM **)my_items);

    /* Create the window to be associated with the menu */
    my_menu_win = newwin(10, 40, (LINES/2)-5, (COLS/2)-20);
    keypad(my_menu_win, TRUE);

    /* Set main window and sub window */
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

    /* Set menu mark to the string " * " */
    set_menu_mark(my_menu, " * ");

    /* Set fore ground and back ground of the menu */
    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    set_menu_back(my_menu, COLOR_PAIR(2));
    set_menu_grey(my_menu, COLOR_PAIR(3));

    /* Print a border around the main window and print a title */
    box(my_menu_win, 0, 0);
    print_in_middle(my_menu_win, 1, 0, 40, msg, COLOR_PAIR(1));
    mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
    mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
    mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

    refresh();

    /* Post the menu */
    post_menu(my_menu);
    wrefresh(my_menu_win);

    while(userChoice < 0)
    {
        c = getch();
        switch(c)
        {	case KEY_DOWN:
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
            case 10: /* Enter */
                move(LINES - 3, 0);
                clrtoeol();
//                mvprintw(LINES - 3, 0, "Item selected is : %s",
//                         item_name(current_item(my_menu)));
                pos_menu_cursor(my_menu);

                if (strcmp(item_name(current_item(my_menu)), "Exit") == 0){
                    userChoice = 0;
                }
                else if (strcmp(item_name(current_item(my_menu)), "Back") == 0){
                    userChoice = 0;
                }
                else {
                    for(i = 0; i < n_choices; i++)
                        if (strcmp(item_name(current_item(my_menu)), choices[i]) == 0)
                            userChoice = i+1;
                }
                break;

        }
        wrefresh(my_menu_win);
    }

    /* Unpost and free all the memory taken up */
    unpost_menu(my_menu);
    free_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    endwin();
    printf("Choice : %d\n", userChoice);
    return userChoice;
}

void ChoiceWindow::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}