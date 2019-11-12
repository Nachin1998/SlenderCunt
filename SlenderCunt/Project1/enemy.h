#ifndef	ENEMY_H
#define ENEMY_H
#include "raylib.h"
namespace Game {
	const float enemySpeed = 2.5f;
	struct Enemy {
		float health;
		bool active;
		Rectangle rec;
		Color color;
	};

	extern Enemy enemy;

	void initEnemy();
	void drawEnemy();
	void updateEnemy();
}

#endif
