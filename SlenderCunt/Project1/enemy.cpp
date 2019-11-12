#include "enemy.h"
#include "definitions.h"

namespace Game {
	Enemy enemy;
	void initEnemy() {
		enemy.rec.height = 20;
		enemy.rec.width = 20;
		enemy.rec.x = screenWidth - 10;
		enemy.rec.y = screenHeight - 20 - enemy.rec.width;
		enemy.color = RED;
	}

	void drawEnemy() {
		DrawRectangleRec(enemy.rec, enemy.color);
	}

	void updateEnemy() {
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) enemy.rec.x -= enemySpeed;
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  enemy.rec.x += enemySpeed;
		enemy.rec.x--;
	}

}