#pragma once

#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include <iostream>
#include <vector>
#include <string>

#include "FileService.h"
#include "BookTable.h"

class BookShop 
{
private:
	// список книг
	std::vector<Book> books;
	// пкть к файлу с ассортиментом
	std::string books_path;

public:
	BookShop()
		: books_path("books.txt") {	}

	~BookShop() { }
	// проверка можно ли купить amount книг которые лежат по индексу index
	bool can_sell_books(const int& index, const int& amount);
	// отнять amount книг
	void sell_books(const int& index, const int& amount);
	// фулл прайс за покупку
	double get_full_price(const int& index, const int& amount);
	// таблица с ассортиментом
	std::string get_catalogue();
	// вывести ее
	void print_catalogue();
	// проверка индекса тип не больше ли он чем всего книг
	bool is_valid_index(const int& value);
	//
	void change_books_data(std::vector<Book> _books);    // обновить или считать файл 

	std::vector<Book> get_books_data();
	//

	// сколько всего книг
	int amount_of_books();

	void add_book(const Book& book);
	void edit_book(std::pair<Book, int> value_and_index);
	void delete_book(const int& index);

	// имя книги по индексу
	std::string get_book_name(const size_t& index);
};

#endif /* BOOKSHOP_H */