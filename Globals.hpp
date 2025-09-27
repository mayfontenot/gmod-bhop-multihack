#pragma once
#include <Windows.h>
#include <thread>
#include <iostream>
#include "Vector.hpp"

using namespace std;

//module addresses
const unsigned long long CLIENT = (unsigned long long)GetModuleHandleA("client.dll");
const unsigned long long ENGINE = (unsigned long long)GetModuleHandleA("engine.dll");

//client addresses
const unsigned long long forceLeft = 0xA36938;
const unsigned long long forceRight = forceLeft + 0x10;
const unsigned long long forceJump = 0xA388F0;
const unsigned long long m_vecAbsVelocity = 0x86D110;
const unsigned long long m_hLocalPlayer = 0x9497F0;

//engine addresses
const unsigned long long m_angAbsRotation = 0x6581FC;

//offsets
const unsigned long long m_fFlags = 0x440;

//constant globals
const int CON_B_RANDOMIZER = 0, CON_B_AUTOHOP = 1, CON_B_AUTOSTRAFE = 2, CON_B_OPTIMIZER = 3, CON_B_COUNT = 4;
const int FL_ONGROUND = (1 << 0);
const float PI = atan(1.f) * 4.f;

//globals
bool conBools[CON_B_COUNT] = {true, false, true, false};