#include "Table.h"

std::string 
Table::get_separator_line(const std::vector<size_t>& columns_length)
{
	std::string separator_line;

	for (auto i = 0; i < columns_length.size(); ++i)
	{
		separator_line += '+';
		// строка из columns_length[i] минусов ('-')
		separator_line += std::string(columns_length[i], '-');
	}

	return separator_line + '+' + '\n';
}

std::string 
Table::get_table_line(std::vector<std::string> item, const size_t& index, std::vector<size_t> columns_length)
{
	std::string line;

	line += '|' + std::to_string(index) + std::string(columns_length[0] - std::to_string(index).length(), ' ');

	for (auto i = 0; i < item.size(); ++i)
	{
		line += '|' + item[i] + std::string(columns_length[1 + i] - item[i].length(), ' ');
	}

	return line + '|' + '\n';
}

std::string 
Table::get_title_line(std::vector<std::string> titles, std::vector<size_t> columns_length)
{
	std::string line;

	for (auto i = 0; i < titles.size(); ++i)
	{
		line += '|' + titles[i] + std::string(columns_length[i] - titles[i].length(), ' ');
	}

	return line + '|' + '\n';
}