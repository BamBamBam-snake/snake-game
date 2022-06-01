#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
class Snake{
    public:
        Stage makeSnake(Stage s);
        int num_of_growth;
        int row, col;
};