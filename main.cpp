#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#include "map.h"
#include "mission.h"

// 맵 테스트를 위한 main 함수
int main()
{
    Item i;
    Gate g;
    Stage s;
    Map m;
    Mission ms;
    Snake snake;

    m.init_window(); // 맵 초기화
    // *todo* //
    // 일정 시간이 지나면 아이템, 게이트 재생성 //
    s = i.generate_item(s); // 맵에 아이템 생성
    s = g.generate_gate(s); // 맵에 게이트 생성

    snake.setInitialSnake(); // 초기 스네이크 위치 세팅
    s = snake.makeSnake(s);  // 스네이크 생성

    s = m.update_map(s);
    ms.createScore(m,snake);
    ms.createMission(m);

    while (true)
    {
        nodelay(stdscr, true); // 딜레이 없이 게임 진행
        s = snake.removeSnake(s); // 기존 스네이크 지우기
        snake.setDirection();     // 스네이크 방향 탐지
        
        snake.checkPosition(s); // 스네이크가 이동한 위치 확인 (아이템, 게이트, 벽이 존재하는지)
        if(snake.isGameOver){ // 게임 종료 조건에 충족했을경우 (벽 충돌, 방향키 반대)
            m.update_gameover();
            break;
        }

        // 스테이지 클리어의 경우
        // m.update_stageclear();
        
        // 게임 클리어의 경우
        // m.update_gameclear();

        

        s = snake.makeSnake(s); // 스네이크 새로 생성

        s = m.update_map(s);
        ms.createScore(m,snake);
        ms.createMission(m);

        usleep(200000); // 0.2초 sleep
    }

    // 윈도우를 소멸시킴
    m.del_win();

    return 0;
}
