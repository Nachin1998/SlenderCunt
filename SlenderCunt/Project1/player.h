#ifndef	PLAYER_H
#define PLAYER_H
#include "raylib.h"

namespace Game {
	struct Warrior {
		Rectangle rec;
		Color color;
	};

	extern Warrior warrior;

	void initPlayer();
	void drawPlayer();
	void updatePlayer();
}
#endif
