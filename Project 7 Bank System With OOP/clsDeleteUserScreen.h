//class DeleteUserScreen

#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t     Delete User Screen");

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

		cout << "Are You Sure You Want to Delete This User [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully : -)\n";
				_PrintUser(User);
			}
			else
			{
				cout << "\nError User Was Not Deleted!";
			}
		}
	};
};