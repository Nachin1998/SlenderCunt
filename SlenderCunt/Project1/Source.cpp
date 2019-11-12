/*#include "raylib.h"



Rectangle warrior;
Rectangle enemy;
Color enemyColor;
Rectangle healthBar;
Rectangle staminaBar;
Rectangle floor;

static const int screenWidth = 800;
static const int screenHeight = 450;

static bool gameOver = false;
static bool pause = false;
static bool touchingFloor = false;
static int hits = 0;
static float playerSpeed = 2.5f;
static int hiScore = 0;

static bool superfx = false;

static void InitGame();       
static void UpdateGame();     
static void DrawGame();       
static void UnloadGame();     
static void UpdateDrawFrame();


int main()
{
	InitWindow(screenWidth, screenHeight, "NIGGERS");

	InitGame();


	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		UpdateDrawFrame();
	}

	UnloadGame();         

	CloseWindow();

	return 0;
}


void InitGame()
{
	floor.x = 0;
	floor.y = screenHeight - 50;
	floor.height = 10;
	floor.width = screenWidth;

	warrior.height = 20;
	warrior.width = 20;
	warrior.x = 100;
	warrior.y = floor.y - warrior.height;

	enemy.height = 20;
	enemy.width = 20;
	enemy.x = screenWidth-10;
	enemy.y = screenHeight - 50 - enemy.width;
	enemyColor = RED;

	healthBar.x = 20;
	healthBar.y = 20;
	healthBar.height = 15;
	healthBar.width = 200;
	
	staminaBar.x = 20;
	staminaBar.y = 35;
	staminaBar.height = 15;
	staminaBar.width = 150;

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

			enemy.x--;

			if (CheckCollisionRecs(warrior, enemy)) { 
				enemyColor = BLUE;
				healthBar.width -= 3;
			}
			else enemyColor = RED;
			

			if (CheckCollisionRecs(warrior, floor)) touchingFloor = true;
			else touchingFloor = false;

			if (IsKeyPressed(KEY_SPACE) && !gameOver && touchingFloor) { 
				int jumpAltitude = warrior.y-100;
				while (jumpAltitude <= warrior.y) warrior.y -= 0.001f;
			}

			if (IsKeyDown(KEY_D)|| IsKeyDown(KEY_RIGHT)) warrior.x+= playerSpeed;
			if (IsKeyDown(KEY_A)|| IsKeyDown(KEY_LEFT)) warrior.x-= playerSpeed;
			
			if(!touchingFloor) warrior.y += 3;
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
		DrawRectangleRec(warrior, BLACK);
		DrawRectangleRec(floor, BLACK);

		if (superfx)
		{
			DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
			superfx = false;
		}

		DrawRectangleRec(healthBar, RED);
		DrawRectangleRec(staminaBar, GREEN);
		DrawRectangle(enemy.x, enemy.y,enemy.height, enemy.width, enemyColor);
		DrawRectangleLines(healthBar.x, healthBar.y,healthBar.width, 15, BLACK);
		DrawRectangleLinesEx(staminaBar, 3, BLACK);

		if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
	
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
}*/