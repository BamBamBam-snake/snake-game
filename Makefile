CC=g++
TARGET=snakegame
OBJECTS= map.cpp main.cpp item.cpp gate.cpp
#  gate.cpp item.cpp

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -std=c++11 -o $(TARGET) $(OBJECTS) -lncurses

# all:
# 	 g++ -std=c++11 -o main main.cpp map.cpp item.cpp -lncurses
