#pragma once

#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <iostream>
#include <fstream>

#include "Serializer.h"

class FileService
{
public:
	// data это набор информации о обькте записанной как вектор пар название поля - значение
	// типо будет {"login", user_login}, {"password", user_password}, {"balance", 3500}
	void write_to_file(std::vector<std::vector<std::pair<std::string, std::string>>> data, const std::string& file_name);
	std::vector<std::vector<std::pair<std::string, std::string>>> read_from_file(const std::string& file_name);
};

#endif