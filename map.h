#pragma once
#include "item.h"
#include "stage.h"
#include "gate.h"
#include "snake.h"
#include <ncurses.h>
#include <clocale>
#include <locale.h>
using namespace std;

class Map {
    friend class Mission;
    private:
        WINDOW *window_map, *window_mission, *window_score, *window_gameover, *window_gameclear, *window_stageclear;
    public:
        int current_size;
        int goal_size;
        void init_window();
        Stage update_map(Stage s);
        //void update_mission();
        //void update_score();
        void update_gameover();
        void update_gameclear();
        void update_stageclear();
        void del_win();
        void play();
};