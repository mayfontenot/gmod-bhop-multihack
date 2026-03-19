#pragma once
#include "Globals.hpp"

float NormalizeAngle(float ang)
{
    if (isnan(ang) || isinf(ang))
        ang = 0;

	while (ang > 180)
		ang -= 360;

	while (ang < -180)
		ang += 360;

	return ang;
}

void OptimizerThread()
{
	while (!GetAsyncKeyState(VK_END))
	{
		if (!GetAsyncKeyState(VK_XBUTTON2) || !conBools[CON_B_OPTIMIZER]) //skip loop iteration if not active
			continue;

		float yaw = *(float*)(MOD_ENGINE + ADDR_ABS_ROTATION + 0x4); //base is pitch, + 0x4 is yaw because a float is 4 bytes
		Vector vel = *(Vector*)(MOD_CLIENT + ADDR_ABS_VELOCITY);

		float idealYaw = atan2(vel.y, vel.x) * (180.f / PI);
		float delta = yaw - idealYaw;

        *(float*)(MOD_ENGINE + ADDR_ABS_ROTATION + 0x4) = NormalizeAngle(yaw - delta); //set yaw towards idealYaw
	}
}