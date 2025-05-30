#include <stdio.h>
#include <raylib.h>

int main(void){
  InitWindow(640, 480, "HELLO");
  while(!WindowShouldClose()){
    PollInputEvents();
  }
  CloseWindow();
  
  return 0;
}
