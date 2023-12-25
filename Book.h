#pragma once

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book 
{
private:
	std::string _name;
	std::string _genre;
	double _price;
	int _amount;

public:
	Book() = default;

	Book
	(const std::string& name, const std::string& genre, const double& price, const int& amount)
		: _name(name), _genre(genre), _price(price), _amount(amount) { }

	~Book() { }

	std::string name();

	std::string genre();

	double price();

	int amount();

	// отнимает от количества книг value типо купили
	void buy_some(const int& value);
	
};

#endif /* BOOK_H */