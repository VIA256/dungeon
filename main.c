#include "camera.h"

#include "main.h"

#include <raylib.h>

#include <stdio.h>
#include <errno.h>

int main(void){
  Camera3D* cam = getCamera();
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

  SetTargetFPS(FPS);

  SetTraceLogLevel(LOG_DEBUG);
  
  DisableCursor();
  
  while(!WindowShouldClose()){
    DrawFPS(0, 0);

    PollInputEvents();
    
    UpdateCameraCustom(GET_DELTATIME());

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
  
  CloseWindow();
  
  return 0;
}
