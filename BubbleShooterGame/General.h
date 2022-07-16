#pragma once
#include "LinkedList.h"
#include "Point.h"
#include "Bubble.h"
#include <iostream>
#include <string>
using namespace std;

extern LinkedList<Point> pointList;
extern LinkedList<Bubble> bubbleList;

namespace Interface
{
	const int SCREEN_WIDTH = 1;
	const int SCREEN_LENGTH = 1;

	const int SCREEN_HEIGHT = 1;
	const int SHOOTER_X = 0;
	const int SHOOTER_Y = SCREEN_WIDTH/2;
	const int BUBBLE_RADIUS = 1;
	const int BUBBLE_ROW = 1;
	const int BUBBLE_COLUMN = 1;

	const char POINT = 254;


	enum COLOR {
		BLACK = 16,
		RED = 12,
		GREEN = 10,
		YELLOW = 14,
		WHITE = 7
	};
}