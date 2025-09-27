#pragma once
#include "Globals.hpp"

void AutohopThread()
{
	srand(time(NULL));

	while (!GetAsyncKeyState(VK_END))
	{
		if (!conBools[CON_B_AUTOHOP] || !GetAsyncKeyState(VK_SPACE)) //skip iteration if not active
			continue;

		unsigned long long hLocalPlayer = *(unsigned long long*)(CLIENT + m_hLocalPlayer);

		if (*(int*)(CLIENT + forceJump) == 5 && !(*(int*)(hLocalPlayer + m_fFlags) & FL_ONGROUND))
			*(int*)(CLIENT + forceJump) = 4; //4 releases, 5 presses
		else if (*(int*)(CLIENT + forceJump) == 4 && *(int*)(hLocalPlayer + m_fFlags) & FL_ONGROUND)
			*(int*)(CLIENT + forceJump) = 5;

		this_thread::sleep_for(chrono::milliseconds(conBools[CON_B_RANDOMIZER] ? 10 + rand() % 15 : 1));
	}
}