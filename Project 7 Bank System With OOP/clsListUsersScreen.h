//class ListUsersScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser UserData)
	{
		cout << setw(2) << left << "" << "| " << setw(12) << left << UserData.UserName;
		cout << setw(2) << left << "" << "| " << setw(25) << left << UserData.FullName();
		cout << setw(2) << left << "" << "| " << setw(12) << left << UserData.Phone;
		cout << setw(2) << left << "" << "| " << setw(20) << left << UserData.Email;
		cout << setw(2) << left << "" << "| " << setw(10) << left << UserData.PassWord;
		cout << setw(2) << left << "" << "| " << setw(12) << left << UserData.Permissions;
	}

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t\tList Users Screen";
		string SubTitle = "\t        (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(2) << left << "" << clsString::Seperator("_", 113) << endl << endl;
		cout << setw(2) << left << "" << "| " << setw(12) << left << "User Name";
		cout << setw(2) << left << "" << "| " << setw(25) << left << "Full Name";
		cout << setw(2) << left << "" << "| " << setw(12) << left << "Phone";
		cout << setw(2) << left << "" << "| " << setw(20) << left << "Email";
		cout << setw(2) << left << "" << "| " << setw(10) << left << "PassWord";
		cout << setw(2) << left << "" << "| " << setw(12) << left << "Permissions" << endl;
		cout << setw(2) << left << "" << clsString::Seperator("_", 113) << endl << endl;

		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t\t\t\tNo Users Availble In The System.\n";
		}
		else
		{
			for (clsUser& U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
			cout << setw(2) << left << "" << clsString::Seperator("_", 113) << endl << endl;
		}
	}
};