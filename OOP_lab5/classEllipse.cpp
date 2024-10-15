#include "classEllipse.h"		//можно потом убрать

Ellipse::Ellipse(double a, double b) : Function(a, b) {};

double Ellipse::calculateY(double X) {
	resultForEllipse = sqrt(*b * *b * (1 - (X * X) / (*a * *a)));
	return resultForEllipse;
}
std::string Ellipse::toString() {
	return "Ellipse : y = " + std::to_string(resultForEllipse);
}

