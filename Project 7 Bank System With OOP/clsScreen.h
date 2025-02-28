//class Screen

#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t" << clsString::Seperator("_", 45);
		cout << "\n\n\t\t\t\t\t  " << Title;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t" << clsString::Seperator("_", 45) << "\n\n";

		_AddDateHeader();
		_AddUserNameHeader();
	}

	//------------------------------------

	static void _AddDateHeader()
	{
		cout << "\n\t\t\t\t\t  " << "Date : " << clsDate::DateToString(clsDate());
	}

	//------------------------------------

	static void _AddUserNameHeader()
	{
		cout << "\n\t\t\t\t\t  " << "User : " << CurrentUser.UserName << "\n\n";
	}

	//------------------------------------

	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (CurrentUser.CheckAccessPermissions(Permissions))
		{
			return true;
		}
		else
		{
			cout << "\t\t\t\t\t" << clsString::Seperator("_", 45);
			cout << "\n\n\t\t\t\t\t  " << "   Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t" << clsString::Seperator("_", 45) << "\n\n";
			return false;
		}
	}

	//------------------------------------


};