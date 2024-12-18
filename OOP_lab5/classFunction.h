#pragma once


#include <iostream>
#include <string>

class Function {
protected:
	double* a, * b;
public:
	Function(double, double);
	Function(const Function&);
	Function& operator=(const Function&);
	virtual void calculateY(double) = 0;
	virtual std::string toString() = 0;

	double* getA();
	double* getB();
	void SetA(double);
	void SetB(double);

	friend std::ostream& operator<<(std::ostream&, Function&);

	virtual ~Function();
};