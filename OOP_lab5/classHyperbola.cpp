#include "classHyperbola.h"

Hyperbola::Hyperbola(double a, double b) : Function(a, b) {};
double Hyperbola::calculateY(double X) {
	resultForHyperbola = sqrt(*b * *b * ((X * X) / (*a * *a) - 1));
	return resultForHyperbola;
}
std::string Hyperbola::toString() {
	return "Hyperbola : y = " + std::to_string(resultForHyperbola);
}