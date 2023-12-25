#pragma once

#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

class Table
{
protected:
	// границы таблички
	std::string get_separator_line(const std::vector<size_t>& columns_length);
	// расчет длин колонок
	virtual std::vector<size_t> get_columns_length(std::vector<std::vector<std::string>> data, std::vector<std::string> titles) = 0;
	// строка с значениями и титульником таблицы
	std::string get_table_line(std::vector<std::string> item, const size_t& index, std::vector<size_t> columns_length);
	std::string get_title_line(std::vector<std::string> titles, std::vector<size_t> columns_length);
};

#endif