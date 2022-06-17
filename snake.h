#pragma once
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "stage.h"
#include <vector>
#include <string>
using namespace std;

class Mission;
class Gate;

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
    void setInitialSnake(); // 스네이크의 상태를 초기화
    void setDirection();    // 방향키 입력을 받아 스네이크 이동방향 설정

    // 다음 clock의 스네이크 위치에 따른 이벤트 생성
    Stage checkPosition(Stage s, Mission *ms);
    Stage makeSnake(Stage s); // 스네이크 생성을 위한 Stage 배열 수정
    Stage moveSnake(Stage s); // head_direction 방향으로 스네이크 이동

    Position head_direction;
    vector<Position> snake_body;
    vector<Position> snake_gate_tail;

    int snakeLen;            // 스네이크 길이
    char movingDirection;    // 스네이크 방향: r, l, u, d
    int isGameOver = false;  // 게임 종료 여부
    const char *gameOverMSG; // 게임 종료 이유
    int numOfPassedBody;     // 게이트를 통과한 몸의 수
};
