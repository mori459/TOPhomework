#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int total_sum = 0;
	const int p_len = 4, b_len = 3;


	int pizza_choice, amount_p = 0, pizza_sum = 0;
	int  pizza_cost[p_len]{ 4, 7, 5, 6 }, pizza_amount[p_len]{ 0, 0, 0, 0 };
	std::string pizza_name[p_len]{ "Пепперони", "4 Сыра", "Маргорита", "Греческая" };
	int pizza_count = 0;

	int amount_b = 0, beveridge_choice, beveridge_sum = 0;
	int beveridge_cost[b_len]{ 2, 2, 3 }, beveridge_amount[b_len]{ 0, 0, 0 };
	std::string beveridge_name[b_len]{ "Пепси", "Кола", "Спрайт" };
	bool beveridge_disc = false;



	while (true)
	{

		while (true)	//пицца
		{
			while (true)
			{
				std::cout << "Выберете пиццу:" << "\n1) Пепперони (4$)" << "\n2) 4 Сыра (7$)" << "\n3) Маргорита (5$)" << "\n4) Греческая (6$)" << "\n5) Продолжить\n";
				std::cin >> pizza_choice;
				if (pizza_choice == 5)
				{
					break;
				}
				else if (pizza_choice < 1 || pizza_choice > 5)
				{
					std::cerr << "Error: incorrect input choice";
					continue;
				}
				break;
			}

			if (pizza_choice == 5)	//функционал кнопки "продолжить"
			{
				break;
			}

			while (true)
			{
				std::cout << "Введите количество: ";
				std::cin >> amount_p;
				if (amount_p < 0)
				{
					std::cerr << "Error: negative value\n";
					continue;
				}

				pizza_count += amount_p;
				if (pizza_count > 5)	//каждая 5ая пицца бесплатно
				{
					pizza_count %= 5;
					amount_p -= amount_p / 5;
				}
				pizza_amount[pizza_choice - 1] += amount_p;
				break;
			}
		}




		while (true)	//напитки
		{
			while (true)
			{
				std::cout << "Выберете напиток:" << "\n1) Пепси (2$)" << "\n2) Кола (2$)" << "\n3) Спрайт (3$)" << "\n4) Назад" << "\n5) Продолжить\n";
				std::cin >> beveridge_choice;
				if (beveridge_choice == 5 || beveridge_choice == 4)
				{
					break;
				}
				else if (beveridge_choice < 1 || beveridge_choice > 5)
				{
					std::cerr << "Error: incorrect input choice";
					continue;
				}
				break;
			}

			if (beveridge_choice == 5 || beveridge_choice == 4) //функционал кнопки "продолжить" и "назад"
			{
				break;
			}

			while (true)
			{
				std::cout << "Введите количество: ";
				std::cin >> amount_b;
				if (amount_b < 0)
				{
					std::cerr << "Error: negative value\n";
					continue;
				}
				if (beveridge_cost[beveridge_choice - 1] > 2 && amount_b + beveridge_amount[beveridge_choice - 1] > 3)	//скидка на напитки
				{
					beveridge_disc = true;
				}
				beveridge_amount[beveridge_choice - 1] += amount_b;
				break;

			}
		}

		if (beveridge_choice == 4)	//функционал кнопки "назад"
		{
			continue;
		}

		for (int i = 0; i < p_len; i++)	//подсчет суммы пицц
		{
			pizza_sum += pizza_cost[i] * pizza_amount[i];
		}

		for (int i = 0; i < b_len; i++)	//подсчет суммы напитков
		{
			beveridge_sum += beveridge_cost[i] * beveridge_amount[i];
		}

		if (beveridge_disc == true)	//15% на напитки
		{
			beveridge_sum *= 0.85;
		}

		total_sum = pizza_sum + beveridge_sum;

		if (total_sum > 50)
		{
			total_sum *= 0.8;
		}

		//вывод чека
		for (int i = 0; i < p_len; i++)	//вывод пицц
		{
			if (pizza_amount[i] != 0)
			{
				std::cout << pizza_name[i] << " - " << pizza_amount[i] << " - " << pizza_cost[i] << "$\n";
			}
		}
		for (int i = 0; i < b_len; i++)
		{
			if (beveridge_amount[i] != 0)
			{
				std::cout << beveridge_name[i] << " - " << beveridge_amount[i] << " - " << beveridge_cost[i] << "$\n";
			}
		}
		std::cout << "\n" << "Итог: " << total_sum << "$\n";

		break;
	}


	return 0;
}