#ifndef	ENEMY_H
#define ENEMY_H
#include "raylib.h"
namespace Game {
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
