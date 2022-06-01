#include <ncurses.h>
#include "snake.h"

Stage Snake::setInitialSnake(Stage s)
{
    // 우측방향으로 이동
    movingDirection = 0;
    tail_x_dir = -1;
    tail_y_dir = 0;

    // 스네이크 길이: 3
    snakeLen = 3;

    // 스네이크 머리 위치
    headRow = 8;
    headCol = 8;

    return s;
}

// 뱀 이동 위치 설정

Stage Snake::setDirection(Stage s)
{

    bool gameOver = false;
    char key = getch();

    switch (key)
    {

    case 'd':
        if (movingDirection == 'l')
        {
            gameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'r'; // 우측 방향
        headCol++;
        tail_x_dir = -1;
        tail_y_dir = 0;
        break;

    case 'a':
        if (movingDirection == 'r')
        {
            gameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'l'; // 좌측 방향
        headCol--;
        tail_x_dir = 1;
        tail_y_dir = 0;

        break;

    case 'w':
        if (movingDirection == 'u')
        {
            gameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'd'; // 아래 방향
        headRow--;
        tail_x_dir = 0;
        tail_y_dir = 1;
        break;

    case 's':
        if (movingDirection == 'd')
        {
            gameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'u'; // 위쪽 방향
        headRow++;
        tail_x_dir = 0;
        tail_y_dir = -1;
        break;
    }
    return s;
}

// 스네이크 삭제
Stage Snake::removeSnake(Stage s)
{
    if (tail_x_dir == 0)
    {
        for (int i = 0; i < snakeLen; i++)
            s.stage[s.num_of_stage][headRow + (tail_y_dir * i)][headCol] = 0;
    }
    else
    {
        for (int i = 0; i < snakeLen; i++)
            s.stage[s.num_of_stage][headRow][headCol + (tail_x_dir * i)] = 0;
    }
    return s;
}

// 스네이크 생성
Stage Snake::makeSnake(Stage s)
{
    s.stage[s.num_of_stage][headRow][headCol] = 3;
    if (tail_x_dir == 0)
    {
        for (int i = 1; i < snakeLen; i++)
            s.stage[s.num_of_stage][headRow + (tail_y_dir * i)][headCol] = 4;
    }
    else
    {
        for (int i = 1; i < snakeLen; i++)
            s.stage[s.num_of_stage][headRow][headCol + (tail_x_dir * i)] = 4;
    }
    return s;
}
