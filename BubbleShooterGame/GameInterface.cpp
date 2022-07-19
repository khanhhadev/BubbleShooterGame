#include "GameInterface.h"
#include <time.h>
#include <Windows.h>
#include "Display.h"

extern MODE mymode;
extern PLAYMODE myplay;
extern LinkedList<Bubble> bubbleList;

//void SetScreen(int x, int y);
//void hidecursor(void);
//delay function
//void delay(int a)
//{
//	int add = 0;
//	int time;
//	int i;
//
//	// delay time increasing speed changing
//	time = a * 1000000;
//	for (i = 0; i < time; i++)
//	{
//		add *= i;
//		add++;
//		add++;
//	}
//}

GameInterface::GameInterface()
{
	system("cls");
	hidecursor();
	drawWall();
	drawDScore();
	displayScore(0);
}

GameInterface::~GameInterface()
{

}


void GameInterface::createBubble()
{
	int timecon = 3500; //ms
	while (mymode == PLAY)
	{
		while (myplay == SHOOTING) {};
		myplay = CREATING;

		Bubble::bubbleSort(bubbleList);
		if (timecon > 1000) timecon -= 100; 

		LinkedList<Bubble>::Iterator itr = bubbleList.begin();

		if (bubbleList.size() > 0)
		{
			if ((*itr).getX() == BUBBLE_ROW_END)
			{
				myplay = NOTHING;
				mymode = LOSE;
				return;
			}
		}

		for (; itr != bubbleList.end(); itr++)
		{
			(*itr).down();
		};

		for (int col = BUBBLE_COLUMN_END; col >= BUBBLE_COLUMN_BEGIN; col--)
		{
			Bubble temp(2, col);
			temp.draw();
			bubbleList.push_back(temp);
			//delete temp;
		}
		myplay = NOTHING;
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

