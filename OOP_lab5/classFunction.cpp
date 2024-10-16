#include "classFunction.h"

Function::Function(double a, double b) {
	this->a = new double{ a };
	this->b = new double{ b };
	this->x = new double;
}
Function::Function(const Function& other) {
	a = new double{ *other.a };
	b = new double{ *other.b };
	x = new double{ *other.x };
}
Function& Function::operator=(const Function& other) {
	if (this == &other) {
		return *this;
	}
	*a = *other.a;
	*b = *other.b;
	*x = *other.x;
	return *this;
}

double* Function::getA() {
	return a;
}
double* Function::getB() {
	return b;
}
double* Function::getX() {
	return x;
}
void Function::SetX(double setX) {
	*x = setX;
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
	delete x;
	a = nullptr;
	b = nullptr;
	x = nullptr;
}