#include "classEllipse.h"

Ellipse::Ellipse(double a, double b) : Function(a, b) {};

double Ellipse::calculateY(double X) {
	resultForEllipse = sqrt(*b * *b * (1 - (X * X) / (*a * *a)));
	return resultForEllipse;
}
std::string Ellipse::toString() {
	return "Ellipse : x = " + std::to_string(*x) + " y = " + std::to_string(resultForEllipse);
}
double Ellipse::getEccentricity() {
	double c = sqrt(*a * *a - *b * *b);
	return c / *a;
}
double Ellipse::getArea() {
	return M_PI * *a * *b;
}
double Ellipse::getPerimeter() {
	return M_PI * (3 * (*a + *b) - sqrt((3 * *a + *b) * (*a + 3 * *b)));
}
bool Ellipse::isPointOnEllipse(double x, double y) {
	return (x * x) / (*a * *a) + (y * y) / (*b * *b) == 1;
}
double Ellipse::getParameter() {
	return (*b * *b) / *a;
}
