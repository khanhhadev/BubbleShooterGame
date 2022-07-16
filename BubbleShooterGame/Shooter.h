#pragma once
#include "General.h"

class Shooter
{
public:
	Bubble* m_shootingpoint;
	float m_shootingangle;

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