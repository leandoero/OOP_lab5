#pragma once
#include "classFunction.h"

class Ellipse : public Function {
	double resultForEllipse;
public:
	Ellipse(double, double);
	double calculateY(double);
	std::string toString();
};