#include "player.h"
#include "enemy.h"
#include "game.h"
#include "definitions.h"
#include <iostream>

namespace Game {
	float knockback = 10.f;
	float staminaRegen = 0.1f;

	void initPlayer();
	void initHealthBar();
	void initStaminaBar();
	void initAOI();
	void initMelee();
	void meleeUpdate();
	void meleeAttack();
	void AOIattack();
	void AOIUpdate();
	void jump();

	Warrior warrior;
	Rectangle meleeAttackArea;
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

		initHealthBar();
		initStaminaBar();
		initMelee();
		initAOI();
	}

	void initHealthBar() {
		healthBar.rec.x = 20;
		healthBar.rec.y = 20;
		healthBar.rec.height = 15;
		healthBar.rec.width = warrior.health;
		healthBar.color = RED;
	}

	void initStaminaBar() {
		staminaBar.rec.x = 20;
		staminaBar.rec.y = 35;
		staminaBar.rec.height = 15;
		staminaBar.rec.width = 150;
		staminaBar.color = GREEN;
	}

	void initMelee() {
		meleeAttackArea.x = warrior.rec.x;
		meleeAttackArea.y = warrior.rec.y + 30;
		meleeAttackArea.height = 20;
		meleeAttackArea.width = 80;
	}

	void drawPlayer() {
		DrawRectangleRec(warrior.rec, warrior.color);

		DrawRectangleRec(healthBar.rec, healthBar.color);
		DrawRectangleLines(healthBar.rec.x, healthBar.rec.y, 200, healthBar.rec.height, WHITE);
		DrawRectangleRec(staminaBar.rec, staminaBar.color);

		DrawRectangleLines(staminaBar.rec.x, staminaBar.rec.y, 150, staminaBar.rec.height, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			DrawRectangleLinesEx(meleeAttackArea, 4, RED);

		if (staminaBar.rec.width > 25) {
			if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
				DrawRectangleLinesEx(AOIattackArea, 4, GREEN);
		}

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

		healthBar.rec.width = warrior.health;

		gravity(warrior.rec);
		jump();
		meleeUpdate();
		AOIUpdate();
	}

	void meleeAttack() {
		for (int i = 0; i < cantSlimes; i++) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionRecs(meleeAttackArea, slime[i].rec)) {
				slime[i].color = RAYWHITE;
				slime[i].health -= warrior.attackDamage;
				slime[i].rec.x += knockback;
			}
		}
	}
	
	void meleeUpdate() {
		meleeAttack();
		if (warrior.aim) {
			meleeAttackArea.x = warrior.rec.x + 20;
			meleeAttackArea.y = warrior.rec.y;
		}
		else {
			meleeAttackArea.x = warrior.rec.x - 80;
			meleeAttackArea.y = warrior.rec.y;
		}
	}

	void initAOI() {
		AOIattackArea.x = warrior.rec.x - 14.3f;
		AOIattackArea.y = warrior.rec.y;
		AOIattackArea.height = 50;
		AOIattackArea.width = 50;
	}
	
	void AOIattack() {
		for (int i = 0; i < cantSlimes; i++) {
			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON) && CheckCollisionRecs(AOIattackArea, slime[i].rec)) {
				slime[i].color = GREEN;
				slime[i].rec.x += AOIattackArea.width;
			}
		}
		for (int i = 0; i < cantSlimes; i++) {
			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON) && CheckCollisionRecs(AOIattackArea, medusa[i].rec)) {
				medusa[i].rec.x += AOIattackArea.width;
			}
		}
	}

	void AOIUpdate() {
		
		if (staminaBar.rec.width > 25) {
			staminaBar.color = GREEN;
			AOIattack();
			if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
				if (AOIattackArea.height < 200 && AOIattackArea.width < 200) {

					AOIattackArea.x -= 0.5f;
					AOIattackArea.width += 1;
					AOIattackArea.y -= 0.5f;
					AOIattackArea.height += 1;
				}
			}

			if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
				if (AOIattackArea.width >= 50 && AOIattackArea.width <= 100)
					staminaBar.rec.width -= 10;

				if (AOIattackArea.width >= 100 && AOIattackArea.width <= 150)
					staminaBar.rec.width -= 25;

				if (AOIattackArea.width >= 150 && AOIattackArea.width <= 200)
					staminaBar.rec.width -= 40;
			}

			if (!IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
				AOIattackArea.x = warrior.rec.x - 14.3f;
				AOIattackArea.y = warrior.rec.y;
				AOIattackArea.height = 50;
				AOIattackArea.width = 50;
			}
		}
		else
			staminaBar.color = BLUE;

		if (staminaBar.rec.width <= 0)staminaBar.rec.width = 0;
		if (staminaBar.rec.width < 150)staminaBar.rec.width += staminaRegen;
	}

	void jump() {
		if (IsKeyPressed(KEY_SPACE) && !gameOver && touchingFloor) {
			bool jumping = true;
			if (jumping)warrior.rec.y--;
		}
	}
}