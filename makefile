.PHONY: exec clean format

SRCS = $(wildcard src/*.s)

all: build/main

build/main: $(SRCS)
	gcc -I src/functions.h src/main.c $(SRCS) -o $@ -lm

exec: ./build/main
	./build/main

clean: build
	rm -f ./build/*

format: 
	clang-format -i ./src/*