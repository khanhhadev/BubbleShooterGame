#include "Bubble.h"
//contructor
Bubble::Bubble()
{

}

// contructor with parameters
Bubble::Bubble(Point& P)
{
	srand((int)time(0));
	COLOR color[3] = { RED,GREEN,YELLOW };
	int r = rand() % 3;

	m_bubbleptr = new Point(P.getX(), P.getY(), BUBBLE, color[r]);
	m_color = color[r];
};

// contructor with parameters point & color
Bubble::Bubble(Point& P, COLOR color)
{
	m_bubbleptr = new Point(P.getX(), P.getY(), BUBBLE, color);
	m_color = color;
};

// contructor with parameters toa do x,y 
Bubble::Bubble(int x, int y)

{
	COLOR color[3] = { RED,GREEN,YELLOW };
	int r = rand() % 3;

	m_bubbleptr = new Point(x, y, BUBBLE ,color[r]);
	m_color = color[r];
}

// contructor with parameters toa do x,y & color
Bubble::Bubble(int x, int y, COLOR color)
{
	m_bubbleptr = new Point(x, y, BUBBLE, color);
	m_color = color;
};

Bubble::Bubble(Bubble& Obj)
{
	m_bubbleptr = new Point(Obj.m_bubbleptr->getX(), Obj.m_bubbleptr->getY(),BUBBLE, Obj.m_bubbleptr->getColor());
	m_color = m_bubbleptr->getColor();
};

//destructor
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
	return m_bubbleptr->getColor();
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

//shift down bubble
void Bubble::down()
{
	Point* temp = m_bubbleptr;
	m_bubbleptr = new Point(temp->getX()+1, temp->getY(), BUBBLE,temp->getColor());
	temp->erase();
	//m_bubbleptr->draw();
	delete temp;
	m_bubbleptr->draw();
};

//shift up bubble
void Bubble::up()
{
	Point* temp = m_bubbleptr;
	m_bubbleptr = new Point(temp->getX() - 1, temp->getY(), BUBBLE, temp->getColor());
	temp->erase();
	//m_bubbleptr->draw();
	delete temp;
	m_bubbleptr->draw();
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


//sort list of Point
void Bubble::bubbleSort(LinkedList<Bubble>& list)
{
	for (LinkedList<Bubble>::Iterator iterator1 = list.begin();
		iterator1 != list.rbegin(); iterator1++)
	{
		for (LinkedList<Bubble>::Iterator iterator2 = iterator1 + 1;
			iterator2 != list.end(); iterator2++)
		{
			Bubble temp = *iterator1;
			if ((*iterator1).getX() < (*iterator2).getX())
				Bubble::swap(*iterator1, *iterator2);
			else if ((*iterator1).getX() == (*iterator2).getX())
			{
				if ((*iterator1).getY() < (*iterator2).getY())

					Bubble::swap(*iterator1, *iterator2);
			}
		}
	}
}

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
	m_color = m_bubbleptr->getColor();
	return *this;
};

//assignment operator = oveloading
Bubble& Bubble::operator= (const Bubble& Obj)
{
	if (m_bubbleptr != nullptr) delete m_bubbleptr;
	m_bubbleptr = new Point(*Obj.m_bubbleptr);
	m_color = m_bubbleptr->getColor();
	return *this;
};