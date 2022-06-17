# snake-game

## Getting Started

Install ncurses library

``` bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

Compile and Run

``` bash
make
./snakegame
```

## Demo video

[Watch Demo Video](https://drive.google.com/file/d/17iT9aE3fNwf8xDlvq0ecXTu83Yf_PYyJ/view?usp=sharing)

![snake_gif](https://user-images.githubusercontent.com/39684946/174345294-12270d86-aa78-499e-9d4b-7fa14e616d1b.gif)

## User Manual

1. 게임 실행 방법

- make를 수행한 디렉토리에서 terminal에서 ./snakegame 을 입력합니다.
- 첫 화면에서 아무 키나 입력하면 게임이 진행됩니다.
- 게임의 조작은 방향키만 사용하여 Snake를 조작합니다.
- 스테이지 클리어 시 아무 키를 입력하면 다음 스테이지로 진행합니다.
- 게임 클리어 시 아무 키를 입력하면 프로그램이 종료됩니다.

2. 주의사항

- 게임 화면의 크기는 전체 화면으로 하여 실행해 주시기 바랍니다.
- ncurses 라이브러리가 설치되어 있어야 합니다.
- c++ 컴파일러가 설치되어 있어야 합니다.
- terminal 환경에서 실행되어야 합니다.

3. 게임실행과정

다음은 게임을 실행했을 때의 첫 화면입니다.

![image](https://user-images.githubusercontent.com/39684946/174340230-5f8851e7-fe04-4040-9831-85085086d75f.png)

- 임의의 키를 입력하면 게임이 시작됩니다.
- snake의 조작법은 사용자의 방향키입니다.
- Stage는 총 4개입니다.
- 우측 상단부터 차례로 미션창과 점수판입니다.
- 점수판의 값은 현 snake의 상태이고, 이 값이 미션창의 값과 동일할 때에 스테이지가 클리어 됩니다.
- Game Over : snake의 길이가 3미만이 될 경우, snake가 벽에 부딪힐 경우, snake가 자신의 몸에 부딪힐 경우

다음은 게임에 사용되는 색상 설명입니다.

![image](https://user-images.githubusercontent.com/39684946/174340807-8570f689-f174-4a4f-a662-a5d7dba5ad8e.png)

- 회색 : Wall
- 흰색: Immune Wall
- 파란색: Snake Head
- 하늘색: Snake Body
- 초록색 : Growth Item
- 빨간색 : Poison Item
- 분홍색 : Gate
