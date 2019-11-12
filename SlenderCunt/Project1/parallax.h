#pragma once
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

extern Image foo;
extern Image* asd;
extern float scrollingBack;
extern float scrollingMid ;
extern float scrollingFore;
extern Texture2D background;
extern Texture2D midground;
extern Texture2D foreground;

void init_parallax();