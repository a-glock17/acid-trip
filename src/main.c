#include "raylib.h"
#include <stdio.h>

/* this uses raylib 5.5 from July 2024 */

// local var def
Camera camera = { 0 };
Vector3 cube_position = { 0 };

// local func dec
static void UpdateDrawFrame(void);

int main(void)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const char TITLE[11] = "Acid Trip!";

    InitAudioDevice();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    // Camera setup
    camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    camera.target   = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up       = (Vector3){0.0f, 1.0f, 0.0f };
    camera.fovy     = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

// update and draw frame
static void UpdateDrawFrame(void)
{
    // update
    UpdateCamera(&camera, CAMERA_ORBITAL);

    // draw
    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

            DrawCube(cube_position, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cube_position, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("Raylib, now in 3D :D", 10, 10, 20, DARKGRAY);

    EndDrawing();


}