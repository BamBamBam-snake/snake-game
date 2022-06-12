#include "mission.h"

void Mission::createScore(Map m, Snake snake){
    // 윈도우 테두리 출력
    wborder(m.window_score, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(m.window_score, 1, 11, "#Score#"); 
    mvwprintw(m.window_score, 3, 2, "Current Length : %d / %d", snake.snakeLen, score[0]);  // current / max
    mvwprintw(m.window_score, 4, 2, "Current Growth Item :   %d  ", score[1]);
    mvwprintw(m.window_score, 5, 2, "Current Poison Item :   %d  ", score[2]);
    mvwprintw(m.window_score, 6, 2, "Current Gate :   %d   ", score[3]);

    // 윈도우 refresh
    refresh();
    wrefresh(m.window_score);
}
void Mission::setScore(){}
void Mission::createMission(Map m){
	// 윈도우 테두리 출력
    wborder(m.window_mission, '|', '|', '-', '-', '+', '+', '+', '+');

    // todo //
    // int goal_length, goal_growth_item, goal_poison_item, goal_number_of_passed_gate
    if(goalStage[0]==false){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[0][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[0][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Posion Item : %d", goal_mission[0][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[0][3]);
    }
    else if(goalStage[0]==true){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[1][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[1][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Posion Item : %d", goal_mission[1][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[1][3]);

    }
    else if(goalStage[1]==true){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[2][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[2][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Posion Item : %d", goal_mission[2][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[2][3]);
    }
    else if(goalStage[2]==true){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[3][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[3][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Posion Item : %d", goal_mission[3][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[3][3]);
    }

    // 윈도우 refresh
    refresh();
    wrefresh(m.window_mission);
}
void Mission::setMission(){}
void Mission::check(){

}