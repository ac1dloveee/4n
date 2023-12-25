#include "Serializer.h"

std::string Serializer::get_field_name(const std::string& serialized_line)
{
	std::string buffer;
	// начинаем считывать после таба
	size_t offset = 4;

	// до пробела
	while (serialized_line[offset] != ' ')
	{
		buffer += serialized_line[offset++];
	}

	return buffer;
}

std::string Serializer::get_field_value(const std::string& serialized_line)
{
	std::string buffer;
	// типо индекс " : " и скипнуть эти 3 символа
	size_t offset = serialized_line.find(" : ") + 3;

	for (; offset < serialized_line.size(); ++offset)
	{
		buffer += serialized_line[offset];
	}

	return buffer;
}

std::vector<std::string> Serializer::serialize(std::vector<std::pair<std::string, std::string>> item)
{
	std::vector<std::string> serialized_item;

	serialized_item.push_back("{");

	for (auto i = 0; i < item.size(); ++i)
	{
		serialized_item.push_back("    " + item[i].first + " : " + item[i].second);
	}

	serialized_item.push_back("}");

	return serialized_item;
}

std::vector<std::vector<std::string>> Serializer::serialize_array(std::vector<std::vector<std::pair<std::string, std::string>>> data)
{
	std::vector<std::vector<std::string>> serialized;

	for (auto i = 0; i < data.size(); ++i)
	{
		serialized.push_back(serialize(data[i]));
	}

	return serialized;
}

std::vector<std::pair<std::string, std::string> > Serializer::deserialize(std::vector<std::string> serialized_item)
{
	std::vector<std::pair<std::string, std::string> > item;

	for (auto i = 0; i < serialized_item.size(); ++i)
	{
		item.push_back
		(
			make_pair
			(
				get_field_name(serialized_item[i]),
				get_field_value(serialized_item[i])
			)
		);
	}

	return item;
}

std::vector<std::vector<std::pair<std::string, std::string> > > Serializer::deserialize_array(std::vector<std::vector<std::string>> serialized)
{
	std::vector<std::vector<std::pair<std::string, std::string> > > data;

	for (auto i = 0; i < serialized.size(); ++i)
	{
		data.push_back(deserialize(serialized[i]));
	}

	return data;
}