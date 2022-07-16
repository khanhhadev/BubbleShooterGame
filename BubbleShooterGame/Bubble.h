#pragma once
#include "General.h"
using namespace Interface;

class Bubble
{
public:
	void fall();
	void setColor(Interface::COLOR);
	Interface::COLOR getColor() const;
	Bubble();
	Bubble(int, int, Interface::COLOR);
	~Bubble();
	bool operator==(Bubble& Obj);
private:
	//refrence to list of Point belonging to Bubble
	Point* m_bubbleptr;
	Interface::COLOR m_color;
};
