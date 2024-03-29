#include "mission.h"
#include "snake.h"

void Mission::init_Mission(){
        score[0] = 3; score[1] = 0; score[2] = 0; score[3] = 0;
        stageClear = false;
        cur_mission[0] = false; cur_mission[1] = false; cur_mission[2] = false; cur_mission[3] = false;
}
void Mission::createScore(Map m, Snake snake){
    // 윈도우 테두리 출력
    wborder(m.window_score, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(m.window_score, 1, 11, "#Score#"); 
    mvwprintw(m.window_score, 3, 2, "Current Length : %d / %d", snake.snakeLen, score[0]);  // current / max
    mvwprintw(m.window_score, 4, 2, "Current Growth Item :   %d  ", score[1]);
    mvwprintw(m.window_score, 5, 2, "Current Poison Item :   %d  ", score[2]);
    mvwprintw(m.window_score, 6, 2, "Current Gate :   %d   ", score[3]);

    wrefresh(m.window_score);
}

void Mission::createMission(Map m){
	// 윈도우 테두리 출력
    wborder(m.window_mission, '|', '|', '-', '-', '+', '+', '+', '+');

    if(goalStage[0]==false){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[0][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[0][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Poison Item : %d", goal_mission[0][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[0][3]);
    }
    else if(goalStage[1]==false){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[1][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[1][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Poison Item : %d", goal_mission[1][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[1][3]);

    }
    else if(goalStage[2]==false){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[2][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[2][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Poison Item : %d", goal_mission[2][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[2][3]);
    }
    else if(goalStage[3]==false){
        mvwprintw(m.window_mission, 1, 10, "*Mission*");
        mvwprintw(m.window_mission, 3, 2, "Goal Length : %d", goal_mission[3][0]);
        mvwprintw(m.window_mission, 4, 2, "Goal Growth Item : %d", goal_mission[3][1]);
        mvwprintw(m.window_mission, 5, 2, "Goal Poison Item : %d", goal_mission[3][2]);
        mvwprintw(m.window_mission, 6, 2, "Goal Gate : %d", goal_mission[3][3]);
    }
    wrefresh(m.window_mission);
}
void Mission::setMission(Map m){
    if(cur_mission[0]==true) mvwprintw(m.window_mission, 3, 25, "v");
    else { mvwprintw(m.window_mission, 3, 25, " "); }
    if(cur_mission[1]==true) mvwprintw(m.window_mission, 4, 25, "v");
    else { mvwprintw(m.window_mission, 4, 25, " "); }
    if(cur_mission[2]==true) mvwprintw(m.window_mission, 5, 25, "v");
    else { mvwprintw(m.window_mission, 5, 25, " "); }
    if(cur_mission[3]==true) mvwprintw(m.window_mission, 6, 25, "v");
    else { mvwprintw(m.window_mission, 6, 25, " "); }

    wrefresh(m.window_mission);
}
void Mission::check(Stage s){
    if (score[0]>=goal_mission[s.num_of_stage][0]) cur_mission[0] = true;
    if (score[1]>=goal_mission[s.num_of_stage][1]) cur_mission[1] = true;
    if (score[2]>=goal_mission[s.num_of_stage][2]) cur_mission[2] = true;
    if (score[3]>=goal_mission[s.num_of_stage][3]) cur_mission[3] = true;

    for(int i=0; i<4; i++) { if(cur_mission[i] == false) return; }
    goalStage[s.num_of_stage] = true;
    stageClear = true;
}