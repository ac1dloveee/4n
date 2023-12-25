#include "Authorization.h"

int Authorization::check_admin_login_and_password(const std::string& login, const std::string& password)
{
	// find возвращает итератор на найденный логин
	// если нет логина такого то итератор на конец (admins.end())
	// итератор это механизм при помощи которого можно работать со структурой данных
	// он предоставляет доступ к элементам структуры и то что они хранят
	auto search_login = admins.find(login);

	if (search_login == admins.end())
	{
		system("cls");
		std::cout << "wrong login\n";
		return 0;
	}

	// search_login->second это пара пароль админ
	if (search_login->second.first != password)
	{
		return 0;
	}

	return -1;
}

int Authorization::check_login_and_password(const std::string& login, const std::string& password)
{
	auto search_login = accounts.find(login);

	if (search_login == accounts.end())
	{
		return check_admin_login_and_password(login, password);
	}

	if (search_login->second.first != password)
	{
		system("cls");
		std::cout << "wrong password\n";
		return 0;
	}

	return 1;
}

void Authorization::set_current_user(const std::string& login, const std::string& password)
{
	// & = берем адрес в памяти
	current_user = &accounts.find(login)->second.second;
}

void Authorization::set_current_administrator(const std::string& login, const std::string& administrator)
{
	current_administrator = &admins.find(login)->second.second;
}

int Authorization::authorize()
{
	std::string login, password;

	std::cout << "login: ";
	std::cin >> login;

	std::cout << "password: ";
	std::cin >> password;

	int output = check_login_and_password(login, password);

	if (output == 1) // user
	{
		system("cls");
		std::cout << "you are succesfully logged in!\n";
		set_current_user(login, password);
		return 0;
	}
	else if (output == -1) // admin
	{
		system("cls");
		std::cout << "you logged in as admin!\n";
		set_current_administrator(login, password);
		return 1;
	}

	// не сошлось
	return menu();
}

void Authorization::registration()
{
	std::string login, password;

	while (true)
	{
		std::cout << "enter your login: ";
		std::cin >> login;

		std::cout << "enter your password: ";
		std::cin >> password;

		// проверка на наличие введенного логина в базе
		// в случае с мапом так и нельзя сделать
		// чтоб было два элемента с одним ключом (логином)
		if (accounts.find(login) == accounts.end())
		{
			break;
		}

		system("cls");
		std::cout << "this login was already used\n";
	}
	User user(login, password, 0);

	accounts.insert
	(
		// создает pair
		make_pair
		(login, make_pair(password, user))
	);
	std::cout << "account created!\n";
	set_current_user(login, password);
}

int Authorization::menu()
{
	std::cout << "1 - create new account\n";
	std::cout << "2 - log in created account\n";
	std::cout << "3 - exit\n";

	int choose = 0;
	bool flag = true;
	while (flag)
	{
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			registration();
			return 0; // юзер
		case 2:
			return authorize(); // админ или юзер
		case 3:
			return -1; // выход из проги
		default:
			std::cout << "wrong input\n";
		}
	}

	return -1;
}

User* Authorization::get_current_user()
{
	return current_user;
}

Administrator* Authorization::get_current_administrator()
{
	return current_administrator;
}

void Authorization::change_accounts_data(std::map<std::string, std::pair<std::string, User>> _accounts)
{
	accounts = _accounts;
}

void Authorization::change_admin_data(std::map<std::string, std::pair<std::string, Administrator>> _admins)
{
	admins = _admins;
}

std::map<std::string, std::pair<std::string, User>>  Authorization::get_accounts_data()
{
	return accounts;
}

std::map<std::string, std::pair<std::string, Administrator>>  Authorization::get_admins_data()
{
	return admins;
}