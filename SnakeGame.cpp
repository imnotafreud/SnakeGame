#include <iostream>
#include "raylib.h"
#include "food.h"
#include "snake.h"
#include "raymath.h"
#include <deque>

Color BackgroundColor = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

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
     Snake snake = Snake(cellSize, cellCount, offset, darkGreen);
     Food food = Food(cellSize, cellCount, offset);

     int GetScore()
     {
          return score;
     }
     void AddScore(int points)
     {
          score += points;
     }
     void ResetScore()
     {
          score = 0;
     }

     void Draw()
     {
          food.Draw();
          snake.Draw();
     }

     void Update()
     {
          bool isMoving = true;
          bool shouldUpdate = true;
          snake.Update(shouldUpdate, isMoving);
          CheckCollisionWithBorders();

          if (Vector2Length(snake.getDir()) > 0)
          {
               isMoving = true;
          }

          if (checkCollisionWithFood())
          {
               updateFoodPos();
               snake.EatsFruit();
               shouldUpdate = false;
               AddScore(1);
          }
          CheckCollisionWithTail();
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
          ResetScore();
     }

     void CheckCollisionWithBorders()
     {
          if (snake.getBody()[0].x < 0 || snake.getBody()[0].x > cellCount - 1 || snake.getBody()[0].y < 0 || snake.getBody()[0].y > cellCount - 1)
          {
               GameOver();
               food.setPos(food.GenerateRandomPos());
          }
     }
     bool ElementInDeque(std::deque<Vector2> deque, Vector2 element)
     {
          for (int i = 0; i < deque.size(); i++)
          {
               if (Vector2Equals(deque[i], element))
               {

                    return true;
               }
          }
          return false;
     }

     void CheckCollisionWithTail()
     {
          std::deque<Vector2> headlessBody = snake.getBody();
          headlessBody.pop_front();
          if (ElementInDeque(headlessBody, snake.getBody()[0]))
          {
               GameOver();
          }
     }
     private:
          int score = 0;
};

int main()
{

     // prepare window
     InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Snake Game");
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
          ClearBackground(BackgroundColor);
          DrawRectangleLinesEx(Rectangle{offset - 5, offset - 5, cellSize * cellCount + 10, cellSize * cellCount + 10}, 5, darkGreen);
          DrawText("Score:", offset -5, 20,40, darkGreen);
          DrawText(TextFormat("%i", game.GetScore()), 400, 20,40, darkGreen);
          game.Draw();
          EndDrawing();
     }

     CloseWindow();
}