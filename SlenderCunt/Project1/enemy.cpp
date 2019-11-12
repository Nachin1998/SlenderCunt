#include "enemy.h"
#include "definitions.h"

namespace Game {
	Enemy enemy;
	void initEnemy() {
		enemy.rec.height = 20;
		enemy.rec.width = 20;
		enemy.rec.x = screenWidth - 10;
		enemy.rec.y = screenHeight - 50 - enemy.rec.width;
		enemy.color = RED;
	}

	void drawEnemy() {
		DrawRectangleRec(enemy.rec, enemy.color);
	}

	void updateEnemy() {
		enemy.rec.x--;
	}

}