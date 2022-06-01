#include "gate.h"
// generate_gate : 벽애 게이트 생성
Stage Gate:: generate_gate(Stage s){
    // 매 번 다른 난수 생성
    srand(time(NULL));

    // 게이트 행, 열 좌표 초기화
    gate1_row = 0; gate1_col = 0; gate2_row = 0; gate2_col = 0;
    
    // 게이트 1 생성
    while(s.stage[s.num_of_stage][gate1_row][gate1_col] != 1){
        gate1_row = rand() % 30;
        gate1_col = rand() % 40;
        // immune wall 옆 벽은 생성되지 않도록 함
        if(s.stage[s.num_of_stage][gate1_row - 1][gate1_col] == 2 || s.stage[s.num_of_stage][gate1_row+1][gate1_col] == 2 || s.stage[s.num_of_stage][gate1_row][gate1_col-1] == 2 || s.stage[s.num_of_stage][gate1_row][gate1_col + 1] == 2){
            gate1_row = 0; gate1_col = 0;
        }
    }
    s.stage[s.num_of_stage][gate1_row][gate1_col] = 7;

    // 게이트 2 생성
    while(s.stage[s.num_of_stage][gate2_row][gate2_col] != 1){
        gate2_row = rand() % 30;
        gate2_col = rand() % 40;
        if(s.stage[s.num_of_stage][gate2_row - 1][gate2_col] == 2 || s.stage[s.num_of_stage][gate2_row+1][gate2_col] == 2 || s.stage[s.num_of_stage][gate2_row][gate2_col-1] == 2 || s.stage[s.num_of_stage][gate2_row][gate2_col + 1] == 2){
            gate2_row = 0; gate2_col = 0;
        }
    }
    s.stage[s.num_of_stage][gate2_row][gate2_col] = 7;

    return s;
}