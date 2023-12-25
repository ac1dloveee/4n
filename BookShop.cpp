#include "BookShop.h"

bool BookShop::can_sell_books(const int& index, const int& amount)
{
	return this->books[index - 1].amount() >= amount;
}

void BookShop::sell_books(const int& index, const int& amount)
{
	this->books[index - 1].buy_some(amount);
}

double BookShop::get_full_price(const int& index, const int& amount)
{
	return this->books[index - 1].price() * amount;
}

std::string BookShop::get_catalogue()
{
	BookTable book_table;
	// для таблицы
	std::vector<std::string> titles = { "", "Genre", "Name", "Price", "Amount" };

	return book_table.create_table(books, titles);
}

void BookShop::print_catalogue()
{
	std::cout << "catalogue:\n";
	std::cout << this->get_catalogue() << '\n';
}

bool BookShop::is_valid_index(const int& value)
{
	return (value > 0) && (value - 1 < books.size());
}

void BookShop::change_books_data(std::vector<Book> _books)
{
	books = _books;
}

std::vector<Book> BookShop::get_books_data()
{
	return books;
}

void BookShop::add_book(const Book& book)
{
	books.push_back(book);
}

void BookShop::edit_book(std::pair<Book, int> value_and_index)
{
	books[value_and_index.second] = value_and_index.first;
}

int BookShop::amount_of_books()
{
	return books.size();
}

void BookShop::delete_book(const int& index)
{
	books.erase(books.begin() + index);
}

std::string BookShop::get_book_name(const size_t& index)
{
	return books[index - 1].name();
}