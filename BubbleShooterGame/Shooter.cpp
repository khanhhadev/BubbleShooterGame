#include "Shooter.h"

extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;

int Shooter::score(int timeconst, int num)
// num = so luong bong
{
	int a;  // so diem
	int score;
	if (num == 3 || num == 4)
	{
		a = 1 * num * timeconst;
	}
	else if (num >= 5)
	{
		a = 2 * num * timeconst;
	}
	score = a;
	return score;
}

void Shooter::checkBubble(LinkedList<Bubble>& bubblelist, int row, int col, int& count)
{
	if ((row < BUBBLE_ROW_BEGIN) || (col < BUBBLE_COLUMN_BEGIN) || (col > BUBBLE_COLUMN_END)) return;

	LinkedList<Bubble>::Iterator pointptr = bubblelist.find(Bubble(row, col, m_bubblecolor));
	if (pointptr != bubblelist.end())
	{
		count++;
		checkBubble(bubblelist, row - 1, col, count);
		checkBubble(bubblelist, row, col + 1, count);
		checkBubble(bubblelist, row, col - 1, count);
		if (count >= 3) bubblelist.remove(pointptr);
	}
	return;
};

void Shooter::shooting(LinkedList<Bubble>& bubblelist, int col)
{
	int currentrow = 5;
	for (int row = currentrow; row >= 0; row--)
	{
		int count = 0;
		checkBubble(bubblelist, row, col, count);
		if (count >= 3) m_score += score(1, count);
		return;
	} 
};


void Shooter::changeColor()
{
	Bubble* temp =  m_shootingpoint;
	m_shootingpoint = new Bubble(temp->getXY());
	delete temp;
};

Shooter::Shooter()
{
	m_shootingpoint = new Bubble(SHOOTER_X, SHOOTER_Y);
}

Shooter::~Shooter()
{

}