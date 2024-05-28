#include "raylib.h"
#include <iostream>
#include <deque>

class Snake
{
public:
    Snake(int cellSize, int cellCount, Color snakeColor);
    void Draw();

private:
    int cellSize{};
    int cellCount{};
    Color snakeColor{};
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
};