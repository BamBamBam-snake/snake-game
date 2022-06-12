#pragma once
#include "map.h"
#include "snake.h"

class Mission{
	public:
		void createScore(Map m, Snake snake);
		void setScore();
		void createMission(Map m);
		void setMission();
		void check();

		int score[4] = {3,0,0,0};
		int cur_mission[4] = {0,0,0,0};
		int goal_mission[4][4] = {{4,3,2,1},{5,4,3,2},{6,5,4,3},{7,6,5,4}};
		bool goalStage[4] = {false,false,false,false};

};