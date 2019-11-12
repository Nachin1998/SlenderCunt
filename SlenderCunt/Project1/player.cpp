#include "player.h"

namespace Game {
	Warrior warrior;

	void initPlayer() {
		warrior.rec.height = 20;
		warrior.rec.width = 20;
		warrior.rec.x = 100;
		warrior.rec.y = 400 - warrior.rec.height;
		warrior.color = BLACK;
	}

	void drawPlayer() {
		DrawRectangleRec(warrior.rec, warrior.color);
	}

	void updatePlayer() {
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) warrior.rec.x += 2.5f;
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) warrior.rec.x -= 2.5f;
	}
}