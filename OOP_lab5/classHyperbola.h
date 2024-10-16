#pragma once
#include "classFunction.h"

class Hyperbola : public Function {
	double resultForHyperbola = 0;
public:
	std::pair<double, double> getAsymptotes();					//метод нахождения ассимптот
	bool isPointOnHyperbola(double, double);					//проверка принадлежности точки гиперболе
	double getEccentricity();									//получение эксцентриситета
	std::pair<double, double> getDirectrices();					//нахождение директрисы
	Hyperbola(double, double);
	double calculateY(double);
	std::string toString();
};
