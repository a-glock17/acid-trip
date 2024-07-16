CC := gcc
SRC := ./src
OUT := ./build/
FLAGS := -Wall -Wshadow -Werror -O2 -std=c99 -s
LIBS := /usr/lib/x86_64-linux-gnu/libGL.so -lraylib -lm -lpthread -ldl -lrt -lX11

.PHONY: all linux windows

all:
	clear

windows:
	# todo: implement

linux:
	mkdir -p build/linux64
	$(CC) $(SRC)/main.c $(FLAGS) -o $(OUT)/linux64/acid-trip $(LIBS)

purge:
	rm -rf build/*