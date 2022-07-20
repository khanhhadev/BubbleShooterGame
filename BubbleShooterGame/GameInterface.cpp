#include "GameInterface.h"
#include <time.h>
#include <Windows.h>
#include "Display.h"

extern MODE mymode;
extern PLAYMODE myplay;
extern LinkedList<Bubble> bubbleList;

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

//create new bubble row
void GameInterface::createBubble()
{
	int timecon = 5000; //ms
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

		//shift bubble down
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

