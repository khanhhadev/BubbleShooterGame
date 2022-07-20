#include "Shooter.h"
#include "Display.h"

extern MODE mymode;
extern PLAYMODE myplay;
extern LinkedList<Bubble> bubbleList;


int Shooter::score(int timeconst, int num)
// num = so luong bong
{
	int score = 0;
	if (num == 3 || num == 4)
	{
		score = 1 * num * timeconst;
	}
	else if (num >= 5)
	{
		score = 2 * num * timeconst;
	}
	return score;
}

//check bubble to delete bubble same color
void Shooter::checkBubble(LinkedList<Bubble>& templist, COLOR maincolor,int row, int col, int& count)
{
	if ((row < BUBBLE_ROW_BEGIN) || (row > BUBBLE_ROW_END) || (col < BUBBLE_COLUMN_BEGIN) || (col > BUBBLE_COLUMN_END)) return;

	int x;
	LinkedList<Bubble>::Iterator pointptr = bubbleList.begin(); 
	//Bubble tmp1;
	for (; pointptr != bubbleList.end(); pointptr++)
	{
		//tmp1 = (*pointptr);
		if (((*pointptr).getX() == row)&& ((*pointptr).getY() == col)&& ((*pointptr).getColor() == maincolor))
		{
			break;
		}
	}
	if (pointptr != bubbleList.end())
	{
		templist.push_back(*pointptr);
		bubbleList.remove(pointptr);
		//bubbleList.move(templist, pointptr);
		count++;

		checkBubble(templist, maincolor, row + 1, col, count);
		checkBubble(templist, maincolor, row - 1, col, count);
		checkBubble(templist, maincolor, row, col + 1, count);
		checkBubble(templist, maincolor, row, col - 1, count);
	}
	return;
};

//shooting event 
void Shooter::shooting()
{
	while (myplay == CREATING)
	{

	}
	myplay = SHOOTING;
	Bubble temp(m_shootingpoint->getX(), m_shootingpoint->getY(), m_shootingpoint->getColor());
	COLOR tempcolor = temp.getColor();

	//get the column position that the player shot
	int col = m_shootingpoint->getXY().getY();

	//bubble up moving-loop
	int row = BUBBLE_ROW_END;
	for (; row >= BUBBLE_ROW_BEGIN; row--)
	{
		LinkedList<Bubble>::Iterator checkptr = bubbleList.begin();

		for (; checkptr != bubbleList.end(); checkptr++)
		{
			if (((*checkptr).getX() == (row - 1))&& ((*checkptr).getY() == col)) break;
		}

		//check if the bubble has reached the final position or not
		if ((checkptr != bubbleList.end()) || (row == BUBBLE_ROW_BEGIN))
		{
			//"count" to check the number of bubbles that were hit
			int count = 1;

			//"templist" is list of bubbles that were hit
			LinkedList<Bubble> templist;

			templist.push_back(temp);

			checkBubble(templist, tempcolor, row - 1, col, count);
			checkBubble(templist, tempcolor, row, col + 1, count);
			checkBubble(templist, tempcolor, row, col - 1, count);

			if (count >= 3)
			{
				m_score += score(1, count);
				displayScore(m_score);
				//LinkedList<Bubble>::Iterator itr = templist.begin();

				while (templist.size() != 0)
				{
					(templist.pop_front()).eraser();
				}
				
			}
			else
			{
				while (templist.size() != 0)
				{
					bubbleList.push_back(templist.pop_front());
				}
				//if (templist.size() != 0)
				//{
				//	LinkedList<Bubble>::Iterator ptr = bubbleList.begin();

				//	for (; ptr != templist.end(); ptr++)
				//	{
				//		bubbleList.push_back(*(ptr));
				//		templist.remove(ptr);
				//	}
				//}
			}
			myplay = NOTHING;
			return;
		}
		else
		{
			temp.up();
			Sleep(50);
		}
	}
	myplay = NOTHING;
}

//Control shooter to shift left, right or shoot
void Shooter::shootercontrol() {
	char key;
	do {
		key = _getch();
		switch (key) {
		case KEY_UP:
			shooting();
			changeColor();
			break;
		case KEY_LEFT:
			left();
			break;
		case KEY_RIGHT:
			right();
			break;
		case KEY_ESC:
			mymode = WAIT;
			return;
			break;
		default:
			break;
		}
		myplay = NOTHING;
	} while (mymode == PLAY);
}

// change shooter color (green, red, yellow)
void Shooter::changeColor()
{
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

int Shooter::getScore() const
{
	return m_score;
};
Shooter::Shooter()
{
	m_shootingpoint = new Bubble(SHOOTER_X, SHOOTER_Y);
	m_shootingpoint->draw();
}

Shooter::~Shooter()
{
	delete m_shootingpoint;
}