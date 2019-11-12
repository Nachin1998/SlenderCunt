#pragma once
#include "raylib.h"

namespace Game {
	void parallax();

	extern Image foo;
	extern Image* asd;
	extern float scrollingBack;
	extern float scrollingMid;
	extern float scrollingFore;
	extern Texture2D background;
	extern Texture2D midground;
	extern Texture2D foreground;

	void init_parallax();
}
