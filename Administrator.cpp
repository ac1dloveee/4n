#include "Administrator.h"

int Administrator::menu() 
{
	int choose = 0;

	while (true)
	{
		std::cout << "1 - print catalogue\n";
		std::cout << "2 - add book\n";
		std::cout << "3 - edit book\n";
		std::cout << "4 - delete book\n";
		std::cout << "5 - exit\n";

		std::cin >> choose;
		system("cls"); // очистка консоли

		if (choose < 1 || choose > 5)
		{
			std::cout << "wrong input\n";
		}
		else
		{
			return choose;
		}
	}
}

Book Administrator::add_book_menu()
{
	std::string name, genre;
	double price;
	int amount;

	std::cout << "enter name of the book: ";
	// std::cin >> std::ws это чтоб корректно работало
	// тип в буфере ввода остаются \n и оно их считывает и прекращает ввод
	std::getline(std::cin >> std::ws, name);

	std::cout << "enter genre of the book: ";
	std::getline(std::cin >> std::ws, genre);

	while (true)
	{
		std::cout << "enter price of the book: ";
		std::cin >> price;

		if (price > 0.0)
		{
			break;
		}
		system("cls");
		std::cout << "price can't be <= 0. please, try again.\n";
	}

	while (true)
	{
		std::cout << "enter amount of books: ";
		std::cin >> amount;

		if (amount > 0)
		{
			break;
		}
		system("cls");
		std::cout << "amount can't be <= 0. please, try again.\n";
	}

	std::cout << "book " << name << " is succesfully added!\n";

	return Book(name, genre, price, amount); // новая книга
}

std::pair<Book, int> Administrator::edit_book_menu(std::vector<Book> books, const std::string& catalogue)
{
	std::string name, genre, choose;
	double price;
	int index, amount;

	std::cout << "catalogue:\n";
	std::cout << catalogue << '\n';

	while (true)
	{
		std::cout << "enter number of book to edit: ";
		std::cin >> index;

		if (index - 1 >= 0 && index - 1 < books.size())
		{
			break;
		}
		system("cls");
		std::cout << "catalogue:\n";
		std::cout << catalogue << '\n';

		std::cout << "wrong index. please, try again.\n";
	}

	std::cout << "name of the book: " << books[index - 1].name() << '\n';
	std::cout << "edit? [y/n]\n";
	std::cin >> choose;

	if (choose == "y")
	{
		std::cout << "enter new name: ";
		std::getline(std::cin >> std::ws, name);
	}
	else
	{
		name = books[index - 1].name();
	}

	choose.clear();
	std::cout << "genre of the book: " << books[index - 1].genre() << '\n';
	std::cout << "edit? [y/n]\n";
	std::cin >> choose;

	if (choose == "y")
	{
		std::cout << "enter new genre: ";
		std::getline(std::cin >> std::ws, genre);
	}
	else
	{
		genre = books[index - 1].genre();
	}

	choose.clear();
	std::cout << "price of the book: " << books[index - 1].price() << '\n';
	std::cout << "edit? [y/n]\n";
	std::cin >> choose;

	if (choose == "y")
	{
		while (true)
		{
			std::cout << "enter new price: ";
			std::cin >> price;

			if (price > 0.0)
			{
				break;
			}
			system("cls");

			std::cout << "price can't be <= 0. please, try again.\n";
		}
	}
	else
	{
		price = books[index - 1].price();
	}

	choose.clear();
	std::cout << "amount of the book: " << books[index - 1].amount() << '\n';
	std::cout << "edit? [y/n]\n";
	std::cin >> choose;

	if (choose == "y")
	{
		while (true)
		{
			std::cout << "enter new amount: ";
			std::cin >> amount;

			if (amount > 0)
			{
				break;
			}
			system("cls");

			std::cout << "amount can't be <= 0. please, try again.\n";
		}
	}
	else
	{
		amount = books[index - 1].amount();
	}

	std::cout << "book is edited!\n";
	return std::make_pair(Book(name, genre, price, amount), index - 1);
}

int Administrator::delete_book_menu(const std::string& catalogue, const int& size)
{
	int index = 0;

	std::cout << "catalogue:\n";
	std::cout << catalogue << '\n';

	while (true)
	{
		std::cout << "enter number of book to delete: ";
		std::cin >> index;

		if (index - 1 >= 0 && index - 1 < size)
		{
			break;
		}

		system("cls");
		std::cout << "catalogue:\n";
		std::cout << catalogue << '\n';
		std::cout << "wrong index. please, try again.\n";
	}

	return index - 1;
}