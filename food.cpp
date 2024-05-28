#include "food.h"
#include "raylib.h"


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

Vector2 Food::GenerateRandomPos()
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}
