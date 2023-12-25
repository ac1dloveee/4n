#include "DataBaseService.h"

void DataBaseService::upload_accounts(std::map<std::string, std::pair<std::string, User>> _accounts)
{
	FileService file_service;
	std::vector<std::vector<std::pair<std::string, std::string>>> accounts_data;
	std::vector<std::pair<std::string, std::string>> account_data;

	// запись каждого аккаунта при помощи итератора 
	for (auto account = _accounts.begin(); account != _accounts.end(); ++account)
	{
		account_data.push_back
		(
			make_pair
			("login", account->first)
		);

		account_data.push_back
		(
			make_pair
			("password", account->second.first)
		);

		account_data.push_back
		(
			make_pair
			("balance", std::to_string(account->second.second.balance()))
		);

		accounts_data.push_back(account_data);
		account_data.clear();
	}

	file_service.write_to_file(accounts_data, users_path);
}

void DataBaseService::unload_accounts()
{
	FileService file_service;
	auto data = file_service.read_from_file(users_path);
	std::string login, password;
	double balance;

	for (auto i = 0; i < data.size(); ++i)
	{
		login = data[i][0].second;
		password = data[i][1].second;
		balance = std::stod(data[i][2].second);

		accounts.insert
		(
			make_pair
			(
				login,
				make_pair(password, User(login, password, balance))
			)
		);
	}
}

void DataBaseService::unload_administrators()
{
	FileService file_service;
	auto data = file_service.read_from_file(admin_path);
	std::string login, password;

	for (auto i = 0; i < data.size(); ++i)
	{
		login = data[i][0].second;
		password = data[i][1].second;

		admins.insert
		(
			make_pair
			(
				login,
				make_pair(password, Administrator(login, password))
			)
		);
	}
}

void DataBaseService::upload_books(std::vector<Book> _books)
{
	FileService file_service;
	std::vector<std::vector<std::pair<std::string, std::string>>> books_data;
	std::vector<std::pair<std::string, std::string>> book_data;

	for (auto i = 0; i < _books.size(); ++i)
	{
		// если на складе не осталось книг
		if (_books[i].amount() < 1)
		{
			continue;
		}

		book_data.push_back
		(
			make_pair
			("name", _books[i].name())
		);

		book_data.push_back
		(
			make_pair
			("genre", _books[i].genre())
		);

		book_data.push_back
		(
			make_pair
			("price", std::to_string(_books[i].price()))
		);

		book_data.push_back
		(
			make_pair
			("amount", std::to_string(_books[i].amount()))
		);

		books_data.push_back(book_data);
		book_data.clear();
	}

	file_service.write_to_file(books_data, books_path);
}

void DataBaseService::unload_books()
{
	FileService file_service;
	auto data = file_service.read_from_file(books_path);
	std::string name, genre;
	double price;
	int amount;

	for (auto i = 0; i < data.size(); ++i)
	{
		name = data[i][0].second;
		genre = data[i][1].second;
		price = std::stod(data[i][2].second);
		amount = std::stoi(data[i][3].second);

		// добавление в вектор но обьект класса книга создается внутри этой функции
		// можно заменить на books.push_back(Book(name, genre, price, amount));
		books.emplace_back
		(
			name, genre, price, amount
		);
	}
}

std::map<std::string, std::pair<std::string, User>> DataBaseService::get_accounts_data()
{
	return accounts;
}

std::map<std::string, std::pair<std::string, Administrator>> DataBaseService::get_admin_data()
{
	return admins;
}

std::vector<Book> DataBaseService::get_books_data()
{
	return books;
}