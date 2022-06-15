#pragma once
#include "map.h"
#include "stage.h"
class Snake;

class Mission{
	public:
		void init_Mission();
		void createScore(Map m, Snake snake);
		void setScore();
		void createMission(Map m);
		void setMission(Map m);
		void check(Stage s);

		int score[4] = {3,0,0,0};
		bool stageClear = false;
		bool cur_mission[4] = {false,false,false,false};
		int goal_mission[4][4] = {{6,5,2,1},{7,6,3,2},{8,7,4,3},{9,8,5,4}};
		bool goalStage[4] = {false,false,false,false};

};