#include "otherFunc.h"

void start() {
	int shapeChoice = 0, choice = 0;
	double a = 0, b = 0;
	Function* shape = nullptr;

	std::cout << "Выберите фигуру: \n" <<
		"1. Эллипс\n" <<
		"2. Гипербола\n" << std::endl;
		
	std::cout << "Ввод: ";
	std::cin >> shapeChoice;

	std::cout << "Введите значение A и B : ";
	std::cin >> a >> b;

	if (shapeChoice == 1) {
		shape = new Ellipse(a, b);
	}
	else if (shapeChoice == 2) {
		shape = new Hyperbola(a, b);
	}

	do {
		system("cls");
		std::cout << "Меню: \n" <<
			"1. Вычислить Y\n" <<
			"2. Распечатать значение\n" <<
			"3. Вернуться в меню\n" <<
			"4. Выход\n" << std::endl;
		std::cout << "Ввод: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1: {
			system("cls");
			double x = 0;
			std::cout << "Введите значение X: ";
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