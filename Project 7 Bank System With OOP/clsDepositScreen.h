// class DepositScreen

#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDepositScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : \n";

		cout << "--------------------------------------------------";
		cout << "\nAccount Number       : " << Client.AccountNumber();
		cout << "\nFirst Name           : " << Client.FirstName;
		cout << "\nLast Name            : " << Client.LastName;
		cout << "\nEmail                : " << Client.Email;
		cout << "\nPhone                : " << Client.Phone;
		cout << "\nPIN Code             : " << Client.PINCode;
		cout << "\nAccount Balance      : " << Client.AccountBalance << " $ ";
		cout << "\n--------------------------------------------------\n";
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t\tDeposit Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With Account Number [" << AccountNumber << "] is Not Found, Enter another One? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;

		cout << "Please Enter Deposit Amount? ";
		Amount = clsInputValidate::ReadDoubleNumber();

		char ClientAnswer = 'n';

		cout << "\nAre You Sure You Want to Perform This Transactions [Y/N]? ";
		cin >> ClientAnswer;

		if (toupper(ClientAnswer) == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\n\nAmount Depositd Successfully. New Balance is : " << Client.AccountBalance << " $ \n";
		}
		else
		{
			cout << "\nOperaion Was Cancelled.\n";
		}
	}

};