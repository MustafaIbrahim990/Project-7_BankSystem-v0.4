// class FindClientScreen

#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsPerson.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\t   Find Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With Account Number [" << AccountNumber << "] is Not Found, Enter another One? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (!Client.IsEmpty())
		{
			cout << "\nClient Found : -)\n";
		}
		else
		{
			cout << "\nClient is Not Found!\n";
		}
		_PrintClient(Client);
	}
};