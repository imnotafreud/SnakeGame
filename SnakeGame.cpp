#include <iostream>
#include "raylib.h"
#include "food.h"
#include "snake.h"
#include "raymath.h"
#include <deque>

Color BackgroundColor = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 10;

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
     double currentTime = GetTime();
     if (currentTime - lastUpdateTime >= interval)
     {
          lastUpdateTime = currentTime;
          return true;
     }
     return false;
}

class Game
{
public:
     Snake snake = Snake(cellSize, cellCount, darkGreen);
     Food food = Food(cellSize, cellCount);

     void Draw()
     {
          food.Draw();
          snake.Draw();
     }

     void Update()
     {
          CheckCollisionWithBorders();
          bool isMoving = false;
          if (Vector2Length(snake.getDir()) > 0)
          {
               isMoving = true;
          }

          bool shouldUpdate = true;
          if (checkCollisionWithFood())
          {
               updateFoodPos();
               snake.EatsFruit();
               shouldUpdate = false;
          }
          snake.Update(shouldUpdate, isMoving);
     }

     bool checkCollisionWithFood()
     {
          return Vector2Equals(snake.getBody()[0], food.getPos());
     }

     Vector2 generateValidPos()
     {
          Vector2 newPos = food.GenerateRandomPos();
          while (food.checkIsValidPos(snake.getBody(), newPos))
          {
               newPos = food.GenerateRandomPos();
          }
          return newPos;
     }
     void updateFoodPos()
     {
          food.setPos(generateValidPos());
     }

     void GameOver()
     {
          snake.reset();
     }

     void CheckCollisionWithBorders()
     {
          if (snake.getBody()[0].x < 0 || snake.getBody()[0].x > cellCount-1 || snake.getBody()[0].y < 0 || snake.getBody()[0].x > cellCount-1)
          {
               GameOver();
               food.setPos(food.GenerateRandomPos());
          }
     }

     void CheckCollisionWithTail()
     {
          
     }

};

int main()
{

     // prepare window
     InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
     SetTargetFPS(60);

     // initiate game objects
     // Food food = Food(cellSize, cellCount);
     // Snake snake = Snake(cellSize, cellCount, darkGreen);
     Game game = Game();
     // main loop
     while (!WindowShouldClose())
     {
          DrawFPS(0, 0);
          BeginDrawing();
          ClearBackground(BackgroundColor);
          if (eventTriggered(0.2))
          {
               game.Update();
          }
          // food.Draw();
          // snake.Draw();

          if (IsKeyPressed(KEY_UP) && game.snake.getDir().y != 1)
          {
               game.snake.setDir({0, -1});
          }
          if (IsKeyPressed(KEY_DOWN) && game.snake.getDir().y != -1)
          {
               game.snake.setDir({0, 1});
          }
          if (IsKeyPressed(KEY_LEFT) && game.snake.getDir().x != 1)
          {
               game.snake.setDir({-1, 0});
          }
          if (IsKeyPressed(KEY_RIGHT) && game.snake.getDir().x != -1)
          {
               game.snake.setDir({1, 0});
          }

          game.Draw();
          EndDrawing();
     }

     CloseWindow();
}