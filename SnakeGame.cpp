#include <iostream>
#include "raylib.h"
#include "food.h"
#include "snake.h"

Color BackgroundColor = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

int main()
{

     // prepare window
     InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
     SetTargetFPS(60);

     // initiate game objects
     Food food = Food(cellSize, cellCount);
     Snake snake = Snake(cellSize, cellCount, darkGreen);

     // main loop
     while (!WindowShouldClose())
     {
          DrawFPS(0, 0);
          BeginDrawing();
          ClearBackground(BackgroundColor);

          food.Draw();
          snake.Draw();

          if (IsKeyPressed(KEY_R))
          {
               food.setPos(food.GenerateRandomPos());
          }

          EndDrawing();
     }

     CloseWindow();
}