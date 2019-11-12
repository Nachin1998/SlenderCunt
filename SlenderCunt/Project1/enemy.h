#ifndef	ENEMY_H
#define ENEMY_H
#include "raylib.h"
namespace Game {
	const float enemySpeed = 2.5f;
	struct Enemy {
		Rectangle rec;
		Color color;
	};

	extern Enemy enemy;

	void initEnemy();
	void drawEnemy();
	void updateEnemy();
}

#endif
