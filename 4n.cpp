#include <iostream>

#include "Authorization.h"
#include "DataBaseService.h"
#include "BookShop.h"
#include "SellingManager.h"

int main()
{
	Authorization authorization;
	DataBaseService data_base_service;
	BookShop book_shop;
	SellingManager selling_manager;
	
	// записываем данные из файлов в классы которые их хранят
	data_base_service.unload_accounts();
	data_base_service.unload_administrators();
	data_base_service.unload_books();
	book_shop.change_books_data(data_base_service.get_books_data());
	authorization.change_accounts_data(data_base_service.get_accounts_data());
	authorization.change_admin_data(data_base_service.get_admin_data());
	// 

	auto is_admin = authorization.menu();
	// если типок вышел
	if (is_admin == -1)
	{
		return 0;
	}

	// обновляем данные в файле если челик зарегался
	data_base_service.upload_accounts(authorization.get_accounts_data());

	if (is_admin)
	{
		Administrator* admin = authorization.get_current_administrator();

		bool flag = true;
		while (flag)
		{
			auto choose = admin->menu();

			switch (choose)
			{
			case 1:
				admin->print_catalogue(book_shop);
				break;
			case 2:
				book_shop.add_book(admin->add_book_menu());
				data_base_service.upload_books(book_shop.get_books_data());
				break;
			case 3:
				book_shop.edit_book
				(
					admin->edit_book_menu
					(book_shop.get_books_data(), book_shop.get_catalogue())
				);
				data_base_service.upload_books(book_shop.get_books_data());
				break;
			case 4:
				book_shop.delete_book
				(
					admin->delete_book_menu
					(book_shop.get_catalogue(), book_shop.amount_of_books())
				);
				data_base_service.upload_books(book_shop.get_books_data());
				break;
			case 5:
				flag = false;
				break;
			}
		}
	}
	else
	{
		User* user = authorization.get_current_user();

		bool flag = true;
		while (flag)
		{
			auto choose = user->menu();

			switch (choose)
			{
			case 1:
				user->print_catalogue(book_shop);
				break;
			case 2:
				selling_manager.do_a_deal(*user, book_shop);
				data_base_service.upload_accounts(authorization.get_accounts_data());
				data_base_service.upload_books(book_shop.get_books_data());
				break;
			case 3:
				user->get_balance();
				break;
			case 4:
				user->add_balance();
				data_base_service.upload_accounts(authorization.get_accounts_data());
				break;
			case 5:
				flag = false;
				break;
			}
		}
	}

	data_base_service.upload_accounts(authorization.get_accounts_data());

	return 0;
}