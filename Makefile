CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=

GAME_SRC=main.c
GAME_OBJ=main.o

all: game

game: $(GAME_OBJ)
	$(CC) $(GAME_OBJ) $(LDFLAGS) -o dungeon_game

main.o: main.c
	$(CC) -c $(GAME_SRC) $(CFLAGS) -o main.o
