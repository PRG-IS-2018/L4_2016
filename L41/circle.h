#pragma once
#include <iostream>


class Point {

	friend class Circle; /////????????????
protected:
	double m_x;
	double m_y;

public:

	Point(double = 0, double = 0);
	friend std::ostream& operator<<(std::ostream&, Point&);

private:

};


class Circle{
	Point m_centr;
	double m_rad;
public:
	Circle(double x=0, double y=0, double rad=0);
	Circle(Point&, Point&);

	friend std::ostream& operator<<(std::ostream&, Circle&);
	~Circle() = default;

private:

};
