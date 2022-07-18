#include "Bubble.h"

extern LinkedList<Bubble> bubbleList;
extern LinkedList<Point> pointList;
Bubble::Bubble()
{

}
Bubble::Bubble(Point& P)
{
	srand((int)time(0));
	COLOR color[3] = { RED,GREEN,YELLOW };
	int r = rand() % 3;

	m_bubbleptr = new Point(P.getX(), P.getY(), BUBBLE, color[r]);
	m_color = color[r];
};

Bubble::Bubble(Point& P, COLOR color)
{
	m_bubbleptr = new Point(P.getX(), P.getY(), BUBBLE, color);
	m_color = color;
};

Bubble::Bubble(int x, int y)

{
	COLOR color[3] = { RED,GREEN,YELLOW };
	int r = rand() % 3;

	m_bubbleptr = new Point(x, y, BUBBLE ,color[r]);
	m_color = color[r];
}

Bubble::Bubble(int x, int y, COLOR color)
{
	m_bubbleptr = new Point(x, y, BUBBLE, color);
	m_color = color;
};

Bubble::Bubble(Bubble& Obj):m_color(Obj.m_color)
{
	m_bubbleptr = new Point(Obj.m_bubbleptr->getX(), Obj.m_bubbleptr->getY(),BUBBLE, Obj.m_bubbleptr->getColor());
};

Bubble::~Bubble()
{
	//m_bubbleptr->erase();
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

int Bubble::getX() const
{
	return m_bubbleptr->getX();
};

int Bubble::getY() const
{
	return m_bubbleptr->getY();
};

Point& Bubble::getXY() const
{
	return *m_bubbleptr;
};

void Bubble::down()
{
	Point* temp = m_bubbleptr;
	m_bubbleptr = new Point(temp->getX()+1, temp->getY(), BUBBLE,temp->getColor());
	temp->erase();
	m_bubbleptr->draw();
	delete temp;
};

void Bubble::up()
{
	Point* temp = m_bubbleptr;
	m_bubbleptr = new Point(temp->getX() - 1, temp->getY(), BUBBLE, temp->getColor());
	temp->erase();
	m_bubbleptr->draw();
	delete temp;
};

void Bubble::left()
{
	if (m_bubbleptr->getY() != BUBBLE_COLUMN_BEGIN)
	{
		//m_bubbleptr->erase();
		Point* temp = m_bubbleptr;
		m_bubbleptr = new Point(temp->getX(), temp->getY() - 1, BUBBLE, temp->getColor());
		//temp->erase();
		temp->erase();
		//m_bubbleptr->draw();
		delete temp;
	}
	m_bubbleptr->draw();
};

void Bubble::right()
{
	if (m_bubbleptr->getY() != BUBBLE_COLUMN_END)
	{
		Point* temp = m_bubbleptr;
		m_bubbleptr = new Point(temp->getX(), temp->getY() + 1, BUBBLE, temp->getColor());
		temp->erase();
		//m_bubbleptr->draw();
		delete temp;
	}
	m_bubbleptr->draw();
};

void Bubble::eraser()
{
	m_bubbleptr->erase();
}


void Bubble::draw()
{
	m_bubbleptr->draw();
}

void Bubble::swap(Bubble& p1, Bubble& p2)
{
	Bubble temp = p1;
	p1 = p2;
	p2 = temp;
};


bool Bubble::operator> (Bubble& p)
{
	return (*m_bubbleptr > *p.m_bubbleptr);
}

bool Bubble::operator< (Bubble& p)
{
	return (*m_bubbleptr < *p.m_bubbleptr);
};

bool Bubble::operator==(Bubble& Obj)
{
	return (*m_bubbleptr == *Obj.m_bubbleptr) && (m_color == Obj.m_color);
};

bool Bubble::operator==(const Bubble& Obj)
{
	return (*m_bubbleptr == *Obj.m_bubbleptr) && (m_color == Obj.m_color);
};

bool Bubble::operator==(const Point& Obj)
{
	return (*m_bubbleptr == Obj);
};



//assignment operator = oveloading
Bubble& Bubble::operator= (Bubble& Obj)
{
	if (m_bubbleptr != nullptr) delete m_bubbleptr;
	m_bubbleptr = new Point(*Obj.m_bubbleptr);
	m_color = Obj.m_color;
	return *this;
};

//assignment operator = oveloading
Bubble& Bubble::operator= (const Bubble& Obj)
{
	if (m_bubbleptr != nullptr) delete m_bubbleptr;
	m_bubbleptr = new Point(*Obj.m_bubbleptr);
	m_color = Obj.m_color;
	return *this;
};