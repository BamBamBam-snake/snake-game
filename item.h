#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
class Item{
    public:
        Stage generate_item(Stage s);
        Stage delete_item(Stage s);
        int num_of_growth;
        int row, col;
        int cnt;
        int item_position[5][2];
};