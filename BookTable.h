#pragma once

#ifndef BOOKTABLE_H
#define BOOKTABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "Table.h"

#include "Book.h"

class BookTable : public Table
{
private:
	std::vector<std::vector<std::string>> books_to_string(std::vector<Book>& data);
	std::vector<size_t> get_columns_length(std::vector<std::vector<std::string>> data, std::vector<std::string> titles) override;
public:
	BookTable() = default;

	~BookTable() = default;

	std::string create_table(std::vector<Book> data, std::vector<std::string> titles);
};

#endif