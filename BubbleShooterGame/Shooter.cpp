#include "Shooter.h"
extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;

int Shooter::score(int timeconst, int num)
// num = so luong bong
{
	if (num == 3 || num == 4)
	{
		m_score = 1 * num * timeconst;
	}
	else if (num >= 5)
	{
		m_score = 2 * num * timeconst;
	}
	return m_score;
}

void Shooter::checkBubble(LinkedList<Bubble>& templist, Bubble& temp,int row, int col, int& count)
{
	if ((row < BUBBLE_ROW_BEGIN) || (row > BUBBLE_ROW_END) || (col < BUBBLE_COLUMN_BEGIN) || (col > BUBBLE_COLUMN_END)) return;
	Bubble tmp(row, col, temp.getColor());
	LinkedList<Bubble>::Iterator pointptr = bubbleList.find(tmp);
	if (pointptr != bubbleList.end())
	{
		templist.push_back(Bubble(*pointptr));
		bubbleList.remove(pointptr);
		count++;

		checkBubble(templist, temp, row + 1, col, count);
		checkBubble(templist, temp, row - 1, col, count);
		checkBubble(templist, temp, row, col + 1, count);
		checkBubble(templist, temp, row, col - 1, count);
	}
	return;
};

void Shooter::shooting()
{
	Bubble temp(m_shootingpoint->getXY(), m_shootingpoint->getColor());

	//shooter changes color after shot
	this->changeColor();

	//get the column position that the player shot
	int col = m_shootingpoint->getXY().getY();

	//bubble up moving-loop
	for (int row = BUBBLE_ROW_END; row >= BUBBLE_ROW_BEGIN; row--)
	{
		LinkedList<Bubble>::Iterator pointptr = bubbleList.begin();
		for (; pointptr != bubbleList.end(); pointptr++)
		{
			if (*pointptr == Point(row - 1, col, BUBBLE)) break;
		}

		//check if the bubble has reached the final position or not
		if ((pointptr != bubbleList.end())|| (row == BUBBLE_ROW_BEGIN))
		{
			//"count" to check the number of bubbles that were hit
			int count = 1;

			//"templist" is list of bubbles that were hit
			LinkedList<Bubble> templist;

			templist.push_back(temp);		

			checkBubble(templist, temp, row - 1, col, count);
			checkBubble(templist, temp, row, col + 1, count);
			checkBubble(templist, temp, row, col - 1, count);

			if (count >= 3)
			{
				m_score += score(1, count);
				while (templist.begin() != templist.end())
				{
					templist.pop_front().eraser();
				}
			}
			else
			{
				while (templist.begin() != templist.end())
				{
					bubbleList.push_back(templist.pop_front());
				}
			}
			break;
		}
		else
			temp.up();
		bubbleList.push_back(temp);
	}
};


void Shooter::changeColor()
{
	Bubble* temp =  m_shootingpoint;
	m_shootingpoint = new Bubble(temp->getXY());
	delete temp;
	m_shootingpoint->draw();
};

void Shooter::left()
{
	m_shootingpoint->left();
};

void Shooter::right()
{
	m_shootingpoint->right();
};
void Shooter::draw()
{
	m_shootingpoint->draw();
}
Shooter::Shooter()
{
	m_shootingpoint = new Bubble(SHOOTER_X, SHOOTER_Y);
	m_shootingpoint->draw();
}

Shooter::~Shooter()
{

}