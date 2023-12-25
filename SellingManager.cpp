#include "SellingManager.h"

bool SellingManager::can_do_a_deal(User& buyer, BookShop& seller, const int& amount, const int& book_index)
{
	if (buyer.enough_money(seller.get_full_price(book_index, amount))) // can buy
	{
		return true;
	}

	return false; 
}

int SellingManager::get_book_index(User& buyer, BookShop& seller)
{
	seller.print_catalogue();
	int index = 0;

	std::cout << "enter number of book you want to buy: ";
	while (true)
	{
		std::cin >> index;

		if (seller.is_valid_index(index))
		{
			break;
		}

		std::cout << "wrong index, try again: ";
	}

	return index;
}

int SellingManager::get_book_amount(User& buyer, BookShop& seller, const int& index)
{
	int amount = 0;

	while (true)
	{
		std::cin >> amount;

		if (seller.can_sell_books(index, amount))
		{
			break;
		}

		std::cout << "we are sorry, but we do not have so much books.\n";
		std::cout << "please, make a choice again: ";
	}

	return amount;
}

void SellingManager::do_a_deal(User& buyer, BookShop& seller)
{
	auto index = get_book_index(buyer, seller);

	std::cout << "good choice! now enter amount of books to buy: ";

	auto amount = get_book_amount(buyer, seller, index);

	while (!can_do_a_deal(buyer, seller, amount, index))
	{
		system("cls");
		seller.print_catalogue();

		std::cout << "you don't have enough money to buy\n";
		std::cout << "top up your balance or buy less books\n";

		std::cout << "1 - top up your balance\n";
		std::cout << "2 - choose another amount\n";
		std::cout << "3 - do not buy books\n";
		std::string choose;
		std::cin >> choose;

		if (choose == "1")
		{
			buyer.add_balance();
		}
		else if (choose == "2")
		{
			std::cout << "enter new amount: ";
			amount = get_book_amount(buyer, seller, index);
		}
		else if (choose == "3")
		{
			system("cls");
			return;
		}
	}

	system("cls");

	double full_price = seller.get_full_price(index, amount);

	seller.sell_books(index, amount);
	buyer.buy_books(full_price);

	std::cout << "deal has been completed successfully!\n";

	std::vector<std::string> titles = { "    Check    ", "Name", "Bought: ", "Full Price: "};
	std::vector<std::string> name_vector(1, seller.get_book_name(index));
	std::vector<int> amount_vector(1, amount);
	std::vector<double> full_price_vector(1, full_price);

	CheckTable check_table;
	auto check = check_table.create_table(name_vector, amount_vector, full_price_vector, titles);

	std::cout << "your check:\n";
	std::cout << check << '\n';
}
