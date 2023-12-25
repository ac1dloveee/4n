#pragma once

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <string>
#include <iostream>
#include <vector>

class Serializer 
{
private:
	// возвращают из строки в файле название и значение поля
	std::string get_field_name(const std::string& serialized_line);
	std::string get_field_value(const std::string& serialized_line);
	//

public:
	// типо форматировать один обькет
	std::vector<std::string> serialize(std::vector<std::pair<std::string, std::string>> item);
	// тут целый массив
	std::vector<std::vector<std::string>> serialize_array(std::vector<std::vector<std::pair<std::string, std::string>>> data);
	// тут расформатировать
	std::vector<std::pair<std::string, std::string>> deserialize(std::vector<std::string> serialized_item);
	std::vector<std::vector<std::pair<std::string, std::string>>> deserialize_array(std::vector<std::vector<std::string>> serialized);
};

#endif