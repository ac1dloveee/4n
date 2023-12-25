#pragma once

#ifndef ABSTRACT_USER
#define ABSTRACT_USER

#include <string>

#include "BookShop.h"

class AbstractUser
{
protected:
	std::string _login;
	std::string _password;
	
public:
	AbstractUser()
		: _login(), _password() { }

	AbstractUser(const std::string& login, const std::string& password)
		: _login(login), _password(password) { }

	~AbstractUser() { }

	virtual int menu() = 0;

	void print_catalogue(BookShop& book_shop);
};

#endif /* ABSTRACT_USER.H */