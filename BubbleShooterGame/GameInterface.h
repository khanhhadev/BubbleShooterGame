#pragma once
#include "Bubble.h"
#include "Point.h"
class GameInterface
{
public:
	GameInterface();
	~GameInterface();

private:
	Point* m_point;
	int m_count;
	friend ostream& operator<< (ostream& output, GameInterface);
};

GameInterface::GameInterface()
{
}

GameInterface::~GameInterface()
{
}