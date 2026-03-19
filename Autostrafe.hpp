#pragma once
#include "Globals.hpp"

void AutostrafeThread()
{
	RECT screen;
	POINT cursor;
	bool runOnce = false;

	srand(time(NULL));

	while (!GetAsyncKeyState(VK_END))
	{
		bool* forceLeft = (bool*)(MOD_CLIENT + ADDR_FORCE_LEFT);
		bool* forceRight = (bool*)(MOD_CLIENT + ADDR_FORCE_RIGHT);

		if (conBools[CON_B_AUTOSTRAFE] && GetAsyncKeyState(VK_XBUTTON2)) //if not active, then skip iteration and reset movement (only once)
		{
			GetWindowRect(GetForegroundWindow(), &screen);
			GetCursorPos(&cursor);

			if (cursor.x < screen.right / 2)
				*forceLeft = !(*forceRight = false);
			else if (cursor.x > screen.right / 2)
				*forceRight = !(*forceLeft = false);

			runOnce = true;
		}
		else if (runOnce)
			runOnce = *forceLeft = *forceRight = false;

		this_thread::sleep_for(chrono::milliseconds(conBools[CON_B_RANDOMIZER] ? 5 + rand() % 15 : 1));
	}
}