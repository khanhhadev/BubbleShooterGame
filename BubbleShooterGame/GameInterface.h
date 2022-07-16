#pragma once
#include "General.h"

class GameInterface
{
public:
	GameInterface();
	~GameInterface();

private:
	int m_count;
	void bubbleSort(LinkedList<Point> m_point);
	friend ostream& operator<< (ostream& output, LinkedList<Point>& m_point);
};
