//class TransactionsScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenueoptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eMainMenue = 6 };

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\n" << setw(40) << left << "" << "Press Any Key to Go Back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static short _ReadTransactionsMenueOptions()
	{
		short ChooseClient = 0;

		cout << setw(40) << left << "" << "Choose What Do You Want to Do [1 to 6]? ";
		ChooseClient = clsInputValidate::ReadShortNumberBetween(1, 6, "\t\t\t\t\tChoose What Do You Want to Do [1 to 6]? ");
		return ChooseClient;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\n\nDeposit Screen Will Be here....";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\n\nWithdraw Screen Will Be here....";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n\nTotal Balances Screen Will Be here....";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\n\nTransfer Screen Will Be here....";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\n\nTransfer Log Screen Will Be here....";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionsMenueOptions(enTransactionsMenueoptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case clsTransactionsScreen::eDeposit:
		{
			system("Cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eWithdraw:
		{
			system("Cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTotalBalances:
		{
			system("Cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransfer:
		{
			system("Cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eTransferLog:
		{
			system("Cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case clsTransactionsScreen::eMainMenue:
		{

		}
		};
	}

public:

	static void ShowTransactionsMenue()
	{
		system("Cls");

		if (!CheckAccessRights(clsUser::enPermissions::pTransaction))
		{
			return;
		}

		_DrawScreenHeader("\t  Transactions Menue Screen");

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;
		cout << setw(40) << left << "" << "\t     Transactions Menue" << endl;
		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		cout << setw(40) << left << "" << "\t[1] Deposit." << endl;
		cout << setw(40) << left << "" << "\t[2] Withdraw." << endl;
		cout << setw(40) << left << "" << "\t[3] Total Balances." << endl;
		cout << setw(40) << left << "" << "\t[4] Transfer." << endl;
		cout << setw(40) << left << "" << "\t[5] Transfer Log." << endl;
		cout << setw(40) << left << "" << "\t[6] Main Menue." << endl;

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		_PerformTransactionsMenueOptions((enTransactionsMenueoptions)_ReadTransactionsMenueOptions());
	}
};