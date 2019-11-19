#include "mainMenu.h"

namespace Game {

	Vector2 mouse_pos;
	Rectangle buttons[CANT_REC];
	int rec_x = screenWidth / 2.5F;
	int rec_y = screenHeight / 2;
	bool credits = false;
	void init_rec()
	{
		for (int i = 0; i < CANT_REC; i++)
		{
			buttons[i].height = rec_height;
			buttons[i].width = rec_width;
			buttons[i].x = (float)rec_x;
			buttons[i].y = (float)rec_y;

			rec_y -= 45;
		}
	}

	void update_buttons()
	{
		for (int i = 0; i < CANT_REC; i++) {
			if (CheckCollisionPointRec(mouse_pos, buttons[i])) {
				DrawRectangleRec(buttons[i], GRAY);
				if (CheckCollisionPointRec(mouse_pos, buttons[2]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
				{
					ClearBackground(BLACK);
					DrawText("Loading", screenWidth / 3, screenHeight / 2, 50, RED);
					play();
				}
				if (CheckCollisionPointRec(mouse_pos, buttons[0]) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				{
					EndDrawing();
					CloseWindow();
				}
				if (CheckCollisionPointRec(mouse_pos, buttons[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					credits = !credits;
				}

			}
		}
	}
	void draw_buttons()
	{
		for (int i = 0; i < CANT_REC; i++) {
			if (CheckCollisionPointRec(mouse_pos, buttons[i]))
				DrawRectangleRec(buttons[i], GRAY);
			else
				DrawRectangleRec(buttons[i], BROWN);
		}
		
	}

	void menu() {
		InitWindow(screenWidth, screenHeight, "SlenderBoi");
		SetTargetFPS(60);
		init_rec();

		while (!WindowShouldClose())
		{
			mouse_pos = GetMousePosition();
			BeginDrawing();

			ClearBackground(BLACK);

			draw_buttons();
			update_buttons();
			DrawText("SlendiBoi", GetScreenWidth() / 3, screenHeight / 2 - 200, 50, LIGHTGRAY);

			DrawText("Exit", buttons[0].x, buttons[0].y, 20, LIGHTGRAY);
			DrawText("Start", buttons[2].x, buttons[2].y, 20, LIGHTGRAY);
			DrawText("Credits", buttons[1].x, buttons[1].y, 20, LIGHTGRAY);

			if (credits)
			{
				draw_credits();
			}

			DrawText("P to pause", GetScreenWidth() / 2 - 60, screenHeight / 2 + 200, 20, LIGHTGRAY);

			EndDrawing();

		}
	}
}