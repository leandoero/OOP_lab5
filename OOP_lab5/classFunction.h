#pragma once

//добавить перегрузку << 

#include <iostream>
#include <string>

class Function {
protected:
	double* a, * b, * x;
public:
	Function(double, double);
	Function(const Function&);
	Function& operator=(const Function&);
	virtual double calculateY(double) = 0;
	virtual std::string toString() = 0;

	double* getA();
	double* getB();
	double* getX();
	void SetX(double);
	void SetA(double);
	void SetB(double);

	friend std::ostream& operator<<(std::ostream&, Function&);

	~Function();
};