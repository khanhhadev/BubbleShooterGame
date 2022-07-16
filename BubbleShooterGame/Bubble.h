#pragma once
#include "General.h"

class Bubble
{
public:
	void fall();
	void setColor(Interface::COLOR);

	Bubble();
	Bubble(int, int, Interface::COLOR);
	~Bubble();
	bool operator==(Bubble& Obj);
private:
	//refrence to list of Point belonging to Bubble
	Point* m_bubbleptr;
	Interface::COLOR m_color;
	
};
