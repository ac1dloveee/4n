#pragma once

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include "AbstractUser.h"

class User : public AbstractUser
{
private:
	double _balance;
	std::string users_path;
public:
	// Конструктор по умолчанию
	User()
		: AbstractUser(), _balance(0.0), users_path("accounts_db.txt") { }

	// Конструктор
	User(const std::string& login, const std::string& password, const double& balance)
		: AbstractUser(login, password), _balance(balance), users_path("accounts_db.txt") { }

	// Деструктор
	~User() = default;

	// положить балик
	void add_balance();
	// значение балика
	double balance();
	// хватает ли бабок 
	bool enough_money(const double& value);
	// отнять балик и вывести оставшийся
	void buy_books(const double& value);
	// вывети балик
	void get_balance();

	int menu() override;

};
	
#endif /* USER_H */