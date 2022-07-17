#include "GameInterface.h"
#include <mutex>

extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;
extern Shooter myShooter;
//ham delay thoi gian ma` minh muon
void delay(int a)
{
	int add = 0;
	int time;
	int i;

	// dieu chinh thoi gian delay o ben duoi
	time = a * 1000000;
	for (i = 0; i < time; i++)
	{
		add *= i;
		add++;
		add++;
	}
}
GameInterface::GameInterface()
{
	for (int row = SCREEN_ROW_BEGIN; row <= SCREEN_ROW_END; row++)
	{
		for (int col = SCREEN_COLUMN_BEGIN; col <= SCREEN_COLUMN_END; col++)
		{
			if ((col == SCREEN_COLUMN_BEGIN) || (col == (SCREEN_COLUMN_END)))
			{
				Point temp(row, col, VERTICAL);
				temp.draw();
			}
			//else
				if ((row == SCREEN_ROW_BEGIN) || (row == (SCREEN_ROW_END)))
				{
					Point temp(row, col, HORIZONTAL);
					temp.draw();
				}
		}
	}
	myShooter = Shooter();
	myShooter.draw();
}

GameInterface::~GameInterface()
{

}


void GameInterface::createBubble()
{
	int timecon = 5000; //ms
	while (true)
	{
		//if (timecon > 2000) timecon -= 100;
		srand((int)time(0));
		for (LinkedList<Bubble>::Iterator iterator = bubbleList.begin();
			iterator != bubbleList.end(); iterator++)
		{
			(*iterator).down();
		}
		for (int col = BUBBLE_COLUMN_BEGIN; col <= BUBBLE_COLUMN_END; col++)
		{
			Bubble temp(2, col);
			temp.draw();
			bubbleList.push_back(temp);
		}
		delay(timecon);
	}
};
ostream& operator<< (ostream& output, LinkedList<Point>& m_point)
{
	for (LinkedList<Point>::Iterator point = m_point.begin();
		point != m_point.rbegin(); point++)
	{
		//*iterator la Point
		//(* iterator1).getX
	}
	return output;
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
