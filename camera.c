#include "main.h"

#include "camera.h"

#include <raylib.h>
#include <math.h>

#include <stdio.h>

#define SQRT1_2 0.707106781

Camera3D camera = { 0 };

Camera3D* getCamera(void){
    return &camera;
}

void updateCameraCustom(float deltatime){
  /*void UpdateCameraPro(Camera *camera, Vector3 movement, Vector3 rotation, float zoom);*/
  Vector3 movement = { 0 };
  float speed = 0.1f;
  float mousesensitivity = 10.0f;
  float arrowsensitivity = 1.5f;
  
  float dx = ((float)IsKeyDown(KEY_W) - (float)IsKeyDown(KEY_S)) * speed * deltatime;
  float dy = ((float)IsKeyDown(KEY_D) - (float)IsKeyDown(KEY_A)) * speed * deltatime;
  if(dx != 0.0f && dy != 0.0f){
    dx *= SQRT1_2;
    dy *= SQRT1_2;
  }
  movement.x = dx;
  movement.y = dy;
  movement.z = 0.0f;
  
  Vector2 moused = GetMouseDelta();
  float rx = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
  float ry = IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP);
  if(rx == 0.0f && ry == 0.0f){
    rx = moused.x * mousesensitivity;
    ry = moused.y * mousesensitivity;
  } else{
    rx *= arrowsensitivity;
    ry *= arrowsensitivity;
    if(rx != 0.0f && ry != 0.0f){
      rx *= SQRT1_2;
      ry *= SQRT1_2;
    }
  }
  rx *= deltatime;
  ry *= deltatime;
  
  UpdateCameraPro(
    &camera,
    movement,
    (Vector3){ rx, ry, 0.0f },
    0.0f
  );
}
