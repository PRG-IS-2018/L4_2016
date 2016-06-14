#include "Point.h"


Point::Point(double x, double y) {
	m_x = x;
	m_y = y;
}

//Point::Point(Point&& other) {
//	m_x = other.m_x;
//	m_y = other.m_y;
//}
Point& Point::operator= (const Point& other) {
	m_x = other.m_x;
	m_y = other.m_y;
	return *this;
}

Point& Point::operator+= (const Point& other){
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Point& Point::operator+= (const double delta){
	m_x += delta;
	m_y += delta;
	return *this;
}

Point& operator-= (Point& l_p, const Point& r_p) {
	l_p.m_x -= r_p.m_x;
	l_p.m_y -= r_p.m_y;
	return l_p;
}

Point& operator-= (Point& l_p, double delta) {
	l_p.m_x -= delta;
	l_p.m_y -= delta;
	return l_p;
}
Point Point::operator+ (const double delta) {
	Point tmp((m_x + delta),(m_y + delta));
	return tmp;
}
Point Point::operator+ (const Point& other) {
	return Point ((m_x + other.m_x), (m_y + other.m_y));;
}
Point operator+ (const int delta, const Point& r_p) {
	Point tmp((r_p.m_x + delta),(r_p.m_y + delta));
	return tmp;
}
Point operator- (const Point&l_p, const double delta) {
	Point tmp((l_p.m_x - delta), (l_p.m_y - delta));
	return tmp;
}
Point operator- (const Point& l_p, const Point& r_p) {
	Point tmp((l_p.m_x - r_p.m_x), (l_p.m_y - r_p.m_y));
	return tmp;

}
Point Point::operator-() {
	return Point(-m_x,-m_y);
}
Point Point::operator+() {
	return *this;
}
bool Point::operator==(const Point & other) {
	return ((m_x == other.m_x) && (m_y == other.m_y));
}

std::ostream& operator<<(std::ostream& os, const  Point& poi) {
	return	os << "Point: x=" << poi.m_x << ",  y=" << poi.m_y;
}
std::ofstream& operator<<(std::ofstream& os, const Point& poi) {
	os << poi.m_x << " " << poi.m_y;
	return	os;
}