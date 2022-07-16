#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "General.h"
#include "LinkedList.h"
#include "Point.h"
#include "Shooter.h"
#include "Bubble.h"


class GameInterface
{
public:
	GameInterface();
	~GameInterface();

private:
	//int m_count;
	void bubbleSort(LinkedList<Point> m_point);
	friend ostream& operator<< (ostream& output, LinkedList<Point>& m_point);
};

#endif // !GAMEINTERFACE_H