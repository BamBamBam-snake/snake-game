#include "map.h"

// extern void generate_item();
void Map:: init_window(){
    // initscr(): ncurses TUI 모드 시작
    initscr();
    // start_color(): 색깔 사용
    start_color(); 
    // 유니코드 사용
    setlocale(LC_ALL, "");
    // 커서 안보이게함
    curs_set(0);
    // 키보드 입력한 값을 화면에 안보이게함
    noecho();
   
    // @window_map: x = 15, y = 15 위치에 가로 40, 세로 30의 크기의 윈도우
    window_map = newwin(30, 40, 15, 15);
    // @window_mission: 미션 표시 윈도우
    window_mission = newwin(10, 30, 5, 15);
    // @window_score: 점수 표시 윈도우
    window_score = newwin(10, 30, 5, 55);
}

// update_map: map 윈도우를 업데이트
Stage Map:: update_map(Stage s)
{    
    // @stage 배열 값에 따라 윈도우 구성
    for(int row = 0; row < 30; row++){
        for(int col = 0; col < 40; col++){
            // immune wall
            if(s.stage[s.num_of_stage][row][col] == 2){
                mvwprintw(window_map, row, col, "X"); // \u2B1B 
            }
            // wall
            else if(s.stage[s.num_of_stage][row][col] == 1) {
                mvwprintw(window_map, row, col, "O");
            }
            // background
            else if(s.stage[s.num_of_stage][row][col] == 0) {
                mvwprintw(window_map, row, col, " ");
            }
            // snake head
            else if(s.stage[s.num_of_stage][row][col] == 3) {
                mvwprintw(window_map, row, col, "@");
            }
            // snake body
            else if(s.stage[s.num_of_stage][row][col] == 4) {
                mvwprintw(window_map, row, col, "*");
            }
            // growth item
            else if(s.stage[s.num_of_stage][row][col] == 5) {
                mvwprintw(window_map, row, col, "+");
            }
            // poison item
            else if(s.stage[s.num_of_stage][row][col] == 6) {
                mvwprintw(window_map, row, col, "-");
            }
            // gate
            else if(s.stage[s.num_of_stage][row][col] == 7) {
                mvwprintw(window_map, row, col, "G");
            }

        } 
    }
    
    // 윈도우 refresh
    refresh();
    wrefresh(window_map);
    return s;
}

// update_mission: 미션 윈도우를 업데이트
void Map:: update_mission(){
    // 윈도우 테두리 출력
    wborder(window_mission, '|', '|', '-', '-', '+', '+', '+', '+');

    // todo //
    // int goal_length, goal_growth_item, goal_poison_item, goal_number_of_passed_gate

    mvwprintw(window_mission, 1, 10, "*Mission*");
    mvwprintw(window_mission, 3, 2, "Goal Length : %d", 0);
    mvwprintw(window_mission, 4, 2, "Goal Growth Item : %d", 0);
    mvwprintw(window_mission, 5, 2, "Goal Posion Item : %d", 0);
    mvwprintw(window_mission, 6, 2, "Goal Gate : %d", 0);

    // 윈도우 refresh
    refresh();
    wrefresh(window_mission);
}

// update_score: 스코어 윈도우를 업데이트
void Map:: update_score(){
    
     // todo // 
     // int current_length, current_grow_item, current_poison_item, current_num_of_passed_gate

    // 윈도우 테두리 출력
    wborder(window_score, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(window_score, 1, 11, "#Score#"); 
    mvwprintw(window_score, 3, 2, "Current Length : %d / %d", 0, 0);  // current / max
    mvwprintw(window_score, 4, 2, "Current Growth Item :   %d  ", 0);
    mvwprintw(window_score, 5, 2, "Current Poison Item :   %d  ", 0);
    mvwprintw(window_score, 6, 2, "Current Gate :   %d   ", 0);

    // 윈도우 refresh
    refresh();
    wrefresh(window_score);
    
    // 미션 성공시 출력 ex) Current Gate : 3 ( v )
    // *todo*

}

// del_win(): 모든 윈도우를 제거
void Map::del_win(){
    delwin(window_map);
    delwin(window_mission);
    delwin(window_score);
    // 전체 윈도우 종료
    endwin();
}

