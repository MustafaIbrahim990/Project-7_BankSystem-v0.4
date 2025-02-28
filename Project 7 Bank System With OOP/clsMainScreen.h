//class MainScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsListClientsScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpDateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyScreen.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpDateClient = 4, eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10 };

	static void _GoBackToMainMenue()
	{
		cout << "\n\n" << setw(40) << left << "" << "Press Any Key to Go Back to Main Menue...";
		system("pause>0");
		ShowMainMenue();
	}

	static short _ReadMainMenueOptions()
	{
		short ChooseClient = 0;

		cout << setw(40) << left << "" << "Choose What Do You Want to Do [1 to 10]? ";
		ChooseClient = clsInputValidate::ReadShortNumberBetween(1, 10, "\t\t\t\t\tChoose What Do You Want to Do [1 to 10]? ");
		return ChooseClient;
	}

	static void _ShowListClientsScreen()
	{
		//cout << "\n\nList Clients Screen Will Be here....";
		clsListClientsScreen::ShowListClientsScreen();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "\n\nAdd New Client Screen Will Be here....";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\n\nDelete Client Screen Will Be here....";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpDateClientScreen()
	{
		//cout << "\n\nUpDate Client Info Screen Will Be here....";
		clsUpDateClientScreen::ShowUpDateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\n\nFind Client Screen Will Be here....";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		//cout << "\n\nTransactions Screen Will Be here....";
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "\n\nManage Users Screen Will Be here....";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\n\nLogin Register Screen Will Be here....";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\n\nCurrency Exchange Screen Will Be here....";
		clsCurrencyScreen::ShowCurrencyMenue();
	}

	static void _ShowLogOutScreen()
	{
		//cout << "\n\nLogout Screen Will Be here....";
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOptions)
	{
		switch (MainMenueOptions)
		{
		case clsMainScreen::eListClients:
		{
			system("Cls");
			_ShowListClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eAddNewClient:
		{
			system("Cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eDeleteClient:
		{
			system("Cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eUpDateClient:
		{
			system("Cls");
			_ShowUpDateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eFindClient:
		{
			system("Cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eTransactions:
		{
			//system("Cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eManageUsers:
		{
			//system("Cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eLoginRegister:
		{
			system("Cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eCurrencyExchange:
		{
			system("Cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsMainScreen::eLogout:
		{
			system("Cls");
			_ShowLogOutScreen();
			break;
		}
		};
	}

public:

	static void ShowMainMenue()
	{
		system("Cls");
		_DrawScreenHeader("\t\tMain Menue Screen");

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;
		cout << setw(40) << left << "" << "\t\t   Main Menue" << endl;
		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		cout << setw(40) << left << "" << "\t[1] List Clients." << endl;
		cout << setw(40) << left << "" << "\t[2] Add New Client." << endl;
		cout << setw(40) << left << "" << "\t[3] Delete Client." << endl;
		cout << setw(40) << left << "" << "\t[4] UpDate Client." << endl;
		cout << setw(40) << left << "" << "\t[5] Find Client." << endl;
		cout << setw(40) << left << "" << "\t[6] Transactions." << endl;
		cout << setw(40) << left << "" << "\t[7] Manage Users." << endl;
		cout << setw(40) << left << "" << "\t[8] Login Register." << endl;
		cout << setw(40) << left << "" << "\t[9] Currency Exchange." << endl;
		cout << setw(40) << left << "" << "\t[10] Logout." << endl;

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		_PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOptions());
	}

};