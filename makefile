CC=gcc
EXEC=md5

build: main.c message.c hash.c
	$(CC) $^ -o $(EXEC) -Wall
