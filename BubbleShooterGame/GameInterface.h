#pragma once
#include "Bubble.h"
#include "LinkedList.h"
#include "Point.h"

class GameInterface
{
public:
	GameInterface();
	~GameInterface();

private:
	int m_count;
	void bubbleSort();
	friend ostream& operator<< (ostream& output, LinkedList<Point>& m_point);
};

GameInterface::GameInterface()
{
}

GameInterface::~GameInterface()
{
}
