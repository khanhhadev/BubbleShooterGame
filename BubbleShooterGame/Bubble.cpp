#include "Bubble.h"

Bubble::Bubble()
{

	bubbleList.push_back(*this);
}

Bubble::Bubble(int x, int y, Interface::COLOR color)
{
	m_bubbleptr = new Point(x, y);
	m_color = color;
	bubbleList.push_back(*this);
};

Bubble::~Bubble()
{
	delete m_bubbleptr;
	bubbleList.remove(bubbleList.find(*this));
}

void Bubble::fall()
{
	delete m_bubbleptr;
}

void Bubble::setColor(Interface::COLOR value)
{
	m_color = value;
};

Interface::COLOR Bubble::getColor() const
{
	return m_color;
}
bool Bubble::operator==(Bubble& Obj)
{
	return (*m_bubbleptr == *Obj.m_bubbleptr) && (m_color == Obj.m_color);
};