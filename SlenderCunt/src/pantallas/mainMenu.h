#ifndef MAINMENU_H
#define MAINMENU_H
#include "raylib.h"
#include "Source.h"
#include "definitions.h"
#include "credits.h"
namespace Game {
	void menu();
	const int CANT_REC = 3;
	const int rec_height = 25;
	const int rec_width = 100;
	extern bool credits;
}
#endif