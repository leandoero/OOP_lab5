#include "classEllipse.h"

Ellipse::Ellipse(double a, double b) : Function(a, b) {};

void Ellipse::calculateY(double X) {
	ellipseX = X;
	double y = *b * *b * (1 - (X * X) / (*a * *a));
	if (y < 0) {
		std::cout << "Значение X не подходит" << std::endl;
		return;
	}
	else if (y == 0) {
		index = 0;
		ellipseY = sqrt(*b * *b * (1 - (X * X) / (*a * *a)));
	}
	else {
		index = 1;
		ellipseY = sqrt(*b * *b * (1 - (X * X) / (*a * *a)));
	}
}
std::string Ellipse::toString() {
	if (index == 0) {
		return "Ellipse : x = " + std::to_string(ellipseX) + " y = " + std::to_string(ellipseY);
	}
	else if (index == 1) {
		return "Ellipse : x = " + std::to_string(ellipseX) + " y = +-" + std::to_string(ellipseY);
	}
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
	return (x * x) / (*a * *a) + (y * y) / (*b * *b) <= 1;
}
double Ellipse::getParameter() {
	return (*b * *b) / *a;
}
