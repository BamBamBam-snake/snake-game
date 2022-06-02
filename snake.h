#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
class Snake
{
public:
    void setInitialSnake();
    void setDirection();
    void checkItem(Stage s);

    Stage makeSnake(Stage s);
    Stage removeSnake(Stage s);

    int snakeLen;
    int headRow, headCol;
    char movingDirection; // r, l, u, d
    int tail_x_dir;       //   -1 , 1
    int tail_y_dir;       // -1 , 1
};