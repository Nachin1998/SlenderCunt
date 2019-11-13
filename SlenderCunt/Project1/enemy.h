#ifndef	ENEMY_H
#define ENEMY_H
#include "raylib.h"
namespace Game {
	const float enemySpeed = 2.5f;
	const int cantSlimes = 5;
	const int cantMedusa = 2;
	struct Enemy {
		float health;
		bool active;
		Rectangle rec;
		Color color;
	};

	extern Enemy slime[cantSlimes];
	extern Enemy medusa[cantMedusa];

	void initEnemy();
	void drawEnemy();
	void updateEnemy();
}

#endif
