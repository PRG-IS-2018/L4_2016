#include "circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Point::Point(double x, double y) {
	m_x = x;
	m_y = y;
}

std::ostream& operator<<(std::ostream& os, const  Point& poi) {
	return	os << "Point: x=" << poi.m_x << ",  y=" << poi.m_y ;
}

Circle::Circle(double x, double y, double rad):m_centr(x, y) {
	m_rad = rad;
}
Circle::Circle(const Point& centr, const Point& dot): m_centr(centr) {
	m_rad = sqrt((dot.m_x - centr.m_x)*(dot.m_x - centr.m_x) + (dot.m_y - centr.m_y)*(dot.m_y - centr.m_y));
}
Circle::Circle(const Point& centr, double rad) : m_centr(centr) {
	m_rad = rad;
}

std::ostream& operator<<(std::ostream& os, const Circle& cir) {
	return os << "Circle: centr - " << cir.m_centr << ", rad - " << cir.m_rad << std::endl;
}

double Circle::GetArea() {
	return m_rad*m_rad* M_PI;
}