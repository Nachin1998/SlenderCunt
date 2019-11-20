#ifndef PLATFORMS_H
#define	PLATFORMS_H
#include "raylib.h"
namespace Game {
	struct Floor {
		Rectangle rec;
		Color color;
	};

	const int maxPlatform = 3;
	void initFloor();
	void initPlatforms();
	void drawFloor();
	void drawPlatforms();
	void updatePlatforms();

	extern Floor floor;
	extern Floor platform[maxPlatform];
}
#endif
