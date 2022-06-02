#include <ncurses.h>
#include "snake.h"

void Snake::setInitialSnake()
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
}

// 뱀 이동 위치 설정

void Snake::setDirection()
{
    nodelay(stdscr, true);
    int key = getch();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    switch (key)
    {

    case KEY_RIGHT:
        if (movingDirection == 'l')
        {
            // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'r'; // 우측 방향
        headCol++;
        tail_x_dir = -1;
        tail_y_dir = 0;
        break;

    case KEY_LEFT:
        if (movingDirection == 'r')
        {
            // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'l'; // 좌측 방향
        headCol--;
        tail_x_dir = 1;
        tail_y_dir = 0;

        break;

    case KEY_UP:
        if (movingDirection == 'u')
        {
            // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'd'; // 아래 방향
        headRow--;
        tail_x_dir = 0;
        tail_y_dir = 1;
        break;

    case KEY_DOWN:
        if (movingDirection == 'd')
        {
            // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'u'; // 위쪽 방향
        headRow++;
        tail_x_dir = 0;
        tail_y_dir = -1;
        break;
    }

}

// 아이템을 먹었는지 판단.
void Snake::checkItem(Stage s)
{
    if (s.stage[s.num_of_stage][headRow][headCol] == 5) // Growth Item을 먹었을때
        snakeLen++;                                     // 스네이크 길이 증가

    else if (s.stage[s.num_of_stage][headRow][headCol] == 6) // Poison Item을 먹었을때
        snakeLen--;                                          // 스네이크 길이 감소
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