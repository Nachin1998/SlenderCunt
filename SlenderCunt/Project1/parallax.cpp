#include "parallax.h"

void parallax()
{
	// Initialization
//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 920;

	InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");

	// NOTE: Be careful, background width must be equal or bigger than screen width
	// if not, texture should be draw more than two times for scrolling effect
	

	Image foo = LoadImage("../res/B1.png");
	Image* asd = &foo;


	ImageResize(asd, 512, 192);
	
	

	Texture2D background = LoadTextureFromImage(foo);

	UnloadImage(foo);
	
	foo = LoadImage("../res/M1.png");
	asd = &foo;

	ImageResize(asd, 512, 192);


	Texture2D midground = LoadTextureFromImage (foo);
	
	UnloadImage(foo);

	foo = LoadImage("../res/F1.png");
	asd = &foo;

	ImageResize(asd, 512, 192);


	Texture2D foreground = LoadTextureFromImage(foo);

	UnloadImage(foo);

	float scrollingBack = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingFore = 0.0f;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		scrollingBack -= 0.1f;
		scrollingMid -= 0.5f;
		scrollingFore -= 1.0f;

		// NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
		if (scrollingBack <= -background.width * 2) scrollingBack = 0;
		if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
		if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GetColor(0x052c46ff));

		// Draw background image twice
		// NOTE: Texture is scaled twice its size
		DrawTextureEx(background, { scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(background, { background.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

		// Draw midground image twice
		DrawTextureEx(midground, { scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midground, { midground.width * 2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

		// Draw foreground image twice
		DrawTextureEx(foreground, { scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(foreground, { foreground.width * 2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);

		DrawText("BACKGROUND SCROLLING & PARALLAX", 10, 10, 20, RED);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	UnloadTexture(background);  // Unload background texture
	UnloadTexture(midground);   // Unload midground texture
	UnloadTexture(foreground);  // Unload foreground texture

	CloseWindow();              // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

}