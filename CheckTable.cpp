#include "CheckTable.h"

std::vector<std::vector<std::string>> CheckTable::data_to_string
(
	std::vector<std::string>& names,
	std::vector<int>& amount,
	std::vector<double>& full_price,
	std::vector<std::string>& titles
)
{
	// вектор на 3 вектора строк
	// в нем все сторки таблицы кроме титульной
	std::vector<std::vector<std::string>> data(3);

	for (auto i = 0; i < data.size(); ++i)
	{
		// тут записываем реальные названия полей
		data[i].push_back(titles[i + 1]);
	}
	for (auto i = 0; i < names.size(); ++i)
	{
		// тут их значения
		data[0].push_back(names[i]);
		data[1].push_back(std::to_string(amount[i]));
		data[2].push_back(std::to_string(full_price[i]));
	}

	return data;
}

std::vector<size_t> CheckTable::get_columns_length(std::vector<std::vector<std::string>> data, std::vector<std::string> titles)
{
	std::vector<size_t> columns_length(titles.size());

	for (auto i = 0; i < titles.size(); ++i)
	{
		// начальные значения
		columns_length[i] = titles[i].length();
	}

	for (auto i = 0; i < data.size(); ++i)
	{
		for (auto j = 0; j < titles.size(); ++j)
		{
			columns_length[j] = std::max(columns_length[j], data[i][j].length());
		}
	}

	// по итогу тут максимальные значения длин для каждой строки таблицы
	return columns_length;
}

std::string
CheckTable::get_table_line(std::vector<std::string>& item, std::vector<size_t>& columns_length)
{
	std::string line;

	// std::string(columns_length[i] - item[i].length(), ' ') - строка с пробелами 
	// которое надо добавить чтоб она имела длину как у максимальной
	for (auto i = 0; i < item.size(); ++i)
	{
		line += '|' + item[i] + std::string(columns_length[i] - item[i].length(), ' ');
	}

	return line + '|' + '\n';
}

std::string
CheckTable::create_table
(
	std::vector<std::string>& names,
	std::vector<int>& amount,
	std::vector<double>& full_price,
	std::vector<std::string>& titles
)
{
	auto data = data_to_string(names, amount, full_price, titles);
	std::string table, buffer;
	std::vector<std::string> _titles(names.size() + 1, "");
	_titles[0] = titles[0];

	auto columns_length = get_columns_length(data, _titles);
	auto separator_line = get_separator_line(columns_length);

	table += separator_line;
	table += get_title_line(_titles, columns_length);

	for (auto i = 0; i < data.size(); ++i)
	{
		table += separator_line;
		table += get_table_line(data[i], columns_length);
	}

	return table + separator_line;
}