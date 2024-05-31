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

void Snake::setDir(Vector2 newDir)
{
    dir = newDir;
}

Vector2 Snake::getDir()
{
    return dir;
}

void Snake::Update(bool shouldUpdate, bool isMoving)
{
    if(shouldUpdate && isMoving)
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], dir));
    }

}

void Snake::EatsFruit()
{
    body.push_front(Vector2Add(body[0], dir));
    std::cout << "Snake now is " << body.size() << " length" << std::endl;
}


std::deque<Vector2> Snake::getBody()
{
    return body;
}

void Snake::reset()
{
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    dir = {0,0};
}