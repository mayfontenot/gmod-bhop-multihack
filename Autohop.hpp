#pragma once
#include "Globals.hpp"

void AutohopThread()
{
	srand(time(NULL));

	while (!GetAsyncKeyState(VK_END))
	{
		unsigned long long hLocalPlayer = *(unsigned long long*)(MOD_CLIENT + ADDR_LOCALPLAYER);
		int* flags = (int*)(hLocalPlayer + OFFSET_FLAGS);
		int* forceJump = (int*)(MOD_CLIENT + ADDR_FORCE_JUMP);

		if (conBools[CON_B_AUTOHOP] && GetAsyncKeyState(VK_SPACE)) //skip iteration if not active
			if (*forceJump == 5 && !(*flags & FL_ONGROUND))
				*forceJump = 4; //4 releases, 5 presses
			else if (*forceJump == 4 && *flags & FL_ONGROUND)
				*forceJump = 5;

		this_thread::sleep_for(chrono::milliseconds(conBools[CON_B_RANDOMIZER] ? 5 + rand() % 15 : 1));
	}
}