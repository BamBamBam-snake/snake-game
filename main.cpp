#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include "map.h"

// 맵 테스트를 위한 main 함수
int main()
{
    Item i;
    Gate g;
    Stage s;
    Map m;
    Snake snake;

    m.init_window(); // 맵 초기화
    // *todo* //
    // 일정 시간이 지나면 아이템, 게이트 재생성 //
    s = i.generate_item(s); // 맵에 아이템 생성
    s = g.generate_gate(s); // 맵에 게이트 생성

    snake.setInitialSnake(); // 초기 스네이크 위치 세팅
    s = snake.makeSnake(s);  // 스네이크 생성

    s = m.update_map(s);
    m.update_score();
    m.update_mission();

    while (true)
    {
        s = snake.removeSnake(s); // 기존 스네이크 지우기
        snake.setDirection();     // 스네이크 방향 탐지
        snake.checkItem(s); // 아이템을 먹었는지 확인
        s = snake.makeSnake(s); // 스네이크 새로 생성

        s = m.update_map(s);
        m.update_score();
        m.update_mission();

        usleep(200000); // 0.2초 sleep
    }

    // getch() : 프로그램을 일시 정지하고 한 문자를 입력받으면 프로그램 계속 진행
    getch();

    // 윈도우를 소멸시킴
    m.del_win();
    endwin();

    return 0;
}
