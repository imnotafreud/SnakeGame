
#include "raylib.h"

class Food
{
public:
    Food(int cellSize, int cellCount);
    void Draw();
    void setPos(Vector2 newPos);
    Vector2 GenerateRandomPos();

    ~Food()
    {
    }

private:
    Vector2 pos{};
    int cellSize{};
    int cellCount{};
    float x{}, y{};
};
