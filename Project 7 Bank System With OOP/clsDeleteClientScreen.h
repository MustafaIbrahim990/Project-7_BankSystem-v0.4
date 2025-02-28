// class DeleteClientScreen

#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsPerson.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t   Delete Client Screen");

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

		char Answer = 'n';

		cout << "Are You Sure You Want to Delete This Client [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nAccount Deleted Successfully : -)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Account Was Not Deleted!";
			}

			
		}
	}

};