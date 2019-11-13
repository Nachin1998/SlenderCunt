#ifndef	PLAYER_H
#define PLAYER_H
#include "raylib.h"

namespace Game {
	struct Warrior {
		float health;
		float attackDamage;
		bool aim;
		bool active;
		Rectangle rec;
		Color color;
		Texture2D sprite;
	};

	extern Warrior warrior;
	extern Image aux;

	void initPlayer();
	void drawPlayer();
	void updatePlayer();
}
#endif
