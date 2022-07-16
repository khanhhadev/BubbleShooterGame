#include "Bubble.h"

Bubble::Bubble()
{

}

Bubble::Bubble(int x, int y, COLOR color)
{
	m_bubbleptr = new Point(x, y);
	m_color = color;
};

Bubble::~Bubble()
{
	delete m_bubbleptr;
}

void Bubble::fall()
{
	delete m_bubbleptr;
}

void Bubble::setColor(COLOR value)
{
	m_color = value;
};

COLOR Bubble::getColor() const
{
	return m_color;
}

bool Bubble::operator==(Bubble& Obj)
{
	return (*m_bubbleptr == *Obj.m_bubbleptr) && (m_color == Obj.m_color);
};

bool Bubble::operator==(const Bubble& Obj)
{
	return (*m_bubbleptr == *Obj.m_bubbleptr) && (m_color == Obj.m_color);
};

//assignment operator = oveloading
Bubble& Bubble::operator= (Bubble& Obj)
{
	*m_bubbleptr = *Obj.m_bubbleptr;
	m_color = Obj.m_color;
	return *this;
};
//assignment operator = oveloading
Bubble& Bubble::operator= (const Bubble& Obj)
{
	*m_bubbleptr = *Obj.m_bubbleptr;
	m_color = Obj.m_color;
	return *this;
};