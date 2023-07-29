CFLAGS=-std=c99 -O2 -Wall -Wextra -g3
INC=-Iinclude
LIB=$(shell pkg-config --libs glfw3) $(shell pkg-config --libs glew) -lm
BIN=solitare

SRC=$(wildcard src/*.c)

default: $(BIN)

$(BIN): $(SRC)
	gcc $(CFLAGS) $^ -o $@ $(LIB) $(INC)

clean:
	rm -rf $(BIN)
