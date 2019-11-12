#include "raylib.h"
#include "definitions.h"
#include "player.h"
#include "enemy.h"
#include "parallax.h"

namespace Game {
	struct Floor {
		Rectangle rec;
		Color color;
	}floor;

	static void InitGame();
	static void UpdateGame();
	static void DrawGame();
	static void UnloadGame();
	static void UpdateDrawFrame();

	void play()
	{
		InitWindow(screenWidth, screenHeight, "SlenderBoi");

		InitGame();

		SetTargetFPS(60);

		while (!WindowShouldClose())
		{
			UpdateDrawFrame();
		}

		UnloadGame();

		CloseWindow();
	}
	void InitGame()
	{

		initPlayer();
		initEnemy();
		floor.rec.x = 0;
		floor.rec.y = screenHeight - 50;
		floor.rec.height = 10;
		floor.rec.width = screenWidth;

		gameOver = false;
		superfx = false;
		pause = false;
	}

	void UpdateGame()
	{
		if (!gameOver)
		{
			if (IsKeyPressed('P')) pause = !pause;

			if (!pause)
			{
				updateEnemy();

				updatePlayer();
				


				if (CheckCollisionRecs(warrior.rec, floor.rec)) touchingFloor = true;
				else touchingFloor = false;

				if (IsKeyPressed(KEY_SPACE) && !gameOver && touchingFloor) {
					int jumpAltitude = warrior.rec.y - 100;
					while (jumpAltitude <= warrior.rec.y) warrior.rec.y -= 0.001f;
				}

				if (!touchingFloor) warrior.rec.y += 3;
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				InitGame();
				gameOver = false;
			}
		}
	}

	void DrawGame()
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (!gameOver)

		drawPlayer();
		drawEnemy();
		DrawRectangleRec(floor.rec, BLACK);

		if (superfx)
		{
			DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
			superfx = false;
		}
	
		if (pause) DrawText("Paused", screenWidth / 2 - MeasureText("Paused", 40) / 2, screenHeight / 2 - 40, 40, GRAY);

		EndDrawing();
	}

	void UnloadGame()
	{

	}

	void UpdateDrawFrame()
	{
		UpdateGame();
		DrawGame();
	}
}
