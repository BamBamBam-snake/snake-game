#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
#include <vector>
using namespace std;

class Mission;

struct Position
{
    int row;
    int col;
    Position(){}
    Position(int r, int c){
        row = r;
        col = c;
    }
};

class Snake
{
public:
    void setInitialSnake();
    void setDirection();
    Stage checkPosition(Stage s, Mission *ms);
    Stage makeSnake(Stage s);
    Stage removeSnake(Stage s);
    Stage moveSnake(Stage s);

    int snakeLen;
    int headRow, headCol;
    char movingDirection; // r, l, u, d
    int tail_x_dir;       //   -1 , 1
    int tail_y_dir;       // -1 , 1
    int isGameOver = false; // 게임 패배
    Position head_direction;
    vector<Position> snake_body;
};
