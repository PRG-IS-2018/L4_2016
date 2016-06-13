#pragma once
#include <iostream>
#include "Point.h"




class Circle{
	Point m_centr;
	double m_rad;
public:
	Circle(double x=0, double y=0, double rad=0);
	Circle(const Point&, const Point&);
	Circle(const Point&, const double);
	Circle(const Circle&) = default;
	Circle(Circle&&) = default;
	bool operator==(const Circle&);
	Circle& operator=(const Circle&)=default;
	//bool operator==(const Circle&, typename);
	double GetArea();
	friend std::ostream& operator<<(std::ostream&, const  Circle&);
	~Circle() = default;

};
