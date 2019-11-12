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

	struct HealthBar {
		Rectangle rec;
		Color color;
	}healthBar;

	struct StaminaBar {
		Rectangle rec;
		Color color;
	}staminaBar;

	static void InitGame();
	static void UpdateGame();
	static void DrawGame();
	static void UnloadGame();
	static void UpdateDrawFrame();

	void play()
	{

		InitWindow(screenWidth, screenHeight, "sample game: floppy");

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


		healthBar.rec.x = 20;
		healthBar.rec.y = 20;
		healthBar.rec.height = 15;
		healthBar.rec.width = 200;

		staminaBar.rec.x = 20;
		staminaBar.rec.y = 35;
		staminaBar.rec.height = 15;
		staminaBar.rec.width = 150;

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
				if (CheckCollisionRecs(warrior.rec, enemy.rec)) {
					enemy.color = BLUE;
					healthBar.rec.width -= 3;
				}
				else enemy.color = RED;


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

		DrawRectangleRec(healthBar.rec, RED);
		DrawRectangleRec(staminaBar.rec, GREEN);
		DrawRectangleLines(healthBar.rec.x, healthBar.rec.y, 200, healthBar.rec.height, BLACK);
		DrawRectangleLinesEx(staminaBar.rec, 3, BLACK);

		if (pause) DrawText("Paused", screenWidth / 2 - MeasureText("Paused", 40) / 2, screenHeight / 2 - 40, 40, GRAY);

		else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

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
