#include "Shooter.h"

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

void Shooter::shooting(LinkedList<Bubble>& bubblelist, int col)
{
	int currentrow = 5;
	for (int row = currentrow; row >= 0; row--)
	{
		LinkedList<Point>::Iterator pointptr = m_point.find(Bubble(row, col));
		if (pointptr != m_point.end())
		{
			int bubbleCount = checkBubble(bubblelist, *pointptr);
		}
		return;
	} 
};


void Shooter::changeColor()
{
	delete m_shootingpoint;
	m_shootingpoint = new Bubble();
};

int Shooter::checkBubble(LinkedList<Bubble>& bubblelist, Bubble& Obj)
{
	int bubbleCount = 0;

};

Shooter::Shooter()
{

}

Shooter::~Shooter()
{

}