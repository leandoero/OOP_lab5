#pragma once
#include "classFunction.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Ellipse : public Function {
	double resultForEllipse = 0;
public:
	double getEccentricity();					//Метод для вычисления эксцентриситета
	double getParameter();						//Метод для вычисления параметра эллипсa
	bool isPointOnEllipse(double, double);		//Метод для проверки принадлежности точки эллипсу
	double getArea();							//Метод для вычисления площади эллипса
	double getPerimeter();						//Метод для вычисления длины периметра
	Ellipse(double, double);
	double calculateY(double);
	std::string toString();
};