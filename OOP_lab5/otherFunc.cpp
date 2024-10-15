#include "otherFunc.h"

void start() {
	int shapeChoice = 0, choice = 0;
	double a = 0, b = 0;
	Function* shape = nullptr;

	std::cout << "�������� ������: \n" <<
		"1. ������\n" <<
		"2. ���������\n" << std::endl;
		
	std::cout << "����: ";
	std::cin >> shapeChoice;

	std::cout << "������� �������� A � B : ";
	std::cin >> a >> b;

	if (shapeChoice == 1) {
		shape = new Ellipse(a, b);
	}
	else if (shapeChoice == 2) {
		shape = new Hyperbola(a, b);
	}

	do {
		system("cls");
		std::cout << "����: \n" <<
			"1. ��������� Y\n" <<
			"2. ����������� ��������\n" <<
			"3. ��������� � ����\n" <<
			"4. �����\n" << std::endl;
		std::cout << "����: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			system("cls");
			double x = 0;
			std::cout << "������� �������� X: ";
			std::cin >> x;
			shape->calculateY(x);
			break;
		}
		case 2: {
			system("cls");
			std::cout << shape->toString() <<std::endl;
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			start();
			choice = 4;
			break;
		}
		default:
			break;
		}
	} while (choice != 4);
	delete shape;
}