#include "Character.h"
#include "raymath.h"

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos =
        {
            static_cast<float>(winWidth / 2.0f) - 2.0f * (0.5f * static_cast<float>(texture.width)),
            static_cast<float>(winHeight / 2.0f) - 2.0f * (0.5f * static_cast<float>(texture.height / 6))};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0f;
    if (Vector2Length(direction) != 0.0f)
    {
        //set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    //update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.0f;
        if (frame > maxFrames)
            frame = 0;
    }

    //draw sprite
    Rectangle source{
                    0.0f, frame * static_cast<float>(texture.height / 6), 
                    rightLeft * static_cast<float>(texture.width), 
                    static_cast<float>(texture.height / 6)};
    Rectangle dest{
                    screenPos.x, screenPos.y, 
                    static_cast<float>(2.0f * texture.width), 
                    static_cast<float>(2.0f * texture.height / 6)};

    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);
}

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}