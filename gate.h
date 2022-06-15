#pragma once
#include <vector>
#include <stdlib.h>
#include "stage.h"
#include "map.h"
using namespace std;

class Gate{
    public:
        Stage generate_gate(Stage s);
        Stage delete_gate(Stage s);
        int gate1_row, gate1_col, gate2_row, gate2_col;
        int gate_position[2][2];
        time_t gate_time;
};
