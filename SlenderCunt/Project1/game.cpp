#include "raylib.h"
#include "definitions.h"
#include "player.h"
#include "enemy.h"
#include "parallax.h"

namespace Game {
	struct Floor {
		Rectangle rec;
		Color color;
	};
	Floor floor;

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
		init_parallax();
		initPlayer();
		initEnemy();
		floor.rec.x = 0;
		floor.rec.y = screenHeight - 13;
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
				
				update_parallax();
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
		draw_parallax();

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

	void gravity(Rectangle &rec) {
		bool touchingFloor;

		if (CheckCollisionRecs(rec, floor.rec)) touchingFloor = true;
		else touchingFloor = false;

		if (!touchingFloor)
			rec.y += 3;
	}

	void UnloadGame()
	{
		unload_parallax();
	}

	void UpdateDrawFrame()
	{
		UpdateGame();
		DrawGame();
	}
}