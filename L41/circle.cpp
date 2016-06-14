#include "circle.h"
//#include "Point.h"
#define _USE_MATH_DEFINES
#include <math.h>






Circle::Circle(double x, double y, double rad):m_centr(x, y) {
	m_rad = rad;
}
Circle::Circle(const Point& centr, const Point& dot): m_centr(centr) {
	m_rad = sqrt((dot.m_x - centr.m_x)*(dot.m_x - centr.m_x) + (dot.m_y - centr.m_y)*(dot.m_y - centr.m_y));
}
Circle::Circle(const Point& centr, double rad) : m_centr(centr) {
	m_rad = rad;
}
bool Circle::operator==(const Circle& other) {
	return ((m_rad == other.m_rad)&&(m_centr == other.m_centr));
}
std::ostream& operator<<(std::ostream& os, const Circle& cir) {
	return os << "Circle: centr - (" << cir.m_centr << "), rad - " << cir.m_rad << std::endl;
}
std::ofstream& operator<<(std::ofstream& os, const Circle& cir) {
	os << cir.m_centr << " " << cir.m_rad;
		return os;
}
double Circle::GetArea() {
	return m_rad*m_rad* M_PI;
}