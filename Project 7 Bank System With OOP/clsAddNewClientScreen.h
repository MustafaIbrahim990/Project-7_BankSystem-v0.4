//class AddNewClientScreen

#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsPerson.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name   : ";
		Client.FirstName = clsInputValidate::ReadString();
		 
		cout << "Enter Last Name    : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter Email        : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Phone        : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PIN Code     : ";
		Client.PINCode = clsInputValidate::ReadString();

		cout << "Enter Acc. Balance : ";
		Client.AccountBalance = clsInputValidate::ReadDoubleNumber();
	}

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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t   Add New Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client With Account Number [" << AccountNumber << "] is Already Used, Enter another One? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		
		cout << "\n\nAdd New Client : \n";
		cout << clsString::Seperator("-", 40) << endl;
		_ReadClientInfo(NewClient);
		cout << clsString::Seperator("-", 40) << endl;

		char Answer = 'n';

		cout << "Are You Sure You Want to Add This Client [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			clsBankClient::enSaveResults SaveResult;
			SaveResult = NewClient.Save();

			switch (SaveResult)
			{
			case clsBankClient::svFalidEmptyOject:
			{
				cout << "\nError Account Was Not Saved, Because It's Empty!";
				break;
			}
			case clsBankClient::svSucceded:
			{
				cout << "\nAccount Addeded Successfully : -)\n";
				_PrintClient(NewClient);
				break;
			}
			case clsBankClient::svFalidAccountNumberExists:
			{
				cout << "\nError Account Was Not Saved, Because Account Number Is Used!";
				break;
			}
			};
		}
		else
		{
			cout << "\nClient Was Not Saved!";
		}
		
	}
};