//class AddNewUserScreen

#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t     Add New User Screen");

		string UserName = "";

		cout << "Please Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "User Name [" << UserName << "] is Already Used, Enter another One? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		cout << "\n\nAdd New User : \n";
		cout << clsString::Seperator("-", 30) << endl;
		_ReadUserInfo(NewUser);
		cout << clsString::Seperator("-", 30) << endl;

		char Answer = 'n';

		cout << "Are You Sure You Want to Add This User [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			clsUser::enSaveResults SaveResult;
			SaveResult = NewUser.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceded:
			{
				cout << "\nUser Addeded Successfully : -)\n";
				_PrintUser(NewUser);
				break;
			}
			case clsUser::enSaveResults::svFalidEmptyOject:
			{
				cout << "\nError User Was Not Saved, Because It's Empty!";
				break;
			}
			case clsUser::enSaveResults::svFalidUserNameExists:
			{
				cout << "\nError User Was Not Saved, Because User Name is Used!";
				break;
			}
			};
		}
		else
		{
			cout << "\nUser Was Not Saved!";
		}
		
	}
};