#pragma once
#include "classFunction.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Ellipse : public Function {
	double resultForEllipse = 0;
public:
	double getEccentricity();					//����� ��� ���������� ���������������
	double getParameter();						//����� ��� ���������� ��������� ������a
	bool isPointOnEllipse(double, double);		//����� ��� �������� �������������� ����� �������
	double getArea();							//����� ��� ���������� ������� �������
	double getPerimeter();						//����� ��� ���������� ����� ���������
	Ellipse(double, double);
	double calculateY(double);
	std::string toString();
};