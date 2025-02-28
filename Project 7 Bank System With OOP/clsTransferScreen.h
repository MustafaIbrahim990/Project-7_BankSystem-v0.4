//class TransferScreen

#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : \n";

		cout << "--------------------------------------------------";
		cout << "\nAccount Number       : " << Client.AccountNumber();
		cout << "\nFull Name            : " << Client.FullName();
		cout << "\nAccount Balance      : " << Client.AccountBalance << " $ ";
		cout << "\n--------------------------------------------------\n";
	}

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = "";

		cout << Message;
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With Account Number [" << AccountNumber << "] is Not Found, Enter another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;

		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidate::ReadDoubleNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "Amount Exceeds The Available, Enter another Amount? ";
			Amount = clsInputValidate::ReadDoubleNumber();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		/*if (!CheckAccessRights(clsUser::enPermissions::))
		{
			return;
		}*/

		_DrawScreenHeader("\t   Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer From : "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To : "));
		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'n';

		cout << "\nAre You Sure You Want to Perform This Operation [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\n\nTransfer Done Successfully : -)\n";
			}
			else
			{
				cout << "\n\nTransfer Falid!\n";
			}
		}
		else
		{
			cout << "\n\nOperaion Was Cancelled.\n";
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}

};