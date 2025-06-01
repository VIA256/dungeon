CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -Iraylib/build/raylib/include
LDFLAGS=-Wl,-rpath=. -L. -lraylib -lGL -lm

GAME_OBJ=main.o camera.o
TESTING_OBJ=testing.o settings.o

all: game

testing: $(TESTING_OBJ)
ifeq (,$(wildcard ./libraylib*))
	cp raylib/build/raylib/libraylib.so* .
endif
	$(CC) $(TESTING_OBJ) $(LDFLAGS) -o dungeon_testing

game: $(GAME_OBJ)
ifeq (,$(wildcard ./libraylib*))
	cp raylib/build/raylib/libraylib.so* .
endif
	$(CC) $(GAME_OBJ) $(LDFLAGS) -o dungeon_game

main.o: main.c main.h
	$(CC) -c main.c $(CFLAGS) -o main.o

testing.o: testing.c
	$(CC) -c testing.c $(CFLAGS) -o testing.o

camera.o: camera.c camera.h
	$(CC) -c camera.c $(CFLAGS) -o camera.o

settings.o: settings.c settings.h
	$(CC) -c settings.c $(CFLAGS) -o settings.o

clean:
ifneq (,$(wildcard *.o))
	rm *.o
endif
ifneq (,$(wildcard dungeon_game))
	rm dungeon_game
endif
ifneq (,$(wildcard dungeon_testing))
	rm dungeon_testing
endif
ifneq (,$(wildcard libraylib.so*))
	rm libraylib.so*
endif
