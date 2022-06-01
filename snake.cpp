#include "snake.h"

Stage Snake::makeSnake(Stage s)
{

    s.stage[s.num_of_stage][8][7] = 3;
    s.stage[s.num_of_stage][8][8] = 4;
    s.stage[s.num_of_stage][8][9] = 4;
    s.stage[s.num_of_stage][8][10] = 4;
    s.stage[s.num_of_stage][8][11] = 4;

    return s;
}