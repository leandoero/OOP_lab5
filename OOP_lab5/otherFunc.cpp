#include "otherFunc.h"

void start() {
	int shapeChoice = 0, choice = 0, choiceForCase = 0;
	double a = 0, b = 0;
	bool isInitialized = false, forStartProgram = true;
	Function* shape = nullptr;
	std::cout << "Выберите фигуру: \n" <<
		"1. Эллипс\n" <<
		"2. Гипербола\n" <<
		"3. Выход\n" << std::endl;
	std::cout << "Ввод: ";
	std::cin >> shapeChoice;
	if (shapeChoice == 3) {
		forStartProgram = false;
	}
	if (forStartProgram) {
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
				"3. Перейти к индивидуальным методам\n" <<
				"4. Вернуться в меню\n" << std::endl;
			std::cout << "Ввод: ";
			std::cin >> choice;
			switch (choice)
			{
			case 1: {
				system("cls");
				double x = 0;
				std::cout << "Введите значение X: ";
				std::cin >> x;
				shape->SetX(x);
				isInitialized = true;
				shape->calculateY(x);
				break;
			}
			case 2: {
				system("cls");
				std::cout << shape->toString() << std::endl;
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				if (shapeChoice == 1) {			//эллипс
					Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);
					do {
						system("cls");
						std::cout << "1. Вычисление эксцентриситета\n" <<
							"2. Вычисление параметра эллипсa\n" <<
							"3. Проверка принадлежности точки эллипсу\n" <<
							"4. Вычисление площади эллипса\n" <<
							"5. Вычисление длины периметра\n" <<
							"6. Вернуться в меню\n" << std::endl;
						std::cout << "Ввод: ";
						std::cin >> choiceForCase;
						switch (choiceForCase)
						{
						case 1: {
							std::cout << "Эксцентриситет = " << ellipse->getEccentricity() << std::endl;
							system("pause");
							break;
						}
						case 2: {
							std::cout << "Параметр = " << ellipse->getParameter() << std::endl;
							system("pause");
							break;
						}
						case 3: {
							double x = 0, y = 0;
							std::cout << "Введите значение точки : (x | y) ";
							std::cin >> x >> y;
							std::cout << std::boolalpha;
							std::cout << ellipse->isPointOnEllipse(x, y) << std::endl;
							system("pause");
							break;
						}
						case 4: {
							std::cout << "Площадь = " << ellipse->getArea() << std::endl;
							system("pause");
							break;
						}
						case 5: {
							std::cout << "Длина периметра = " << ellipse->getPerimeter() << std::endl;
							system("pause");
							break;
						}
						default:
							break;
						}
					} while (choiceForCase != 6);
				}
				else {
					Hyperbola* hyperbola = dynamic_cast<Hyperbola*>(shape);
					do {
						system("cls");
						std::cout << "1. Найти ассимптоты\n" <<
							"2. Проверка принадлежности точки гиперболе\n" <<
							"3. Получение эксентриситета\n" <<
							"4. Нахождение директрисы\n" <<
							"5. Вернуться в меню\n" << std::endl;
						std::cin >> choiceForCase;
						switch (choiceForCase)
						{
						case 1: {
							if (isInitialized == true) {
								std::cout << "Ассимптоты: " << hyperbola->getAsymptotes().first << " | " << hyperbola->getAsymptotes().second << std::endl;
								system("pause");
								break;
							}
							else {
								std::cout << "Для выполнения нужно задать X" << std::endl;
								system("pause");
								break;
							}
						}
						case 2: {
							double x = 0, y = 0;
							std::cout << "Введите значение точки : (x | y) ";
							std::cin >> x >> y;
							std::cout << std::boolalpha;
							std::cout << hyperbola->isPointOnHyperbola(x, y) << std::endl;
							system("pause");
							break;
						}
						case 3: {
							std::cout << "Экстренситет: " << hyperbola->getEccentricity() << std::endl;
							system("pause");
							break;
						}
						case 4: {
							std::cout << "Директриса: " << hyperbola->getDirectrices().first << " | " << hyperbola->getDirectrices().second << std::endl;
							system("pause");
							break;
						}
						default:
							break;
						}
					} while (choiceForCase != 5);
				}
			case 4: {
				system("cls");
				start();
				choice = 4;
				break;
			}
			}
			default:
				break;
			}
		} while (choice != 4);
		delete shape;
	}
}

std::ostream& operator<<(std::ostream& out, Function& func) {
	out << *func.a << *func.b;
	return out;
}