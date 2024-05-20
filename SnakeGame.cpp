#include "raylib.h"





int main()
{

     //prepare window
     InitWindow(800, 600, "MyWindow");
     SetTargetFPS(60);
     //main loop
     while (!WindowShouldClose())
     {
          
          float dt = GetFrameTime();
          DrawFPS(0, 0);
          BeginDrawing();
          ClearBackground(WHITE);
          //draw background


      EndDrawing();
     }

     CloseWindow();
} 