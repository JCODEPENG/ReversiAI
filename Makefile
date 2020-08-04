CFLAGS = -Wall

all: build

build:
	g++ $(CFLAGS) main.cpp reversi.cpp -o out


run: build
	./out


clean:
	rm out 