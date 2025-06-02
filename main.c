#include "camera.h"
#include "main.h"

#include <raylib.h>

#include <stdio.h>
#include <errno.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#define GAME_VERSION_MAJOR 0
#define GAME_VERSION_MINOR 1
#define GAME_VERSION_PATCH 0
#define GAME_VERSION_STRING "alpha 0.1"

void loop(void);
void cleanup(void);

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE void pause(void){ emscripten_pause_main_loop(); }
EMSCRIPTEN_KEEPALIVE void unpause(void){ emscripten_resume_main_loop(); }
EMSCRIPTEN_KEEPALIVE void shutdown(void){
  emscripten_cancel_main_loop();
  cleanup();
}
#endif

Camera3D* cam;

int main(void){
  cam = getCamera();
  cam->position = (Vector3){ 0.0f, 0.0f, 0.0f };
  cam->target = (Vector3){ 1.0f, 0.0f, 0.0f };
  cam->up = (Vector3){ 0.0f, 1.0f, 0.0f };
  cam->fovy = 80.0f;
  cam->projection = CAMERA_PERSPECTIVE;

  InitWindow(640, 480, "HELLO");
  if(!IsWindowReady()){
    perror("failed to initialize raylib. bye bye.\n");
    return -1;
  }

  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(loop, 0, 1);
  #endif

  SetTraceLogLevel(LOG_DEBUG);
  
  DisableCursor();

  while(!WindowShouldClose()){
    loop();
  }
  
  cleanup();
  
  return 0;
}

void loop(void){
  DrawFPS(0, 0);
  
  PollInputEvents();

#ifdef __EMSCRIPTEN__
  if(IsMouseButtonDown(0) && !IsCursorHidden()){
    DisableCursor();
  }
#endif
  
  updateCameraCustom(GET_DELTATIME());
  
  ClearBackground(SKYBLUE);
  BeginDrawing();
  BeginMode3D(*cam);
  /*DrawCube(Vector3 position, float width, float height, float length, Color color);*/
  DrawCube(
    (Vector3){ 2.0f, 0.0f, 0.0f },
    1.0f,
    1.0f,
    1.0f,
    GRAY
  );
  EndMode3D();
  EndDrawing();
  
  SwapScreenBuffer();
}

void cleanup(void){
  CloseWindow();
}
