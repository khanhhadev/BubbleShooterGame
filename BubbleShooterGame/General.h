#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <string>
using namespace std;

#pragma once
//namespace Interface
//{
	//const int SCREEN_WIDTH = 15;
	const int SCREEN_LENGTH = 15;
	const int SCREEN_HEIGHT = 14;

	const int SHOOTER_X = 14;
	const int SHOOTER_Y = 38;


	const int SCREEN_ROW_BEGIN = 1;
	const int SCREEN_ROW_END = 15;

	const int SCREEN_COLUMN_BEGIN = 30;
	const int SCREEN_COLUMN_END = 45;

	//const int BUBBLE_RADIUS = 1;
	const int BUBBLE_ROW_BEGIN = 2;
	const int BUBBLE_ROW_END = 9;

	const int BUBBLE_COLUMN_BEGIN = 31;
	const int BUBBLE_COLUMN_END = 44;

	typedef enum CHARACTER {
		BUBBLE = 'o',
		HORIZONTAL = '+',
		VERTICAL = '+',
		ERASER = ' '
	};


	typedef enum COLOR {
		BLACK = 16,
		RED = 12,
		GREEN = 10,
		YELLOW = 14,
		WHITE = 7
	};
//};

#endif // !GENERAL_H