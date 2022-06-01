#include <ncurses.h>
#include <iostream>
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
    s = ms.makeSnake(s);
    s = m.update_map(s);
    m.update_score();
    m.update_mission();
    // getch() : 프로그램을 일시 정지하고 한 문자를 입력받으면 프로그램 계속 진행
    getch();

    // 윈도우를 소멸시킴
    m.del_win();
    endwin();

    return 0;
}
