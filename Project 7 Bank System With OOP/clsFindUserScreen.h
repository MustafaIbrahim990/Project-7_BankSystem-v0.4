// class FindUserScreen

#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsPerson.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t   Find User Screen");

		string UserName = "";

		cout << "Please Enter User Name? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name [" << UserName << "] is Not Found, Enter another One? ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found : -)\n";
		}
		else
		{
			cout << "\nUser is Not Found!\n";
		}
		_PrintUser(User);
	}
};