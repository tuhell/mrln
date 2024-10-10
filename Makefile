CC=clang

all: example

example: example/str/basic.c
	${CC} -Wall -Wextra -g -pedantic -std=c99 -fsanitize=address,undefined example/str/basic.c -I include

bear:
	bear -- make all
