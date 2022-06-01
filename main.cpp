#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include "map.h"

// #include "item.cpp"
// #include "gate.cpp"

// 맵 테스트를 위한 main 함수

int main()
{
    Item i;
    Gate g;
    Stage s;
    Map m;
    Snake ms;
    // bool is_gameover = 0;
    // while(!(is_gameover)){

    // }
    // 윈도우 초기화
    m.init_window();
    s = i.generate_item(s);
    s = g.generate_gate(s);

    s = ms.setInitialSnake(s); // 초기 스네이크 위치 세팅
    s = ms.makeSnake(s);       // 스네이크 생성

     s = m.update_map(s);
    m.update_score();
    m.update_mission();

    while (true)
    {
        s = ms.removeSnake(s);  // 기존 스네이크 지우기
        s = ms.setDirection(s); // 스네이크 방향 탐지
        s = ms.makeSnake(s);    // 스네이크 새로 생성

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
