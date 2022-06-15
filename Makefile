CC = g++
TARGET = snakegame
OBJECTS = map.cpp main.cpp item.cpp gate.cpp snake.cpp mission.cpp

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -std=c++11 -o $(TARGET) $(OBJECTS) -lncurses

