#include "Shooter.h"

extern LinkedList<Bubble> bubbleList;
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
		LinkedList<Bubble>::Iterator pointptr = bubblelist.find(Bubble(row, col, m_bubblecolor));
		if (pointptr != bubblelist.end())
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
	m_bubblecolor = m_shootingpoint->getColor();
};

int Shooter::checkBubble(LinkedList<Bubble>& bubblelist, Bubble& Obj)
{
	int bubbleCount = 0;
	return bubbleCount;
};

Shooter::Shooter()
{
	m_shootingpoint = new Bubble();
	m_bubblecolor = m_shootingpoint->getColor();
	bubbleList.push_back(*m_shootingpoint);
}

Shooter::~Shooter()
{

}