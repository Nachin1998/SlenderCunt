#include "mainMenu.h"
#include "raylib.h"
#include "Source.h"
#include "definitions.h"
namespace Game {
	void menu() {
		InitWindow(screenWidth, screenHeight, "SlenderBoi");
		SetTargetFPS(60);
		
		while (!WindowShouldClose())
		{
			BeginDrawing();

			ClearBackground(BLACK);

			DrawText("SlendiBoi", GetScreenWidth() / 2 - 70, screenHeight / 2 - 200, 50, LIGHTGRAY);

			DrawText("Start", GetScreenWidth() / 2 - 180, screenHeight / 2 - 40, 20, LIGHTGRAY);
			DrawText("(Enter)", GetScreenWidth() / 2 - 190, screenHeight / 2 - 20, 20, LIGHTGRAY);

			DrawText("Exit", GetScreenWidth() / 2 + 120, screenHeight / 2 - 40, 20, LIGHTGRAY);
			DrawText("(Escape)", GetScreenWidth() / 2 + 94, screenHeight / 2 - 20, 20, LIGHTGRAY);

			DrawText("P to pause", GetScreenWidth() / 2 - 60, screenHeight / 2 + 200, 20, LIGHTGRAY);

			if (IsKeyPressed(KEY_ENTER)) {
				play();
			}
			EndDrawing();
		}
	}
}