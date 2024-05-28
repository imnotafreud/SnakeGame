#include "raylib.h"
#include "snake.h"
#include "raymath.h"

Snake::Snake(int cellSize, int cellCount, Color snakeColor) : cellSize(cellSize), cellCount(cellCount), snakeColor(snakeColor)
{
}

void Snake::Draw()
{
    Color col = snakeColor;
    for (unsigned int i = 0; i < body.size(); i++)
    {
        int x = body[i].x;
        int y = body[i].y;
        if(i==0)
        {
            col = ColorBrightness(snakeColor, -0.5);
        }
        else
        {
            col = snakeColor;
        }

        DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, col);
    }
}