#include "raylib.h"
#include "definitions.h"
#include "player.h"
#include "enemy.h"
#include "mainMenu.h"
#include "parallax.h"
#include "platforms.h"

namespace Game {

	static void InitGame();
	static void UpdateGame();
	static void UpdateEntites();
	static void DrawGame();
	static void UnloadGame();
	static void UpdateDrawFrame();

	void play()
	{
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

		initFloor();
		initPlatforms();

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
				UpdateEntites();

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
		drawFloor();
		drawPlatforms();
		

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

		for (int i = 0; i < maxPlatform; i++) {
			if (CheckCollisionRecs(rec, floor.rec) || CheckCollisionRecs(rec, platform[i].rec)) touchingFloor = true;
			else touchingFloor = false;
		}

		if (!touchingFloor) rec.y += 3;
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

	void UpdateEntites() {

		updateEnemy();
		updatePlayer();
		update_parallax();
		updatePlatforms();
	}
}
