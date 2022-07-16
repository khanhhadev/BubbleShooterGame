#pragma once
#include "LinkedList.h"
#include "Point.h"
#include "Bubble.h"
#include <iostream>
#include <string>
using namespace std;

LinkedList<Point> pointList;
LinkedList<Bubble> bubbleList;

namespace Interface
{
	const int SCRREN_WIDTH = 1;
	const int SCRREN_LENGTH = 1;
	const int SHOOTER_X = 0;
	const int SHOOTER_Y = SCRREN_WIDTH/2;
	const int BUBBLE_RADIUS = 1;
	const int BUBBLE_ROW = 1;
	const int BUBBLE_COLUMN = 1;

	const char POINT = 254;


	enum COLOR {
		RED = 1,
		GREEN,
		YELLOW,
	};
}