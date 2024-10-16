#include "otherFunc.h"

void start() {
	int shapeChoice = 0, choice = 0, choiceForCase = 0;
	double a = 0, b = 0;
	bool isInitialized = false, forStartProgram = true;
	Function* shape = nullptr;
	std::cout << "�������� ������: \n" <<
		"1. ������\n" <<
		"2. ���������\n" <<
		"3. �����\n" << std::endl;
	std::cout << "����: ";
	std::cin >> shapeChoice;
	if (shapeChoice == 3) {
		forStartProgram = false;
	}
	if (forStartProgram) {
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
				"3. ������� � �������������� �������\n" <<
				"4. ��������� � ����\n" << std::endl;
			std::cout << "����: ";
			std::cin >> choice;
			switch (choice)
			{
			case 1: {
				system("cls");
				double x = 0;
				std::cout << "������� �������� X: ";
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
				if (shapeChoice == 1) {			//������
					Ellipse* ellipse = dynamic_cast<Ellipse*>(shape);
					do {
						system("cls");
						std::cout << "1. ���������� ���������������\n" <<
							"2. ���������� ��������� ������a\n" <<
							"3. �������� �������������� ����� �������\n" <<
							"4. ���������� ������� �������\n" <<
							"5. ���������� ����� ���������\n" <<
							"6. ��������� � ����\n" << std::endl;
						std::cout << "����: ";
						std::cin >> choiceForCase;
						switch (choiceForCase)
						{
						case 1: {
							std::cout << "�������������� = " << ellipse->getEccentricity() << std::endl;
							system("pause");
							break;
						}
						case 2: {
							std::cout << "�������� = " << ellipse->getParameter() << std::endl;
							system("pause");
							break;
						}
						case 3: {
							double x = 0, y = 0;
							std::cout << "������� �������� ����� : (x | y) ";
							std::cin >> x >> y;
							std::cout << std::boolalpha;
							std::cout << ellipse->isPointOnEllipse(x, y) << std::endl;
							system("pause");
							break;
						}
						case 4: {
							std::cout << "������� = " << ellipse->getArea() << std::endl;
							system("pause");
							break;
						}
						case 5: {
							std::cout << "����� ��������� = " << ellipse->getPerimeter() << std::endl;
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
						std::cout << "1. ����� ����������\n" <<
							"2. �������� �������������� ����� ���������\n" <<
							"3. ��������� ��������������\n" <<
							"4. ���������� ����������\n" <<
							"5. ��������� � ����\n" << std::endl;
						std::cin >> choiceForCase;
						switch (choiceForCase)
						{
						case 1: {
							if (isInitialized == true) {
								std::cout << "����������: " << hyperbola->getAsymptotes().first << " | " << hyperbola->getAsymptotes().second << std::endl;
								system("pause");
								break;
							}
							else {
								std::cout << "��� ���������� ����� ������ X" << std::endl;
								system("pause");
								break;
							}
						}
						case 2: {
							double x = 0, y = 0;
							std::cout << "������� �������� ����� : (x | y) ";
							std::cin >> x >> y;
							std::cout << std::boolalpha;
							std::cout << hyperbola->isPointOnHyperbola(x, y) << std::endl;
							system("pause");
							break;
						}
						case 3: {
							std::cout << "������������: " << hyperbola->getEccentricity() << std::endl;
							system("pause");
							break;
						}
						case 4: {
							std::cout << "����������: " << hyperbola->getDirectrices().first << " | " << hyperbola->getDirectrices().second << std::endl;
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