#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include <string>

int main()
{
    const int windowWidth{480};
    const int windowHeight{400};

    InitWindow(windowWidth, windowHeight, "My second top down game");

    //map
    Texture2D map = LoadTexture("tileset/newtileset.png");
    Vector2 mapPos{0.0f, 0.0f};

    //character
    Character saberDude;
    saberDude.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //update worldPos
        mapPos = Vector2Scale(saberDude.getWorldPos(), -1.0f);

        //draw map
        DrawTextureEx(map, mapPos, 0.0f, 3.0f, WHITE);

        //update saberDude
        saberDude.tick(GetFrameTime());

        if(saberDude.getWorldPos().x < 0.0f || saberDude.getWorldPos().y < 0.0f || saberDude.getWorldPos().x + windowWidth > map.width * 3.0f || saberDude.getWorldPos().y + windowHeight > map.height * 3.0f)
        {
            saberDude.undoMovement();
        }

        //pos info
        std::string posX = "Position X: "; //y 100, 1635 x 100, 1500
        posX.append(std::to_string(saberDude.getWorldPos().x), 0, 4);
        DrawText(posX.c_str(), 55.0f, 25.0f, 20, RED);
        std::string posY = "Position Y: "; //y 100, 1635 x 100, 1500
        posY.append(std::to_string(saberDude.getWorldPos().y), 0, 4);
        DrawText(posY.c_str(), 55.0f, 50.0f, 20, RED);

        EndDrawing();
    }

    UnloadTexture(map);

    CloseWindow();
}