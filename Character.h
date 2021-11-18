#include "raylib.h"

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWidth, int winHeigt);
    void tick(float deltaTime);
    void undoMovement();

private:
    Texture2D texture{LoadTexture("characters/Saber_dude/SaberDude_idle.png")};
    Texture2D idle{LoadTexture("characters/Saber_dude/SaberDude_idle.png")};
    Texture2D run{LoadTexture("characters/Saber_dude/SaberDude_move.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float rightLeft{1.0f};
    //animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f / 12.0f};
    const float speed{4.0f};
};