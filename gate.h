#pragma once
#include <vector>
#include <stdlib.h>
#include "stage.h"
#include "map.h"
using namespace std;

class Gate{
    public:
        int collision_gate();
        Stage generate_gate(Stage s);
        int gate1_row, gate1_col, gate2_row, gate2_col;
};
// vector<int> gate;
