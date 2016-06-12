#pragma once
#include <iostream>


class Point {

	friend class Circle; /////????????????
protected:
	double m_x;
	double m_y;

public:

	Point(double = 0, double = 0);
	bool operator==(const Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);

};


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
