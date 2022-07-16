#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <string>
using namespace std;

#pragma once
//namespace Interface
//{
	const int SCREEN_WIDTH = 1;
	const int SCREEN_LENGTH = 1;
	const int SCREEN_HEIGHT = 1;

	const int SHOOTER_X = 0;
	const int SHOOTER_Y = SCREEN_WIDTH / 2;

	const int BUBBLE_RADIUS = 1;
	const int BUBBLE_ROW = 1;
	const int BUBBLE_COLUMN = 1;

	const char POINT = 254;


	typedef enum COLOR {
		BLACK = 16,
		RED = 12,
		GREEN = 10,
		YELLOW = 14,
		WHITE = 7
	};
//};

#endif // !GENERAL_H