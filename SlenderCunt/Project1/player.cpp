#include "player.h"
#include "enemy.h"
#include "game.h"
#include "definitions.h"
#include <iostream>

namespace Game {
	float knockback = 10.f;
	void attack();
	void jump();

	Warrior warrior;
	Rectangle normalAttackArea;
	Rectangle AOIattackArea;

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

		normalAttackArea.x = warrior.rec.x;
		normalAttackArea.y = warrior.rec.y + 30;
		normalAttackArea.height = 20;
		normalAttackArea.width = 80;

		AOIattackArea.x = warrior.rec.x - 14.3f;
		AOIattackArea.y = warrior.rec.y + 15;
		AOIattackArea.height = 50;
		AOIattackArea.width = 50;
	}

	void drawPlayer() {
		DrawRectangleRec(warrior.rec, warrior.color);

		DrawRectangleRec(healthBar.rec, healthBar.color);
		DrawRectangleLines(healthBar.rec.x, healthBar.rec.y, 200, healthBar.rec.height, WHITE);

		DrawRectangleRec(staminaBar.rec, GREEN);
		DrawRectangleLines(staminaBar.rec.x, staminaBar.rec.y, staminaBar.rec.width, staminaBar.rec.height, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			DrawRectangleLinesEx(normalAttackArea, 4, RED);

		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
			DrawRectangleLinesEx(AOIattackArea, 4, GREEN);
	}

	void updatePlayer() {
		if (IsKeyDown(KEY_D)) {
			warrior.aim = true;
			knockback *= 3;
		}
		else
			knockback = 10.0f;
		if (IsKeyDown(KEY_A)) {
			warrior.aim = false;
			knockback *= 3;
		}
		else
			knockback = 10.0f;


		if (warrior.aim) {
			normalAttackArea.x = warrior.rec.x + 20;
			normalAttackArea.y = warrior.rec.y;
		}
		else {
			normalAttackArea.x = warrior.rec.x - 80;
			normalAttackArea.y = warrior.rec.y;
		}

		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			AOIattackArea.x -= 0.5f;
			AOIattackArea.width += 1;
			AOIattackArea.y -= 0.5f;
			AOIattackArea.height += 1;
		}
		else 
		{
			attack();
			AOIattackArea.x = warrior.rec.x - 13;
			AOIattackArea.y = warrior.rec.y - 15;
			AOIattackArea.height = 50;
			AOIattackArea.width = 50;
		}

		healthBar.rec.width = warrior.health;

		gravity(warrior.rec);
		jump();
		attack();
	}

	void attack() {
		for (int i = 0; i < cantSlimes; i++) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(normalAttackArea, slime[i].rec)) {
				slime[i].color = RAYWHITE;
				slime[i].health -= warrior.attackDamage;
				slime[i].rec.x += knockback;
			}
			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON) && CheckCollisionRecs(AOIattackArea, slime[i].rec)) {
				slime[i].color = RAYWHITE;
				slime[i].health -= warrior.attackDamage;
				slime[i].rec.x += knockback;
			}

		}
	}

	void jump() {
		if (IsKeyPressed(KEY_SPACE) && !gameOver && touchingFloor) {
			bool jumping = true;
			if (jumping)warrior.rec.y--;
		}
	}
}