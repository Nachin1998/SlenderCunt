#include "player.h"
#include "enemy.h"
namespace Game {
	Warrior warrior;

	struct HealthBar {
		Rectangle rec;
		Color color;
	}healthBar;

	struct StaminaBar {
		Rectangle rec;
		Color color;
	}staminaBar;

	void initPlayer() {
		warrior.rec.height = 20;
		warrior.rec.width = 20;
		warrior.rec.x = 100;
		warrior.rec.y = 400 - warrior.rec.height;
		warrior.color = BLACK;

		healthBar.rec.x = 20;
		healthBar.rec.y = 20;
		healthBar.rec.height = 15;
		healthBar.rec.width = 200;
		healthBar.color = RED;

		staminaBar.rec.x = 20;
		staminaBar.rec.y = 35;
		staminaBar.rec.height = 15;
		staminaBar.rec.width = 150;

	}

	void drawPlayer() {
		DrawRectangleRec(warrior.rec, warrior.color);

		DrawRectangleRec(healthBar.rec, healthBar.color);
		DrawRectangleLines(healthBar.rec.x, healthBar.rec.y, 200, healthBar.rec.height, BLACK);
	
		DrawRectangleRec(staminaBar.rec, GREEN);
		DrawRectangleLines(staminaBar.rec.x, staminaBar.rec.y, staminaBar.rec.width, staminaBar.rec.height, BLACK);
	}

	void updatePlayer() {
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) warrior.rec.x += 2.5f;
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) warrior.rec.x -= 2.5f;
		
		if (CheckCollisionRecs(warrior.rec, enemy.rec)) {
			enemy.color = BLUE;
			healthBar.rec.width -= 3;
		}
		else enemy.color = RED;
	}
}