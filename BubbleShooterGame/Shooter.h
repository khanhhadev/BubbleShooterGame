#ifndef SHOOTER_H
#define SHOOTER_H

#include "General.h"
#include "Bubble.h"
#include "LinkedList.h"


class Shooter
{
public:
	void changeColor();
	void left();
	void right();
	void draw();
	void eraser();
	int score(int timeconst, int num);
	void shooting();
	void checkBubble(LinkedList<Bubble>& templist, COLOR maincolor, int row, int col, int& count);
	Shooter();
	~Shooter();
private:
	Bubble* m_shootingpoint = nullptr;
	COLOR m_bubblecolor;
	int m_score = 0;
	//float m_shootingangle;
	//refrence to list of Point belonging to Shooter
	//Point* m_shooterptr;
};
#endif