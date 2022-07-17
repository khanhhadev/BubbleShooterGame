#include "Point.h"
#include "mylib.h"
#include <math.h>

//default constructor
Point::Point()
{

};
Point::Point(int x, int y, CHARACTER mychar):m_x(x), m_y(y), m_char(mychar), m_color(BLACK)
{
}
Point::Point(int x, int y, CHARACTER mychar, COLOR color):m_x(x), m_y(y), m_char(mychar), m_color(color)
{
};

Point::~Point()
{
};

//copy constructor
Point::Point(Point& p):m_x(p.m_x), m_y(p.m_y),m_color(p.m_color), m_char(p.m_char)
{
};

void Point::draw()
{
	SetColor(m_color);
	gotoXY(m_y, m_x);
	cout << (char)m_char;
	gotoXY(0, 16);
};

void Point::erase()
{
	gotoXY(m_y, m_x);
	cout << (char)ERASER;
	gotoXY(0, 16);
};
//return m_x value of Point object
int Point::getX() const
{
	return m_x;
};

//return m_y value of Point object
int Point::getY() const
{
	return m_y;
};

COLOR Point::getColor() const
{
	return m_color;
}

//set value for m_x of Point object
void Point::setX(int value)
{
	m_x = value;
};

//set value for m_y of Point object
void Point::setY(int value)
{
	m_y = value;
};

//set value for m_x, m_y of Point object
void Point::set(int x, int y)
{
	m_x = x;
	m_y = y;
};

//calculate distance between 2 points
float Point::distance(Point& pA, Point& pB)
{
	return sqrt((pB.m_x - pA.m_x) * (pB.m_x - pA.m_x) + (pB.m_y - pA.m_y) * (pB.m_y - pA.m_y));
};

//calculate dot product between 2 points
int Point::dotProduct(Point& pA, Point& pB)
{
	return (pA.m_x * pB.m_y + pA.m_y * pB.m_x);
};
void Point::swap(Point& p1, Point& p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
};

//assignment operator = oveloading 
Point& Point::operator= (const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	return *this;
};

//assignment operator = oveloading 
Point& Point::operator= (Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	return *this;
};


//addition operator + overloading  
Point Point::operator+ (Point& p)
{
	Point Result;
	Result.m_x = m_x + p.m_x;
	Result.m_y = m_y + p.m_y;
	return Result;
};

//subtraction operator - oveloading
Point Point::operator- (Point& p)
{
	Point Result;
	Result.m_x = m_x - p.m_x;
	Result.m_y = m_y - p.m_y;
	return Result;
};

//multiplication operator * overloading
Point Point::operator* (int p)
{
	Point Result;
	Result.m_x = m_x * p;
	Result.m_y = m_y * p;
	return Result;
};

//devision operator / overloading
Point Point::operator/ (int p)
{
	Point Result;
	if (p != 0)
	{
		Result.m_x = m_x / p;
		Result.m_y = m_y / p;
	}
	return Result;
};

//assignment operator += overloading
Point& Point::operator+= (Point& p)
{
	m_x = m_x + p.m_x;
	m_y = m_y + p.m_y;
	return *this;
};

//assignment operator -= overloading
Point& Point::operator-= (Point& p)
{
	m_x = m_x - p.m_x;
	m_y = m_y - p.m_y;
	return *this;
};

//assignment operator *= overloading
Point& Point::operator*= (int p)
{
	m_x = m_x * p;
	m_y = m_y * p;
	return *this;
};

//assignment operator /= overloading
Point& Point::operator/= (int p)
{
	if (p != 0)
	{
		m_x = m_x / p;
		m_y = m_y / p;
	}
	return *this;
};


bool Point::operator> (Point& p)
{
	if (m_x > p.m_x) return true;
	else if (m_x == p.m_x) return (m_y > p.m_y);
	return false;
}

bool Point::operator< (Point& p)
{
	if (m_x > p.m_x) return true;
	else if (m_x == p.m_x) return (m_y > p.m_y);
	return false;
};

bool Point::operator== (Point& p)
{
	return ((m_x == p.m_x)&& (m_y == p.m_y));
};

bool Point::operator== (const Point& p)
{
	return ((m_x == p.m_x) && (m_y == p.m_y));
};