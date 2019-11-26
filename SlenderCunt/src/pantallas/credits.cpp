#include "credits.h"

namespace Game {
	void draw_credits()
	{
		DrawText("Parallax", GetScreenHeight() / 2,GetScreenWidth() / 2, 50, RED);
	}
}