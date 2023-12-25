#pragma once

#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "User.h"
#include "Administrator.h"

class Authorization
{
private:
	std::string users_path; // путь к файлу с логинами и паролями юзеров
	std::string admin_path; // путь к файлу с логинами и паролями админов
	// мап это крч структурка содержит <ключ, значение>
	// она написана на дереве (красно-черном) \\ хз мб понадобится
	// тут ключ это логин пользователя
	// значение пара пароль и сам обьект юзерв
	// тут мап так как он удобен когда надо найти чето по ключу 
	std::map<std::string, std::pair<std::string, User>> accounts; 
	std::map<std::string, std::pair<std::string, Administrator>> admins;

	// для возврата в мейн обьекта текущего юзера / админа
	User* current_user;
	Administrator* current_administrator;

	// функция для захода в существующий акк
	// --> 1 - зашел админ, 0 - юзер
	// работает пока типок не зайдет в акк
	int authorize();
	// рег нового юзера
	void registration();
	// проверка логина и пароля с акком админа
	int check_admin_login_and_password(const std::string& login, const std::string& password);
	// проверка логина и пароля с акками юзеров
	int check_login_and_password(const std::string& login, const std::string& password);
	// установить обьекты юзеров и админов на чей акк зашли
	void set_current_user(const std::string& login, const std::string& password);
	void set_current_administrator(const std::string& login, const std::string& administrator);

public:
	Authorization()
		: users_path("accounts_db.txt"), admin_path("admin.txt"), current_administrator(nullptr), current_user(nullptr) { }

	~Authorization() { }

	// главное меню с регой или авторизацикй
	int menu();
	// вернуть обьекты юзеров и админов на чей акк зашли
	User* get_current_user();
	Administrator* get_current_administrator();
	// переписать дату акков в мап из класса
	// это чтоб то че в файле попало в этот класс
	// два ласт метода чтоб обновить файл в случае реги нового акка 
	void change_accounts_data(std::map<std::string, std::pair<std::string, User>> _accounts);
	void change_admin_data(std::map<std::string, std::pair<std::string, Administrator>> _admins);
	std::map<std::string, std::pair<std::string, User>> get_accounts_data();
	std::map<std::string, std::pair<std::string, Administrator>> get_admins_data();
};

#endif