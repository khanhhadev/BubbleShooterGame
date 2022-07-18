#include "GameInterface.h"
#include <time.h>
#include <Windows.h>
//#include "Graphic.h"
extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;
extern Shooter myShooter;
extern bool shootingCheck;

void SetScreen(int x, int y);
void hidecursor(void);
//delay function
void delay(int a)
{
	int add = 0;
	int time;
	int i;

	// delay time increasing speed changing
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
			if ((row == SCREEN_ROW_BEGIN) || (row == (SCREEN_ROW_END)))
			{
				Point temp(row, col, HORIZONTAL);
				temp.draw();
			}
		}
	}

	//initailize shooter object
	myShooter = Shooter();
}

GameInterface::~GameInterface()
{

}


void GameInterface::createBubble()
{
	int timecon = 5000; //ms
	while (true)
	{
		while (shootingCheck) {};
		//srand((int)time(0));
		if (timecon > 2000) timecon -= 100;
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
		Sleep(timecon);
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
void GameInterface::bubbleSort(LinkedList<Bubble> list)
{
	for (LinkedList<Bubble>::Iterator iterator1 = list.begin();
		iterator1 != list.rbegin(); iterator1++)
	{
		for (LinkedList<Bubble>::Iterator iterator2 = iterator1 + 1;
			iterator2 != list.end(); iterator2++)
		{
			if (*iterator1 < *iterator2) Bubble::swap(*iterator1, *iterator2);
		}
	}
}
