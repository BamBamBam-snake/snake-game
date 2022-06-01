#pragma once
#include "item.h"
#include "stage.h"
#include "gate.h"
#include <ncurses.h>
#include <clocale>
#include <locale.h>
using namespace std;

class Map {
    private:
        WINDOW *window_map, *window_mission, *window_score;
        int current_size;
        int goal_size;
    public:
        void init_window();
        Stage update_map(Stage s);
        void update_mission();
        void update_score();
        void del_win();
        void play();
};