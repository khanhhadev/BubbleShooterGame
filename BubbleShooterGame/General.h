#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <string>
using namespace std;

#pragma once
//namespace Interface
//{
	#define MAX 300
	#define KEY_UP 72
	#define KEY_LEFT 75
	#define KEY_RIGHT 77
	#define KEY_X 120
	#define KEY_SPACE 32
	#define KEY_ESC 27
	//const int SCREEN_WIDTH = 15;

	const int SCREEN_LENGTH = 15;
	const int SCREEN_HEIGHT = 14;

	const int SHOOTER_X = 14;
	const int SHOOTER_Y = 28;


	const int SCREEN_ROW_BEGIN = 1;
	const int SCREEN_ROW_END = 15;

	const int SCREEN_COLUMN_BEGIN = 20;
	const int SCREEN_COLUMN_END = 35;

	//const int BUBBLE_RADIUS = 1;
	const int BUBBLE_ROW_BEGIN = 2;
	const int BUBBLE_ROW_END = 14;

	const int BUBBLE_COLUMN_BEGIN = 21;
	const int BUBBLE_COLUMN_END = 34;

	typedef enum CHARACTER {
		BUBBLE = 'o',
		HORIZONTAL = '-',
		VERTICAL = '|',
		ERASER = ' ',
		MULTI = 'x',
		HASHTAG = '#'
	};

	typedef enum MODE {
		PLAY,
		WAIT,
		LOSE, 
		EXIT
	};

	typedef enum PLAYMODE {
		SHOOTING,
		CREATING,
		NOTHING
	};
	typedef enum COLOR {
		BLACK = 7,
		RED = 12,
		GREEN = 10,
		BLUE = 1,
		YELLOW = 14,
		WHITE = 7
	};

//};

#endif // !GENERAL_H