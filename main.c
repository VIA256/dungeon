#include <raylib.h>

#include <stdio.h>
#include <errno.h>


#define FPS 60
#define DELTATIME(void) (GetFrameTime()*FPS)

int main(void){
  InitWindow(640, 480, "HELLO");
  if(!IsWindowReady()){
    perror("failed to initialize raylib. bye bye.\n");
    return -1;
  }

  SetTargetFPS(FPS);

  SetTraceLogLevel(LOG_DEBUG);
  
  while(!WindowShouldClose()){
    PollInputEvents();

    BeginDrawing();
    EndDrawing();
    
    SwapScreenBuffer();

    printf("DELTATIME = %f\n", DELTATIME());
  }
  
  CloseWindow();
  
  return 0;
}
