#pragma once
#include <iostream>

class Point{
	double m_x;
	double m_y;
	friend class Circle;

	friend Point& operator-= (Point&, const Point&);
	friend Point& operator-= (Point&, double);
	friend Point operator- (const Point&, const double);
	friend Point operator- (const Point&, const Point&);

	friend Point operator+ (const int, const Point&);
	
	
	public:
		Point(double = 0, double = 0);
		bool operator==(const Point&);
		friend std::ostream& operator<<(std::ostream&, const Point&);
	
	//Point(Point&&); //не сильно нужен, но написан для проверки
	Point& operator= (const Point&);

	Point& operator+= (const Point&);
	Point& operator+= (const double);

	Point operator+ (const double);
	Point operator+ (const Point&);
	Point operator- ();
	Point operator+ ();
};

