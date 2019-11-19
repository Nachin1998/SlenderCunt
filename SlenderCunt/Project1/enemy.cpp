#include "enemy.h"
#include "player.h"
#include "game.h"
#include "definitions.h"

namespace Game {
	void enemyMovement();
	Enemy slime[cantSlimes];
	Enemy medusa[cantMedusa];
	float bottomRange = 30, topRange = screenHeight - 100, CosSinAux = 0, origY = screenHeight / 2;
	void initEnemy() {

		for (int i = 0; i < cantSlimes; i++)
		{
			slime[i].health = 100.0f;
			slime[i].active = true;
			slime[i].rec.height = 20;
			slime[i].rec.width = 20;
			slime[i].rec.x = GetRandomValue(screenWidth / 2, screenWidth);
			slime[i].rec.y = screenHeight - 20 - slime[i].rec.width;
			slime[i].color = RED;
		}

		for (int i = 0; i < cantMedusa; i++)
		{
			medusa[i].health = 100.0f;
			medusa[i].active = true;
			medusa[i].rec.height = 20;
			medusa[i].rec.width = 20;
			medusa[i].rec.x = screenWidth - 10;
			medusa[i].rec.y = screenHeight / 2;
			medusa[i].color = BLUE;
		}
	}

	void drawEnemy() {
		for (int i = 0; i < cantSlimes; i++)
			if (slime[i].active)
				DrawRectangleRec(slime[i].rec, slime[i].color);

		for (int i = 0; i < cantMedusa; i++)
			if (medusa[i].active)
				DrawRectangleRec(medusa[i].rec, medusa[i].color);
	}

	void updateEnemy() {
		enemyMovement();
	}

	void enemyMovement()
	{
		CosSinAux++;
		//Slime movement
		for (int i = 0; i < cantSlimes; i++)
		{
			if (slime[i].health > 1)slime[i].active = true;
			else slime[i].active = false;

			if (slime[i].active) {
				if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) slime[i].rec.x -= enemySpeed;
				if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  slime[i].rec.x += enemySpeed;
				slime[i].rec.x--;

				if (CheckCollisionRecs(slime[i].rec, warrior.rec)) {
					slime[i].color = BLUE;
					warrior.health -= 3;
				}
				else
					slime[i].color = RED;

				if (slime[i].rec.x < 0 - slime[i].rec.width) slime[i].rec.x = screenWidth;
			}
			gravity(slime[i].rec);
			//Medusa Movement
			for (int i = 0; i < cantMedusa; i++)
			{
				if (medusa[i].health >= 1) medusa[i].active = true;
				else medusa[i].active = false;

				if (medusa[i].active)
				{
					if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) medusa[i].rec.x -= enemySpeed / 3;
					if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  medusa[i].rec.x += enemySpeed / 3;

					if (medusa[i].rec.x < 0 - medusa[i].rec.width)
					{
						medusa[i].rec.x = screenWidth;
						medusa[i].rec.y = GetRandomValue(0, GetScreenHeight() - (medusa[i].rec.height * 2));
					}

					if(i == 0)
						medusa[i].rec.y = ((screenHeight / 4) * sin(CosSinAux * 0.5f * PI / 50)) + origY;
					else
						medusa[i].rec.y = -((screenHeight / 4) * sin(CosSinAux * 0.5f * PI / 50)) + origY;

					medusa[i].rec.x -= enemySpeed / 4;
				}

				if (CheckCollisionRecs(medusa[i].rec, warrior.rec)) {
					medusa[i].color = BLUE;
					warrior.health -= 3;

				}
			}
		}
	}
}