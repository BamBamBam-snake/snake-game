#include "map.h"
#include "snake.h"
#include <cstring>

void Map:: init_window(){
    // initscr(): ncurses TUI 모드 시작
    initscr();
    // 커서 안보이게함
    curs_set(0);
    // 키보드 입력한 값을 화면에 안보이게함
    noecho();
    // color 사용
    start_color();
    // @window_map: 행 = 15, 열 = 15 위치에 가로 40, 세로 30의 크기의 윈도우
    window_map = newwin(30, 40, 10, 15);
    // @window_mission: 미션 표시 윈도우
    window_mission = newwin(10, 30, 10, 57);
    // @window_score: 점수 표시 윈도우
    window_score = newwin(10, 30, 20, 57);
    // @window_status: 게임 상태 표시 윈도우
    window_status = newwin(5, 30, 35, 57);

    // 윈도우 테두리 출력
    wborder(window_status, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(window_status, 2, 4, "Press any key to start");
     // 윈도우 refresh
    refresh();
    wrefresh(window_status);
}

// init_color: 사용할 color의 pair 설정
void Map::init_color(){
    init_pair(0, COLOR_BLACK, 234); //background : Gray
    init_pair(1, COLOR_BLACK, 240); //wall : light gray
    init_pair(2, COLOR_BLACK, 15); //immune wall : white
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, 153); //snake body : sky blue
    init_pair(5, COLOR_BLACK, COLOR_GREEN);     // Growth Item
    init_pair(6, COLOR_BLACK, COLOR_RED);         // Poison Item
    init_pair(7, COLOR_BLACK, COLOR_MAGENTA);   // Gate
}

// update_map: map 윈도우를 업데이트
void Map:: update_map(Stage s)
{    
    // @stage 배열 값에 따라 윈도우 구성
    for(int row = 0; row < 30; row++){
        for(int col = 0; col < 40; col++){
            // immune wall
            if(s.stage[s.num_of_stage][row][col] == 2){
                wattron(window_map, COLOR_PAIR(2));
                mvwprintw(window_map, row, col, " ");
                wattroff(window_map, COLOR_PAIR(2));
            }
            // wall
            else if(s.stage[s.num_of_stage][row][col] == 1) {
                wattron(window_map, COLOR_PAIR(1));
                mvwprintw(window_map, row, col, " ");
                wattroff(window_map, COLOR_PAIR(1));
            }
            // background
            else if(s.stage[s.num_of_stage][row][col] == 0) {
                wattron(window_map, COLOR_PAIR(0));
                mvwprintw(window_map, row, col, " ");
                wattroff(window_map, COLOR_PAIR(0));
            }
            // snake head
            else if(s.stage[s.num_of_stage][row][col] == 3) {
                wattron(window_map, COLOR_PAIR(3));
                mvwprintw(window_map, row, col, " ");
                wattroff(window_map, COLOR_PAIR(3));            }
            // snake body
            else if(s.stage[s.num_of_stage][row][col] == 4) {
                wattron(window_map, COLOR_PAIR(4));
                mvwprintw(window_map, row, col, " ");
                wattroff(window_map, COLOR_PAIR(4));            }
            // growth item
            else if(s.stage[s.num_of_stage][row][col] == 5) {
                wattron(window_map, COLOR_PAIR(5));
                mvwprintw(window_map, row, col, "G");
                wattroff(window_map, COLOR_PAIR(5));
            }
            // poison item
            else if(s.stage[s.num_of_stage][row][col] == 6) {
                wattron(window_map, COLOR_PAIR(6));
                mvwprintw(window_map, row, col, "P");
                wattroff(window_map, COLOR_PAIR(6));
            }
            // gate
            else if(s.stage[s.num_of_stage][row][col] == 7) {
                wattron(window_map, COLOR_PAIR(7));
                mvwprintw(window_map, row, col, "G");
                wattroff(window_map, COLOR_PAIR(7));
            }

        } 
    }
    
    // 윈도우 refresh
    refresh();
    wrefresh(window_map);
}

void Map:: update_gameover(Snake snake){
    wclear(window_status);
    // 윈도우 테두리 출력
    wborder(window_status, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(window_status, 1, 10, "*GameOver*");
    mvwprintw(window_status, 2, 1, snake.gameOverMSG);

    // 윈도우 refresh
    refresh();
    wrefresh(window_status);
    // 다시 딜레이 설정 후, 아무 키나 입력 받으면 종료
    nodelay(stdscr, false);
    getch();
    wclear(window_status);
}

void Map:: update_gameclear(){
    wclear(window_status);
    // 윈도우 테두리 출력
    wborder(window_status, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(window_status, 1, 8, "*Congratuation*");
    mvwprintw(window_status, 2, 10, "*GameClear*");

    // 윈도우 refresh
    refresh();
    wrefresh(window_status);
    // 다시 딜레이 설정 후, 아무 키나 입력 받으면 종료
    nodelay(stdscr, false);
    getch();
    wclear(window_status);
}

// update_stageclear: 스테이지 클리어시 @window_status를 update
void Map:: update_stageclear(){
    wclear(window_status);
    // 윈도우 테두리 출력
    wborder(window_status, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(window_status, 1, 8, "* Stage Clear *");
    mvwprintw(window_status, 2, 7, "* Press any key *");
    mvwprintw(window_status, 3, 6, "* to go next stage *");

    // 윈도우 refresh
    refresh();
    wrefresh(window_status);
    // 다시 딜레이 설정 후, 아무 키나 입력 받으면 종료
    nodelay(stdscr, false);
    getch();
    wclear(window_status);
}
// update_status: 현재 진행중인 스테이지 출력
void Map::update_status(Stage s){
    wclear(window_status);
    wborder(window_status, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(window_status, 2, 10, "Stage : %d",s.num_of_stage + 1);
     // 윈도우 refresh
    refresh();
    wrefresh(window_status);
}

// del_win: 모든 윈도우를 제거
void Map::del_win(){
    delwin(window_map);
    delwin(window_mission);
    delwin(window_score);
    delwin(window_status);
    // 전체 윈도우 종료
    endwin();
}

