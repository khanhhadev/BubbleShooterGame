#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "General.h"
#include "LinkedList.h"
#include "Point.h"
#include "Shooter.h"
#include "Bubble.h"
#include "Display.h"


class GameInterface
{
public:
	GameInterface();
	~GameInterface();

	void createBubble();
	void bubbleSort(LinkedList<Bubble>& list);
	friend ostream& operator<< (ostream& output, LinkedList<Point>& m_point);
};

#endif // !GAMEINTERFACE_H