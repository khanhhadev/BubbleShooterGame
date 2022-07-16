#ifndef SHOOTER_H
#define SHOOTER_H

#include "General.h"
#include "Bubble.h"
#include "LinkedList.h"


class Shooter
{
public:
	void changeColor();
	int score(int timeconst, int num);
	void shooting(LinkedList<Bubble>& bubblelist, int y);
	void checkBubble(LinkedList<Bubble>& bubblelist, int row, int col, int& count);
	Shooter();
	~Shooter();
private:
	Bubble* m_shootingpoint;
	COLOR m_bubblecolor;
	int m_score = 0;
	//float m_shootingangle;
	//refrence to list of Point belonging to Shooter
	//Point* m_shooterptr;
};
#endif