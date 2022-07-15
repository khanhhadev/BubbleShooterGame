#pragma once
#include "Point.h"

enum COLOR{
	RED,
	BLUE, 
	YELLOW,
};

class Bubble
{
public:
	void fall();
	Bubble();
	~Bubble();

private:
	//refrence to list of Point belonging to Bubble
	Point* m_bubbleptr;
};

Bubble::Bubble()
{
}

Bubble::~Bubble()
{
}

void Bubble::fall()
{

}