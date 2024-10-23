#pragma once
#include "classFunction.h"

class Hyperbola : public Function {
	double hyperbolaY, hyperbolaX;
	int index;
public:
	std::pair<double, double> getAsymptotes();					//����� ���������� ���������
	bool isPointOnHyperbola(double, double);					//�������� �������������� ����� ���������
	double getEccentricity();									//��������� ���������������
	std::pair<double, double> getDirectrices();					//���������� ����������
	Hyperbola(double, double);
	void calculateY(double);
	std::string toString();
};
