#include <deque>
#include "raylib.h"

class Food
{
public:
    Food(int cellSize, int cellCount);
    void Draw();
    void setPos(Vector2 newPos);
    Vector2 getPos();
    Vector2 GenerateRandomPos();
    bool checkIsValidPos(std::deque<Vector2> snakeBody, Vector2 newPos);

    ~Food()
    {
    }

private:
    Vector2 pos{};
    int cellSize{};
    int cellCount{};
    float x{}, y{};
};
