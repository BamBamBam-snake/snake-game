#include "item.h"

Stage Item:: generate_item(Stage s){
    // 매 번 다른 난수 생성
    srand((unsigned)time(NULL));

    // 생성할 성장 아이템 수
    // 0 ~ 3 난수 생성
    cnt = 0;
    num_of_growth = 3;
    // 아이템을 6개 생성할 때 까지 반복
    while(cnt < 6){
            
        // @row : 아이템을 생성할 행 좌표, 0 ~ 29 까지의 난수
        row = rand() % 30;
        // @col : 아이템을 생성할 열 좌표, 0 ~ 39 까지의 난수
        col = rand() % 40;

        // 아이템 생성 좌표를 저장
        item_position[cnt][0] = row; item_position[cnt][1] = col;
        // map안에 있을 경우
        if(s.stage[s.num_of_stage][row][col] == 0){
            // 성장 아이템 수가 생성한 아이템 수보다 작은 경우 성장 아이템 생성
            if(cnt >= num_of_growth){
            // 성장 아이템은 5
                s.stage[s.num_of_stage][row][col] = 5;
                cnt++;
                }
            else {
                // 포이즌 아이템은 6
                s.stage[s.num_of_stage][row][col] = 6;
                cnt++;
            }
        }
    }
    return s;
}

// delete_item: @stage에 생성된 아이템 값을 0으로 변경
Stage Item:: delete_item(Stage s){
    for(int i = 0; i < 6; i++){
        s.stage[s.num_of_stage][item_position[i][0]][item_position[i][1]] = 0;
    }
    return s;
}