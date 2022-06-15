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

    time_t current_time = 0;

    m.init_window(); // 맵 초기화

    snake.setInitialSnake(); // 초기 스네이크 위치 세팅
    s = snake.makeSnake(s);  // 스네이크 생성

    s = m.update_map(s);
    ms.createScore(m,snake);
    ms.createMission(m);

    // 아무 키나 입력하면 시작
    getch();

    while (true)
    {   
        ms.setMission(m); // 스테이지 미션
        nodelay(stdscr, true); // 딜레이 없이 게임 진행

        // s = snake.removeSnake(s); // 기존 스네이크 지우기
        snake.setDirection();     // 스네이크 방향 탐지
        s = snake.checkPosition(s, &ms); // 스네이크가 이동한 위치 확인 (아이템, 게이트, 벽이 존재하는지)
        ms.check(s); // 미션충족 여부 확인
        if(snake.isGameOver){ // 게임 종료 조건에 충족했을경우 (벽 충돌, 방향키 반대)
            m.update_gameover();
            break;
        }
        s = snake.moveSnake(s); 
        s = snake.makeSnake(s); // 스네이크 새로 생성

        if(current_time == 0){ // 첫 시간 저장
            current_time = time(NULL); 
            s = i.generate_item(s); // 맵에 아이템 생성
            s = g.generate_gate(s); // 맵에 게이트 생성
            }
        else if (time(NULL) - current_time > 10){ // 10초가 지나면 아이템과 게이트 재생성
            current_time = 0;
            s = i.delete_item(s);
            s = g.delete_gate(s);
        }


        // 스테이지 클리어의 경우
        if(ms.stageClear == true && s.num_of_stage != 3) {
            current_time = 0 ;
            m.update_stageclear(); 
            m.init_window();
            snake.setInitialSnake(); 
            s = snake.makeSnake(s); 
            ms.init_Mission();
            s.num_of_stage++;
            continue;
        }
        
        
        // 게임 클리어의 경우
        if(ms.stageClear==true && s.num_of_stage == 3){
            m.update_gameclear();
            break;
        }
        
        m.update_status(s); // 상태 창 업데이트
        s = m.update_map(s);
        ms.createScore(m,snake);
        ms.createMission(m);

        usleep(150000); // 0.15초 sleep
    }

    // 윈도우를 소멸시킴
    m.del_win();

    return 0;
}
