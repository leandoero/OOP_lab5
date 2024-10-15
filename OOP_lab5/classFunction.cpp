#include "classFunction.h"

Function::Function(double a, double b) {
	this->a = new double{ a };
	this->b = new double{ b };
}
Function::Function(const Function& other) {
	a = new double{ *other.a };
	b = new double{ *other.b };
}
Function& Function::operator=(const Function& other) {
	if (this == &other) {
		return *this;
	}
	*a = *other.a;
	*b = *other.b;
	return *this;
}

double* Function::getA() {
	return a;
}
double* Function::getB() {
	return b;
}
void Function::SetA(double setA) {
	*a = setA;
}
void Function::SetB(double setB) {
	*b = setB;
}

Function::~Function() {
	delete a;
	delete b;
	a = nullptr;
	b = nullptr;
}