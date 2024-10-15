#pragma once
#include "classFunction.h"

class Hyperbola : public Function {
	double resultForHyperbola;
public:
	Hyperbola(double, double);
	double calculateY(double);
	std::string toString();
};
