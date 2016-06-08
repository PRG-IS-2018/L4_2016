
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "circle.h"
#include "List.h"


#define _CRT_SECURE_NO_WARNINGS
#define _SP system("pause");

typedef unsigned int uint;

void main() {


	Point p1 = { 11,12 };
	Point p2 = p1;
	Point p3(p2);
	Point p4 (1,2);
	p3 = p1;
	//std::cout << p3;
	Circle C1(p1,p3);
	Circle C2(p1, p4);
	//std::cout << C1;

	List L1;
	L1.AddNode(C1);
	L1.AddNode(C2);
	std::cout << L1;

	//int c = 0,c1=0, c2 = 0,c3=0;
	//for (int i = 1; i < 401;i++) {
	//	c1 = i / 100;
	//	c2 = (i / 10)- c1*10;
	//	c3 = i - c2*10 - c1*100;
	//	if ((c1 + c2 + c3) == 4)   {
	//		std::cout << c1 << " " << c2 << " " << c3 << std::endl;
	//		c++;
	//	}
	//}
	//std::cout << c << std::endl;
	
	_SP








}