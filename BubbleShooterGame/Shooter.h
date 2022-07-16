#ifndef SHOOTER_H
#define SHOOTER_H

#include "General.h"
#include "Bubble.h"
#include "LinkedList.h"

class Shooter
{
public:
	Bubble* m_shootingpoint;
	float m_shootingangle;
	COLOR m_bubblecolor;
	//refrence to list of Point belonging to Shooter
	//Point* m_shooterptr;
private:
	void changeColor();
	int score(int timeconst, int num);
	void shooting(LinkedList<Bubble>& bubblelist, int y);
	int checkBubble(LinkedList<Bubble>& bubblelist, Bubble&);
	Shooter();
	~Shooter();
};
#endif