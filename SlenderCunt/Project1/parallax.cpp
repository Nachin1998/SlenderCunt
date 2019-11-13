#include "parallax.h"
#include "definitions.h"

namespace Game {

	Image aux;
	Image* ptr;
	float scrollingBack;
	float scrollingMid;
	float scrollingFore;
	Texture2D background;
	Texture2D midground;
	Texture2D foreground;

	void init_parallax()
	{
		aux = LoadImage("../res/BackGround.png");
		ptr = &aux;

		ImageResize(ptr, screenWidth * 2, screenHeight);


		background = LoadTextureFromImage(aux);

		UnloadImage(aux);

		aux = LoadImage("../res/MiddleGround.png");
		ptr = &aux;

		ImageResize(ptr, screenWidth / 2, screenHeight / 2);

		midground = LoadTextureFromImage(aux);

		UnloadImage(aux);

		aux = LoadImage("../res/ForeGround.png");
		ptr = &aux;

		ImageResize(ptr, screenWidth, screenHeight / 1.8f);

		foreground = LoadTextureFromImage(aux);

		UnloadImage(aux);

		//--------------------------------------------------------------------------------------

	}
	void draw_parallax()
	{
		// Draw background image twice
		DrawTextureEx(background, { scrollingBack, 0 }, 0.0f, 1.0f, WHITE);
		DrawTextureEx(background, { background.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

		// Draw midground image twice
		DrawTextureEx(midground, { scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midground, { midground.width * 2 + scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

		// Draw foreground image twice
		DrawTextureEx(foreground, { scrollingFore, -20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(foreground, { foreground.width * 2 + scrollingFore, -20 }, 0.0f, 2.0f, WHITE);
	}
	void unload_parallax()
	{

		// De-Initialization
		//--------------------------------------------------------------------------------------
		UnloadTexture(background);  // Unload background texture
		UnloadTexture(midground);   // Unload midground texture
		UnloadTexture(foreground);  // Unload foreground texture

	}
	void update_parallax()
	{
		// Update
			//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_D))
		{
			scrollingBack -= 0.1f;
			scrollingMid -= 0.5f;
			scrollingFore -= 1.0f;
		}
		else if (IsKeyDown(KEY_A))
		{
			scrollingBack += 0.1f;
			scrollingMid += 0.5f;
			scrollingFore += 1.0f;
		}

		// NOTE: Texture is scaled twice its size, so it sould be considered on scrolling

		if (scrollingBack <= -background.width * 2) scrollingBack = 0;
		if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
		if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;

		if (scrollingBack >= 0) scrollingBack = 0;
		if (scrollingMid >= 0) scrollingMid = 0;
		if (scrollingFore >= 0) scrollingFore = 0;
	}
}