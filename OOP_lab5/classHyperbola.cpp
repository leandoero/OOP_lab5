#include "classHyperbola.h"

Hyperbola::Hyperbola(double a, double b) : Function(a, b) {};

void Hyperbola::calculateY(double X) {
	hyperbolaX = X;

	// Вычисление y^2
	double ySquare = (*b) * (*b) * ((X * X) / ((*a) * (*a)) - 1);

	// Проверка условий для X
	if (std::abs(hyperbolaX) > *a) {
		// Если X больше a или меньше -a, значение Y существует
		if (ySquare >= 0) {
			index = 0;  // Выбор индекса для хранения значений
			hyperbolaY = sqrt(ySquare);  // Положительное значение Y
		}
	}
	else if (std::abs(hyperbolaX) < *a) {
		index = 1;
	}
	else if (std::abs(hyperbolaX) == *a) {
		index = 2;
	}
}
std::string Hyperbola::toString() {
	if (index == 0) {
		return "Hyperbola : x = " + std::to_string(hyperbolaX) + " y = +-" + std::to_string(hyperbolaY);
	}
	else if(index == 1){
		return "Для значения X значение Y - пустое множество";
	}
	else if (index == 2) {
		return "Hyperbola : x = " + std::to_string(hyperbolaX) + " y = 0";
	}
}
std::pair<double, double> Hyperbola::getAsymptotes() {
	double y_First = (*b / *a) * hyperbolaX;
	double y_Second = -1 * (*b / *a) * hyperbolaX;
	return { y_First, y_Second };
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