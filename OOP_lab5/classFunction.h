#pragma once

//добавить перегрузку <<

#include <iostream>
#include <string>

class Function {
protected:
	double* a, * b;
public:
	Function(double, double);
	Function(const Function&);
	Function& operator=(const Function&);
	virtual double calculateY(double) = 0;
	virtual std::string toString() = 0;

	double* getA();
	double* getB();
	void SetA(double);
	void SetB(double);

	~Function();
};