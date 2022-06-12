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
    
    // 시작 위치는 머리가 8,8
    snake_body.push_back(Position(8,8));
    snake_body.push_back(Position(8,7));
    snake_body.push_back(Position(8,6));

    // 첫 뱀은 오른쪽을 보고있음, head 방향을 0,1로 설정
    head_direction = Position(0, 1);
    movingDirection = 'r';
    
}

// 스네이크 좌표 값에 따라 @stage 배열 수정
Stage Snake::makeSnake(Stage s)
{   vector<Position>::iterator it;
     for (it = snake_body.begin(); it != snake_body.end(); it++) {
         if(it == snake_body.begin()){ // 첫 시작은 head 이므로 3
            s.stage[s.num_of_stage][snake_body[0].row][snake_body[0].col] = 3;
         }
        else{
            s.stage[s.num_of_stage][it->row][it->col] = 4;
        }
     }

    return s;
}

// moveSnake: 현재 snake head 좌표 값에 @head_direction의 방향을 더해서 다음 움직임 좌표 계산
Stage Snake::moveSnake(Stage s){
    // 스네이크 다음 이동 좌표
    int next_row = snake_body[0].row + head_direction.row;
    int next_col = snake_body[0].col + head_direction.col;
    
    // 맵에서 꼬리 부분을 0으로 바꿔줌
    s.stage[s.num_of_stage][snake_body.back().row][snake_body.back().col] = 0;
    snake_body.pop_back(); // 꼬리를 제거

    // 맵에서 새로운 head 위치에 다음 좌표 값을 insert (0번째 인덱스)
    snake_body.insert(snake_body.begin(), Position(next_row, next_col));
    

    return s;
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
            isGameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'r'; // 우측 방향
        head_direction = Position(0, 1);
        break;

    case KEY_LEFT:
        if (movingDirection == 'r')
        {
            isGameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'l'; // 좌측 방향
        head_direction = Position(0, -1);
        break;

    case KEY_UP:
        if (movingDirection == 'u')
        {
            isGameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'd'; // 아래 방향
        head_direction = Position(-1, 0);
        break;

    case KEY_DOWN:
        if (movingDirection == 'd')
        {
            isGameOver = true; // 반대방향 키를 누르면 게임 종료
        }
        movingDirection = 'u'; // 위쪽 방향
        head_direction = Position(1, 0);
        break;
    }
}

// snake head 충돌에 따른 이벤트 생성 함수
Stage Snake::checkPosition(Stage s)
{
    // 다음 loop에서 진행할 뱀의 head 좌표
    int next_row = snake_body[0].row + head_direction.row;
    int next_col = snake_body[0].col + head_direction.col;

    // 벽에 충돌할때
    if (s.stage[s.num_of_stage][next_row][next_col] == 1 || s.stage[s.num_of_stage][next_row][next_col] == 2)
    {
        isGameOver = true;
        return s;
    }
    // 자기 몸에 부딪혔을때
    else if (s.stage[s.num_of_stage][next_row][next_col] == 4){
        isGameOver = true;
        return s;
    }
    
    // Growth Item을 먹었을때
    else if (s.stage[s.num_of_stage][next_row][next_col] == 5){
        // 맵에서 증가한 몸의 좌표 값을 insert (0번째 인덱스)
        snake_body.push_back(Position(next_row, next_col));
        snakeLen++; // 스네이크 길이 증가
        return s;
        }
    
    // Poison Item을 먹었을때
    else if (s.stage[s.num_of_stage][next_row][next_col] == 6){
        // 삭제할 꼬리 좌표의 @stage 배열 값을 0으로 설정
        s.stage[s.num_of_stage][snake_body.back().row][snake_body.back().col] = 0;
        snake_body.pop_back(); // 꼬리를 제거
        snakeLen--; // 스네이크 길이 감소
        if (snakeLen < 3) // 스네이크의 길이가 3보다 작으면 게임 종료
        {
            isGameOver = true; 
            return s;
        }
        
        return s;
    }

    // 게이트를 들어갈때
    else if (s.stage[s.num_of_stage][headRow][headCol] == 7)
    {
        bool exitOuterLoop = false;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                if (s.stage[s.num_of_stage][i][j] == 7 && !(i == headRow && j == headCol))
                {
                    headRow = i;
                    headCol = j;

                    if (i == 0)
                    {
                        movingDirection = 'd'; // 아래쪽 방향
                        tail_x_dir = 0;
                        tail_y_dir = 1;
                    }
                    else if (i == 29)
                    {
                        movingDirection = 'u'; // 위쪽 방향
                        tail_x_dir = 0;
                        tail_y_dir = -1;
                    }

                    else if (j == 0)
                    {
                        movingDirection = 'r'; // 오른쪽 방향
                        tail_x_dir = -1;
                        tail_y_dir = 0;
                    }

                    else if (j == 39)
                    {
                        movingDirection = 'l'; // 왼쪽 방향
                        tail_x_dir = 1;
                        tail_y_dir = 0;
                    }
                    exitOuterLoop = true;
                    break;
                }
            }
            if (exitOuterLoop == true)
                break;
        }
    }
    return s;
}

