#include "parallax.h"

void parallax()
{
	// Initialization
//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");

	// NOTE: Be careful, background width must be equal or bigger than screen width
	// if not, texture should be draw more than two times for scrolling effect


	Image foo;
	Image* asd;

	foo = LoadImage("../res/BackGround.png");
	asd = &foo;

	ImageResize(asd, screenWidth * 2, screenHeight);


	Texture2D background = LoadTextureFromImage(foo);

	UnloadImage(foo);

	foo = LoadImage("../res/MiddleGround.png");
	asd = &foo;

	ImageResize(asd, screenWidth / 2, screenHeight / 2);

	Texture2D midground = LoadTextureFromImage(foo);

	UnloadImage(foo);

	foo = LoadImage("../res/ForeGround.png");
	asd = &foo;

	ImageResize(asd, screenWidth, screenHeight / 1.8f);

	Texture2D foreground = LoadTextureFromImage(foo);
	//Texture2D foreground = LoadTexture("../res/ForeGround.png");

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
		if (IsKeyDown(KEY_D))
		{
			scrollingBack -= 0.1f;
			scrollingMid -= 0.5f;
			scrollingFore -= 1.0f;
		}
		else if (IsKeyDown(KEY_A))
		{
			scrollingBack += 0.1f;
			scrollingMid  += 0.5f;
			scrollingFore += 1.0f;
		}
		// NOTE: Texture is scaled twice its size, so it sould be considered on scrolling

		if (scrollingBack <= -background.width * 2) scrollingBack = 0;
		if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
		//if (scrollingFore <= -foreground.width * 2) scrollingFore = 0;

		if (scrollingBack >= 0) scrollingBack = 0;
		if (scrollingMid >= 0) scrollingMid = 0;
		if (scrollingFore >= 0) scrollingFore = 0;

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GetColor(0x052c46ff));

		// NOTE: Texture is scaled twice its size
		// Draw background image twice
		DrawTextureEx(background, { scrollingBack, 0 }, 0.0f, 1.0f, WHITE);
		DrawTextureEx(background, { background.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

		// Draw midground image twice
		DrawTextureEx(midground, { scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midground, { midground.width * 2 + scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

		// Draw foreground image twice
		DrawTextureEx(foreground, { scrollingFore, -20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(foreground, { foreground.width * 2 + scrollingFore, -20 }, 0.0f, 2.0f, WHITE);



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