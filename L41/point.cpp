#include "Point.h"

Point::Point(int x,int y) {
	m_x = x;
	m_y = y;
}

std::ostream& operator<<(std::ostream& os, Point& poi) {
	return	os << "Point: x=" << poi.m_x << ",  y=" << poi.m_y << std::endl;
}