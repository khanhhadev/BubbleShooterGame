#include "GameInterface.h"
using namespace Interface;

GameInterface::GameInterface()
{
	for (int row = 1; row <= SCREEN_HEIGHT; row++)
	{
		for (int col = 1;col <= SCREEN_LENGTH; col++)
		{
			if ((row == 1)||(row == (SCREEN_HEIGHT))) pointList.push_back(Point(row, col));
		}
	}
}

GameInterface::~GameInterface()
{
}

ostream& operator<< (ostream& output, LinkedList<Point>& m_point)
{
	for (LinkedList<Point>::Iterator point = m_point.begin();
		point != m_point.rbegin(); point++)
	{
		//*iterator la Point
		//(* iterator1).getX
	}
}


//sort list of Point
void GameInterface::bubbleSort(LinkedList<Point> m_point)
{
	for (LinkedList<Point>::Iterator iterator1 = m_point.begin();
		iterator1 != m_point.rbegin(); iterator1++)
	{
		for (LinkedList<Point>::Iterator iterator2 = iterator1 + 1;
			iterator2 != m_point.end(); iterator2++)
		{
			if (*iterator1 > *iterator2) Point::swap(*iterator1, *iterator2);
		}
	}
}
