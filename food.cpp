#include "food.h"
#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <iostream>

Food::Food(int cellSize, int cellCount) : cellSize(cellSize), cellCount(cellCount)
{
    pos = GenerateRandomPos();
}

void Food::Draw()
{
    DrawRectangle(pos.x * cellSize, pos.y * cellSize, cellSize, cellSize, RED);
}

void Food::setPos(Vector2 newPos)
{
    pos = newPos;
}

Vector2 Food::getPos()
{
    return pos;
}

bool Food::checkIsValidPos(std::deque<Vector2> snakeBody, Vector2 newPos)
{
    for(int i=0; i < snakeBody.size(); i++)
    {
        if(Vector2Equals(snakeBody[i], newPos))
        {
            std::cout<< "Hit in Snake" << std::endl;
            return true;
        }
    }
    return false;
}
Vector2 Food::GenerateRandomPos()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);

    return Vector2{x, y};
}
