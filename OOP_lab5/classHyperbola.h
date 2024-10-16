#pragma once
#include "classFunction.h"

class Hyperbola : public Function {
	double resultForHyperbola = 0;
public:
	std::pair<double, double> getAsymptotes();					//����� ���������� ���������
	bool isPointOnHyperbola(double, double);					//�������� �������������� ����� ���������
	double getEccentricity();									//��������� ���������������
	std::pair<double, double> getDirectrices();					//���������� ����������
	Hyperbola(double, double);
	double calculateY(double);
	std::string toString();
};
