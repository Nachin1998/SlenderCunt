#pragma once
#include "raylib.h"

namespace Game {

	extern Image aux;
	extern Image* ptr;
	extern float scrollingBack;
	extern float scrollingMid;
	extern float scrollingFore;
	extern Texture2D background;
	extern Texture2D midground;
	extern Texture2D foreground;

	void init_parallax();
	void draw_parallax();
	void update_parallax();
	void unload_parallax();
}
