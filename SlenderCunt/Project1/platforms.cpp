#include "platforms.h"
#include "definitions.h"
namespace Game {
	Floor floor;
	Floor platform[maxPlatform];
	void initFloor(){
		floor.rec.x = 0;
		floor.rec.y = screenHeight - 10;
		floor.rec.height = 10;
		floor.rec.width = screenWidth;
		floor.color = BLACK;
	}

	void drawFloor() {
		//DrawRectangleRec(floor.rec, floor.color);
	}

	void initPlatforms() {
		for (int i = 0; i < maxPlatform; i++) {
			platform[i].rec.height = 10;
			platform[i].rec.width = 100;
			platform[i].color = YELLOW;
		}
		platform[0].rec.x = screenWidth / 2;
		platform[0].rec.y = screenHeight / 2;
		platform[1].rec.x = screenWidth/1.5f;
		platform[1].rec.y = screenHeight/1.5f;
		platform[2].rec.x = screenWidth/1.2f;
		platform[2].rec.y = screenHeight/1.2f;
	}

	void drawPlatforms() {
		for (int i = 0; i < maxPlatform; i++) {
			DrawRectangleRec(platform[i].rec, platform[i].color);
		}
	}

	void updatePlatforms() {
		for (int i = 0; i < maxPlatform; i++) {
			if (platform[i].rec.x < 0 - platform[i].rec.width){
				platform[i].rec.x = screenWidth;
			}

			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) platform[i].rec.x -= 2.5f;
			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))  platform[i].rec.x += 2.5f;
		}
	}
}