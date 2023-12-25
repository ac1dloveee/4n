#pragma once

#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <map>
#include <string>
#include <vector>

#include "User.h"
#include "Administrator.h"
#include "Book.h"
#include "FileService.h"

// класс тип для работы с файлами с данными
class DataBaseService
{
private:
	std::map<std::string, std::pair<std::string, User>> accounts;
	std::map<std::string, std::pair<std::string, Administrator>> admins;
	std::vector<Book> books;
	std::string users_path;
	std::string books_path;
	std::string admin_path;

public:
	DataBaseService() 
		: users_path("accounts.txt"), books_path("books.txt"), admin_path("admin.txt") {}
	~DataBaseService() {}

	// загрузить
	void upload_accounts(std::map<std::string, std::pair<std::string, User>> accounts);
	void upload_books(std::vector<Book> books);
	//

	// выгрузить
	void unload_accounts();
	void unload_administrators();
	void unload_books();
	//

	// это чтоб обновлять классы authorization и bookshop после изменений
	std::map<std::string, std::pair<std::string, User>> get_accounts_data();
	std::map<std::string, std::pair<std::string, Administrator>> get_admin_data();
	std::vector<Book> get_books_data();
};

#endif /* DATABASESERVICE_H */