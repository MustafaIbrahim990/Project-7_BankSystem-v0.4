//class LoginRegisterScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsDate.h"
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen 
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(4) << left << "" << "| " << setw(30) << left << LoginRegisterRecord.DateTime;
		cout << setw(4) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << setw(4) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.PassWord;
		cout << setw(4) << left << "" << "| " << setw(12) << left << LoginRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t        (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(4) << left << "" << clsString::Seperator("_", 105) << endl << endl;
		cout << setw(4) << left << "" << "| " << setw(30) << left << "Date/Time";
		cout << setw(4) << left << "" << "| " << setw(20) << left << "User Name";
		cout << setw(4) << left << "" << "| " << setw(20) << left << "PassWord";
		cout << setw(4) << left << "" << "| " << setw(12) << left << "Permissions" << endl;
		cout << setw(4) << left << "" << clsString::Seperator("_", 105) << endl << endl;

		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Login Available In The System.\n";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& C : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(C);
				cout << endl;
			}
			cout << setw(4) << "" << clsString::Seperator("_", 105) << endl << endl;
		}
	}

};