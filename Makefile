CFLAGS = -Wall -g -Werror

all: build

build:
	g++ $(CFLAGS) main.cpp reversi.cpp -o out


run: build
	./out


clean:
	rm -f main.o reversi.o