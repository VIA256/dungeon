#ifndef H_MAIN_H
#define H_MAIN_H

#include <raylib.h>

#define GAME_VERSION_MAJOR 0
#define GAME_VERSION_MINOR 1
#define GAME_VERSION_PATCH 0
#define GAME_VERSION_STRING "alpha 0.1"

#define FPS 60
#define GET_DELTATIME(void) (GetFrameTime()*60) //NOT ADJUSTED WITH FPS BECAUSE THEN MOVESPEEDS WILL BE AFFECTED

#endif
