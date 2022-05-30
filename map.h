#include <ncurses.h>
#include <clocale>
#include <iostream>
#include "stage.h"

WINDOW *window_map, *window_mission, *window_score;
int num_of_stage = 0;
void update_map();
void update_mission();
void update_score();
void del_win();