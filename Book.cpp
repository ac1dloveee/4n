#include "Book.h"

std::string Book::name()
{
	return this->_name;
}

std::string Book::genre()
{
	return this->_genre;
}

double Book::price()
{
	return this->_price;
}

int Book::amount()
{
	return this->_amount;
}

void Book::buy_some(const int& value)
{
	this->_amount -= value;
}