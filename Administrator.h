#pragma once

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <iostream>
#include <vector>

#include "Book.h"
#include "AbstractUser.h"

class Administrator : public AbstractUser
{
public:
	Administrator(const std::string& login, const std::string& password)
		: AbstractUser(login, password) { }

	~Administrator() { }

	// главная менюшка с выбором че делать
	int menu() override;
	// меню добавления, возвращает новый обьект книги
	Book add_book_menu();
	// меню изменения, возвращает новый обьект книги и индекс какую книгу менять
	std::pair<Book, int> edit_book_menu(std::vector<Book> books, const std::string& catalogue);
	// меню удаления, возвращает че удалять
	int delete_book_menu(const std::string& catalogue, const int& size);
};

#endif