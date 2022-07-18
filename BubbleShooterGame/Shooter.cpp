#include "Shooter.h"
extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;
extern bool shootingCheck;

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

void Shooter::checkBubble(LinkedList<Bubble>& templist, COLOR maincolor,int row, int col, int& count)
{
	if ((row < BUBBLE_ROW_BEGIN) || (row > BUBBLE_ROW_END) || (col < BUBBLE_COLUMN_BEGIN) || (col > BUBBLE_COLUMN_END)) return;

	LinkedList<Bubble>::Iterator pointptr = bubbleList.begin();
	Bubble tmp1;
	for (; pointptr != bubbleList.end(); pointptr++)
	{
		tmp1 = (*pointptr);
		Bubble tmp2(row, col, maincolor);
		if (tmp1 == tmp2) break;
	}

	if (pointptr != bubbleList.end())
	{
		/*templist.push_back(Bubble(tmp1));
		bubbleList.remove(pointptr);*/
		bubbleList.move(templist, pointptr);
		count++;

		checkBubble(templist, maincolor, row + 1, col, count);
		checkBubble(templist, maincolor, row - 1, col, count);
		checkBubble(templist, maincolor, row, col + 1, count);
		checkBubble(templist, maincolor, row, col - 1, count);
	}
	return;
};

void Shooter::shooting()
{
	shootingCheck = true;
	Bubble temp(m_shootingpoint->getX(), m_shootingpoint->getY(), m_shootingpoint->getColor());

	//shooter changes color after shot
	//this->changeColor();

	//get the column position that the player shot
	int col = m_shootingpoint->getXY().getY();

	//bubble up moving-loop
	int row = BUBBLE_ROW_END;
	for (; row > BUBBLE_ROW_BEGIN; row--)
	{
		LinkedList<Bubble>::Iterator pointptr = bubbleList.begin();

		for (; pointptr != bubbleList.end(); pointptr++)
		{
			if (((*pointptr).getX() == (row - 1))&& ((*pointptr).getY() == col)) break;
		}

		//check if the bubble has reached the final position or not
		if ((pointptr != bubbleList.end()) || (row == BUBBLE_ROW_BEGIN))
		{
			//"count" to check the number of bubbles that were hit
			int count = 1;

			//"templist" is list of bubbles that were hit
			LinkedList<Bubble> templist;

			//templist.push_back(temp);

			checkBubble(templist, temp.getColor(), row - 1, col, count);
			checkBubble(templist, temp.getColor(), row, col + 1, count);
			checkBubble(templist, temp.getColor(), row, col - 1, count);

			if (count >= 3)
			{
				m_score += score(1, count);
				LinkedList<Bubble>::Iterator pointptr = templist.begin();

				while (templist.begin() != templist.end())
				{
					(templist.pop_front()).eraser();
					if (templist.size() == 0) break;
				}
				//temp.eraser();
			}
			else
			{
				while (templist.begin() != templist.end())
				{
					bubbleList.push_back(templist.pop_front());
					//templist.move(bubbleList, templist.begin());
					if (templist.size() == 0) break;
				}
				bubbleList.push_back(temp);
				//temp.draw();
			}
			shootingCheck = false;
			return;

			/*if (count >= 3)
			{
				m_score += score(1, count);
				LinkedList<Bubble>::Iterator pointptr = templist.begin();

				for (; pointptr != templist.end(); pointptr++)
				{
					(* pointptr).eraser();
				}
			}
			else
			{
				LinkedList<Bubble>::Iterator pointptr = templist.begin();

				for (; pointptr != templist.end(); pointptr++)
				{
					Bubble tmp(*(templist.begin()));
					bubbleList.push_back(tmp);
				}
			}*/

			/*
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
					Bubble tmp(*(templist.begin()));
					bubbleList.push_back(tmp);
					//templist.pop_front();
				}
			}*/
		}
		else temp.up();
	}
	shootingCheck = false;
}

void Shooter::changeColor()
{
	//srand((int)time(0));
	Bubble* temp =  m_shootingpoint;
	m_shootingpoint = new Bubble(m_shootingpoint->getXY());
	m_shootingpoint->eraser();
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