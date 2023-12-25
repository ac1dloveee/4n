#pragma once

#ifndef CHECKTABLE_H
#define CHECKTABLE_H

#include <vector>
#include <string>

#include "Table.h"

class CheckTable : public Table
{
private:
	std::string get_table_line
	(
		std::vector<std::string>& item,
		std::vector<size_t>& columns_length
	);

	std::vector<std::vector<std::string>> data_to_string 
	(
		std::vector<std::string>& names,
		std::vector<int>& amount,
		std::vector<double>& full_price,
		std::vector<std::string>& titles
	);

	std::vector<size_t> get_columns_length 
	(
		std::vector<std::vector<std::string>> data,
		std::vector<std::string> titles
	) override;

public:
	std::string create_table 
	(
		std::vector<std::string>& names,
		std::vector<int>& amount,
		std::vector<double>& full_price,
		std::vector<std::string>& titles
	);

};

#endif