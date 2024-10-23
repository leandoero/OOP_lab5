#pragma once
#include "classFunction.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Ellipse : public Function {
	double ellipseX, ellipseY;
	int index;
public:
	double getEccentricity();					//����� ��� ���������� ���������������
	double getParameter();						//����� ��� ���������� ��������� ������a
	bool isPointOnEllipse(double, double);		//����� ��� �������� �������������� ����� �������
	double getArea();							//����� ��� ���������� ������� �������
	double getPerimeter();						//����� ��� ���������� ����� ���������
	Ellipse(double, double);
	void calculateY(double);
	std::string toString();
};