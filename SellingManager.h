#pragma once

#ifndef SELLINGMANAGER_H
#define SELLINGMANAGER_H

#include <iostream>

#include "User.h"
#include "BookShop.h"
#include "CheckTable.h"

class SellingManager
{
private:
	// менюшки для ввода индекса и кол-ва книг для покупки 
	int get_book_index(User& buyer, BookShop& seller);
	int get_book_amount(User& buyer, BookShop& seller, const int& index);
	// проверка достаточно ли балика у юзера и кинг в шопе
	bool can_do_a_deal(User& buyer, BookShop& seller, const int& amount, const int& book_index);
public:
	// вся сделка с менюшками 
	void do_a_deal(User& buyer, BookShop& seller);
};

#endif /* SELLINGMANAGER_H */