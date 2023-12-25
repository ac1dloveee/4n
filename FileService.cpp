#include "FileService.h"

void FileService::write_to_file(std::vector<std::vector<std::pair<std::string, std::string>> > data, const std::string& file_name)
{
	Serializer serializer;
	// получение вектора со строками в формате (типо json)
	auto serialized_data = serializer.serialize_array(data);
	std::ofstream file;

	file.open(file_name);
	if (!file)
	{
		std::cout << "can't open the file\n";
		return;
	}

	for (auto i = 0; i < serialized_data.size(); ++i)
	{
		for (auto j = 0; j < serialized_data[i].size(); ++j)
		{
			file << serialized_data[i][j] << '\n';
		}
	}

	file.close();
}

std::vector<std::vector<std::pair<std::string, std::string>>> FileService::read_from_file(const std::string& file_name)
{
	Serializer serializer;
	std::ifstream file;
	std::string buffer;
	std::vector<std::string> item;
	std::vector<std::vector<std::string>> serialized_data;

	file.open(file_name);
	if (!file)
	{
		std::cout << "can't open the file\n";
		return std::vector<std::vector<std::pair<std::string, std::string>>>(); // пустой вектор
	}

	while (getline(file, buffer))
	{
		if (buffer != "{" && buffer != "}")
		{
			// пушим только строки с данными
			item.push_back(buffer);
		}

		if (buffer == "}")
		{
			serialized_data.push_back(item);
			item.clear();
		}
	}

	file.close();

	return serializer.deserialize_array(serialized_data);
}