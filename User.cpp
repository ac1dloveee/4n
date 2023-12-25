#include "User.h"

void User::add_balance()
{
	double value = 0.0;

	std::cout << "how much money to transfer: ";
	while (true)
	{
		std::cin >> value;
		if (value <= 0.0)
		{
			std::cout << "you can not transfer negative value or null\n";
			std::cout << "try again: ";
		}
		else
		{
			break;
		}
	}

	_balance += value;

	std::cout << "now your balance equals ";
	std::cout << std::to_string(_balance);
	std::cout << " byn\n";

	//update_accounts();
}

double User::balance()
{
	return _balance;
}

bool User::enough_money(const double& value)
{
	return _balance >= value;
}

void User::buy_books(const double& value)
{
	_balance -= value;
	std::cout << "you spended " << value << " byn. ";
	std::cout << "your current balance: " << _balance << '\n';
}

void User::get_balance()
{
	std::cout << "your balance equals ";
	std::cout << _balance;
	std::cout << " byn\n";
}

int User::menu()
{
	int choose = 0;
	
	while (true)
	{
		std::cout << "1 - display assortiment\n";
		std::cout << "2 - buy a good\n";
		std::cout << "3 - your balance\n";
		std::cout << "4 - top up the balance\n";
		std::cout << "5 - exit\n";
		std::cin >> choose;
		system("cls");

		if (choose < 1 || choose > 5)
		{
			std::cout << "wrong input\n";
		}
		else
		{
			return choose;
		}
	}
}