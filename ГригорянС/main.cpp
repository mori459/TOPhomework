#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	double num1, num2;
	char choice;
	std::cin >> num1;

	std::cout << "Выберете действие:  +  -  *  /\n";

	std::cin >> choice;
	std::cin >> num2;
	

	switch (choice)
	{
	case '+':
		std::cout << num1 + num2;
		break;

	case '-':
		std::cout << num1 - num2;
		break;

	case '*':
		std::cout << num1 * num2;
		break;

	case '/':
		if (num2 != 0)
		{
			std::cout << num1 / num2;
		}
		else
		{
			std::cerr << "Error: division by 0";
		}
		break;

	default:
		std::cerr << "Error: incorrect input choice";
		break;
	}


	/*if (choice == 1)
	{
		std::cout << num1 + num2;
	}
	else if(choice == 2)
	{
		std::cout << num1 - num2;
	}
	else if (choice == 3)
	{
		std::cout << num1 * num2;
	}
	else if (choice == 4)
	{
		std::cout << num1 / num2;
	}
	else
	{
		std::cerr << "Error: incorrect input choice";
	}*/



	return 0;
}