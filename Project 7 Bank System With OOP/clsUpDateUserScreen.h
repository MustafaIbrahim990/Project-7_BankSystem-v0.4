// class UpDateUserScreen

#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsPerson.h"
using namespace std;

class clsUpDateUserScreen : protected clsScreen
{
private:

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char UserAnswer = 'n';

		cout << "\nEnter Permissions: ";
		cout << "\nDo You Want to Give Full Access [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			return -1;
		}

		cout << "\nDo You Want to Give Access to : \n\n";

		cout << "Show Client List [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "Add New Client   [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Delete Client    [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "UpDate Client    [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpDateClientInfo;
		}

		cout << "Find Client      [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "Transaction      [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransaction;
		}

		cout << "Manage User      [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "Login Register   [Y/N]? ";
		cin >> UserAnswer;

		if (toupper(UserAnswer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name  : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email      : ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone      : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter PassWord   : ";
		User.PassWord = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card : \n";

		cout << "--------------------------------------------------";
		cout << "\nUser Name           : " << User.UserName;
		cout << "\nFirst Name          : " << User.FirstName;
		cout << "\nLast Name           : " << User.LastName;
		cout << "\nFull Name           : " << User.FullName();
		cout << "\nEmail               : " << User.Email;
		cout << "\nPhone               : " << User.Phone;
		cout << "\nPassWord            : " << User.PassWord;
		cout << "\nPermissions         : " << User.Permissions;
		cout << "\n--------------------------------------------------\n";
	}

public:

	static void ShowUpDateUserScreen()
	{
		_DrawScreenHeader("\t   UpDate User Screen");

		string UserName = "";

		cout << "Please Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name [" << UserName << "] is Not Found, Enter another One? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Answer = 'n';

		cout << "Are You Sure You Want to UpDate This User [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpDate User Info : \n";
			cout << clsString::Seperator("-", 40) << endl;
			_ReadUserInfo(User);
			cout << clsString::Seperator("-", 40) << endl;

			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svFalidEmptyOject:
			{
				cout << "\nError User Was Not Saved, Because It's Empty!";
				break;
			}
			case clsUser::svSucceded:
			{
				cout << "\nUser Addeded Successfully : -)\n";
				_PrintUser(User);
				break;
			}
			};
		}
	}

};