#pragma once
#include <thread>
#include "Bubble.h"
#include "General.h"

void createBubbleRow()
{
	for (int i = 0; i < SCREEN_LENGTH; i++)
		Bubble();
}
