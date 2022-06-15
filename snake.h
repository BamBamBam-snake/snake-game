#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
#include <vector>
#include <string>
using namespace std;

class Mission;

struct Position
{
    int row;
    int col;
    Position() {}
    Position(int r, int c)
    {
        row = r;
        col = c;
    }
};

class Snake
{
public:
    void setInitialSnake();
    void setDirection();
    Stage checkPosition(Stage s, Mission *ms);
    Stage makeSnake(Stage s);
    Stage moveSnake(Stage s);
    Stage removeGate(Stage s);

    Position head_direction;
    vector<Position> snake_body;

    int snakeLen;           // 스네이크 길이
    int gateCnt;            // 게이트 통과 횟수
    char movingDirection;   // r, l, u, d
    int isGameOver = false; // 게임 패배
    string gameOverMSG;
};
