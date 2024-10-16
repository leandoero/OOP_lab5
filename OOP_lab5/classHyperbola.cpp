#include "classHyperbola.h"

Hyperbola::Hyperbola(double a, double b) : Function(a, b) {};
double Hyperbola::calculateY(double X) {
	resultForHyperbola = sqrt(*b * *b * ((X * X) / (*a * *a) - 1));
	return resultForHyperbola;
}
std::string Hyperbola::toString() {
	return "Hyperbola : x = " + std::to_string(*x) + " y = " + std::to_string(resultForHyperbola);
}
std::pair<double, double> Hyperbola::getAsymptotes() {
	double y_First = (*b / *a) * *x;
	double y_Second = -1 * (*b / *a) * *x;
	return {y_First, y_Second};
}
bool Hyperbola::isPointOnHyperbola(double x, double y) {
	return (x * x) / (*a * *a) - (y * y) / (*b * *b) == 1;
}
double Hyperbola::getEccentricity() {
	double c = sqrt(*a * *a + *b * *b);
	return c / *a;
}
std::pair<double, double> Hyperbola::getDirectrices() {
	double e = getEccentricity();
	return { *a / e, (-1 * *a) / e };
}