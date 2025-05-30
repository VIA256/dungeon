CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -Iraylib/build/raylib/include
LDFLAGS=-Wl,-rpath=. -L. -lraylib -lGL -lm

GAME_SRC=main.c
GAME_OBJ=main.o

all: game

game: $(GAME_OBJ)
ifeq (,$(wildcard ./libraylib*))
	cp raylib/build/raylib/libraylib.so* .
endif
	$(CC) $(GAME_OBJ) $(LDFLAGS) -o dungeon_game

main.o: main.c
	$(CC) -c $(GAME_SRC) $(CFLAGS) -o main.o

clean:
ifneq (,$(wildcard *.o))
	rm *.o
endif
ifneq (,$(wildcard dungeon_game))
	rm dungeon_game
endif
ifneq (,$(wildcard libraylib.so*))
	rm libraylib.so*
endif
