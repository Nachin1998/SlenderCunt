#include "enemy.h"
#include "player.h"
#include "game.h"
#include "definitions.h"

namespace Game {
	Enemy enemy;
	void initEnemy() {
		enemy.health = 100.0f;
		enemy.active = true;
		enemy.rec.height = 20;
		enemy.rec.width = 20;
		enemy.rec.x = screenWidth - 10;
		enemy.rec.y = 400 - enemy.rec.height;
		enemy.color = RED;
	}

	void drawEnemy() {
		if (enemy.active) 
			DrawRectangleRec(enemy.rec, enemy.color);
	}

	void updateEnemy() {
		if (enemy.health > 1)enemy.active = true;
		else enemy.active = false;

		if (enemy.active) {
			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) enemy.rec.x -= enemySpeed;
			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  enemy.rec.x += enemySpeed;
			enemy.rec.x--;

			if (CheckCollisionRecs(enemy.rec, warrior.rec)) {
				enemy.color = BLUE;
				warrior.health -= 3;
			}
			else
				enemy.color = RED;

			if (enemy.rec.x < 0 - enemy.rec.width) enemy.rec.x = screenWidth;
		}

		gravity(enemy.rec);
	}

}