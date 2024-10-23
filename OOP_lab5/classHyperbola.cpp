#include "classHyperbola.h"

Hyperbola::Hyperbola(double a, double b) : Function(a, b) {};
void Hyperbola::calculateY(double X) {
	hyperbolaX = X;
	
	double y = *b * *b * ((X * X) / (*a * *a) - 1);
	if (-1 * *a > hyperbolaX && *a < hyperbolaX ) {
		index = 0;
		hyperbolaY = sqrt(y);
	}
	else if (abs(hyperbolaX) < *a) {
		std::cout << "Для значения X значение Y - пустое множество" << std::endl;
		//икс по модулю больше a то два y
		//икс по модулю меньше а то пустое множество
		//икс равен а либо -а то игрик равен 0
	}
	else {
		hyperbolaY = sqrt(y);
	}
}
std::string Hyperbola::toString() {
	if (index == 0) {
		return "Hyperbola : x = " + std::to_string(hyperbolaX) + " y = +-" + std::to_string(hyperbolaY);
	}
	else {
		return "Hyperbola : x = " + std::to_string(hyperbolaX) + " y = " + std::to_string(hyperbolaY);
	}
}
std::pair<double, double> Hyperbola::getAsymptotes() {
	double y_First = (*b / *a) * hyperbolaX;
	double y_Second = -1 * (*b / *a) * hyperbolaX;
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