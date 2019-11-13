#include "player.h"
#include "enemy.h"
#include <iostream>

namespace Game {

	void attack();

	Warrior warrior;
	Rectangle attackArea;

	struct HealthBar {
		Rectangle rec;
		Color color;
	};
	HealthBar healthBar;

	struct StaminaBar {
		Rectangle rec;
		Color color;
	};
	StaminaBar staminaBar;


	void initPlayer() {
		warrior.health = 200.0;
		warrior.attackDamage = 15.0f;
		warrior.active = true;
		warrior.aim = true;
		warrior.rec.height = 40;
		warrior.rec.width = 20;
		warrior.rec.x = 100;
		warrior.rec.y = 400 - warrior.rec.height;
		warrior.color = GRAY;

		healthBar.rec.x = 20;
		healthBar.rec.y = 20;
		healthBar.rec.height = 15;
		healthBar.rec.width = warrior.health;
		healthBar.color = RED;

		staminaBar.rec.x = 20;
		staminaBar.rec.y = 35;
		staminaBar.rec.height = 15;
		staminaBar.rec.width = 150;

		attackArea.x = warrior.rec.x;
		attackArea.y = warrior.rec.y+30;
		attackArea.height =20;
		attackArea.width = 80;


	}

	void drawPlayer() {
		DrawRectangleRec(warrior.rec, warrior.color);

		DrawRectangleRec(healthBar.rec, healthBar.color);
		DrawRectangleLines(healthBar.rec.x, healthBar.rec.y, 200, healthBar.rec.height, WHITE);
	
		DrawRectangleRec(staminaBar.rec, GREEN);
		DrawRectangleLines(staminaBar.rec.x, staminaBar.rec.y, staminaBar.rec.width, staminaBar.rec.height, WHITE);
		
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			DrawRectangleLinesEx(attackArea, 4, RED);
	}

	void updatePlayer() {
		if (IsKeyDown(KEY_D)) warrior.aim = true;
		if (IsKeyDown(KEY_A)) warrior.aim = false;

		if (warrior.aim) {
			attackArea.x = warrior.rec.x+20;
			attackArea.y = warrior.rec.y;
		}
		else {
			attackArea.x = warrior.rec.x-80;
			attackArea.y = warrior.rec.y;
		}


		healthBar.rec.width = warrior.health;
		
		attack();
	}

	void attack() {
		for(int i = 0; i < cantSlimes; i++)
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(attackArea, slime[i].rec)) {
			slime[i].color = RAYWHITE;
			slime[i].health -= warrior.attackDamage;
		}
	}
}