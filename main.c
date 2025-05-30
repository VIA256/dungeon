#include <raylib.h>

#include <stdio.h>
#include <errno.h>


#define FPS 60
#define DELTATIME(void) (GetFrameTime()*FPS)

int main(void){
  Camera3D cam = { 0 };/*(Camera3D){
			 (Vector3){ 0 },
			 (Vector3){ 1.0f, 0.0f, 0.0f },
			 (Vector3){ 0.0f, 1.0f, 0.0f },
			 80.0f,
			 CAMERA_PERSPECTIVE
			 };*/
  cam.position = (Vector3){ 0 };
  cam.target = (Vector3){ 1.0f, 0.0f, 0.0f };
  cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  cam.fovy = 80.0f;
  cam.projection = CAMERA_PERSPECTIVE;

  
  InitWindow(640, 480, "HELLO");
  if(!IsWindowReady()){
    perror("failed to initialize raylib. bye bye.\n");
    return -1;
  }

  SetTargetFPS(FPS);

  SetTraceLogLevel(LOG_DEBUG);
  
  while(!WindowShouldClose()){
    PollInputEvents();
    UpdateCamera(&cam, CAMERA_FIRST_PERSON);

    ClearBackground(SKYBLUE);
    BeginDrawing();
    EndDrawing();
    
    SwapScreenBuffer();
  }
  
  CloseWindow();
  
  return 0;
}
