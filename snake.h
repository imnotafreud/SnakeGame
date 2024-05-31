#include "raylib.h"
#include <iostream>
#include <deque>

class Snake
{
public:
    Snake(int cellSize, int cellCount, Color snakeColor);
    void Draw();
    void Update(bool shouldUpdate, bool isMoving);
    void EatsFruit();
    void setDir(Vector2 newDir);
    Vector2 getDir();
    std::deque<Vector2> getBody();
    void reset();


private:
    int cellSize{};
    int cellCount{};
    Color snakeColor{};
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 dir{0,0};
};