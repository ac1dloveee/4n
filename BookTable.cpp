#include "BookTable.h"

std::vector<std::vector<std::string>> BookTable::books_to_string(std::vector<Book>& data)
{
	std::vector<std::vector<std::string>> books;
	std::vector<std::string> buffer;

	// записываем данные о книге в вектор строк и добавляем в весь каталог
	for (auto i = 0; i < data.size(); ++i)
	{
		buffer.push_back(data[i].name());
		buffer.push_back(data[i].genre());
		buffer.push_back(std::to_string(data[i].price()));
		buffer.push_back(std::to_string(data[i].amount()));


		books.push_back(buffer);
		buffer.clear();
	}

	return books;
}

std::vector<size_t>
BookTable::get_columns_length(std::vector<std::vector<std::string>> data, std::vector<std::string> titles)
{
	std::vector<size_t> columns_length(titles.size());

	for (auto i = 0; i < titles.size(); ++i)
	{
		// начальные значения
		columns_length[i] = titles[i].length();
	}

	for (auto i = 0; i < data.size(); ++i)
	{
		columns_length[0] = std::max(columns_length[0], std::to_string(i).length());
		for (auto j = 0; j < data[i].size(); ++j)
		{
			// 1 + j потому что первый уже записан вне цикла
			columns_length[1 + j] = std::max(columns_length[1 + j], data[i][j].length());
		}
	}

	return columns_length;
}

std::string BookTable::create_table(std::vector<Book> data, std::vector<std::string> titles)
{
	auto books = books_to_string(data);
	auto columns_length = get_columns_length(books, titles);
	auto separator_line = get_separator_line(columns_length);
	std::string table;
	std::string buffer;

	// построчно строим таблицу
	table += separator_line;
	table += get_title_line(titles, columns_length);

	for (auto i = 0; i < books.size(); ++i)
	{
		table += separator_line;
		table += get_table_line(books[i], i + 1, columns_length);
	}

	return table + separator_line;
}