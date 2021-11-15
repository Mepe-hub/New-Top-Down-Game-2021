#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth {384};
    const int windowHeight {384};

    InitWindow(windowWidth, windowHeight, "My second top down game");

    Texture2D map = LoadTexture("tileset/newtileset.png");
    Vector2 mapPos {0.0f, 0.0f};
    float speed {4.0f};

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0f;
        if(IsKeyDown(KEY_D)) direction.x += 1.0f;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if(IsKeyDown(KEY_S)) direction.y += 1.0f;
        if(Vector2Length(direction) != 0.0f)
        {
           mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        
        DrawTextureEx(map, mapPos, 0.0f, 3.0f, WHITE); 
        
        EndDrawing();
    }

   UnloadTexture(map);

    CloseWindow();

   
}