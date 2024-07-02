#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "JO HYUK JUN - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("UNLUCKY STRIKE", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

