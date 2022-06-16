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
    m.init_color(); // 컬러 설정
    snake.setInitialSnake(); // 초기 스네이크 위치 세팅
    s = snake.makeSnake(s);  // 스네이크 생성

    m.update_map(s);
    ms.createScore(m,snake);
    ms.createMission(m);
    
    i.item_time = 0; // 아이템 생성 쿨타임 초기화
    g.gate_time = 0; // 게이트 생성 쿨타임 초기화
    
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
            m.update_gameover(snake);
            break;
        }
        s = snake.moveSnake(s); 
        s = snake.makeSnake(s); // 스네이크 새로 생성

        if(ms.score[1] >= 2){ //growth item을 2개이상 획득한 경우
            if(g.gate_time == 0){ // 첫 게이트 생성 시간 저장
                g.gate_time = time(NULL); 
                s = g.generate_gate(s); // 맵에 게이트 생성
            }
            else if (time(NULL) - g.gate_time > 7 && snake.numOfPassedBody <= 0){ // 게이트가 통과중이 아니고, 7초가 지나면 게이트 재생성
                g.gate_time = 0;
                s = g.delete_gate(s);
            }
        }

        if(i.item_time == 0){ // 첫 게이트 생성 시간 저장
            i.item_time = time(NULL); 
            s = i.generate_item(s); // 맵에 아이템 생성
            }
        else if (time(NULL) - i.item_time > 10){ // 10초가 지나면 아이템 재생성
            i.item_time = 0;
            s = i.delete_item(s);
        }

        // 스테이지 클리어의 경우
        if(ms.stageClear == true && s.num_of_stage != 3) {
            ms.setMission(m);
            i.item_time = 0;
            g.gate_time = 0;
            m.update_stageclear(); 
            m.init_window();
            snake.setInitialSnake(); 
            s = snake.makeSnake(s); 
            ms.init_Mission();
            s.num_of_stage++;

            // 키 입력 시 다음 스테이지 진행
            s = snake.makeSnake(s); // 스네이크 새로 생성   
            m.update_status(s); 
            m.update_map(s);
            ms.createScore(m,snake);
            ms.createMission(m);
            getch();
            continue;
        }
        
        // 게임 클리어의 경우
        if(ms.stageClear==true && s.num_of_stage == 3){
            m.update_gameclear();
            break;
        }
        
        m.update_status(s); // 상태 창 업데이트
        m.update_map(s); // 맵 업데이트
        ms.createScore(m,snake);
        ms.createMission(m);
        snake.numOfPassedBody--;
        usleep(150000); // 0.15초 sleep
    }

    // 윈도우를 소멸시킴
    m.del_win();

    return 0;
}
