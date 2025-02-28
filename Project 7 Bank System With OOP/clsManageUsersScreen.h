//class ManageUsersScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpDateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenueOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpDateUser = 4, eFindUser = 5, eMainMenue = 6 };

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\n" << setw(40) << left << "" << "Press Any Key to Go Back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static short _ReadManageUsersMenueOptions()
	{
		short Choose = 0;

		cout << setw(40) << left << "" << "Choose What Do You Want to Do [1 to 6]? ";
		Choose = clsInputValidate::ReadShortNumberBetween(1, 6, "\t\t\t\t\tChoose What Do You Want to Do [1 to 6]? ");
		return Choose;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\n\nList Users Screen Will Be here....";
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\n\nAdd New User Screen Will Be here....";
		clsAddNewUserScreen::ShowAddNewUserScreen();
		
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\n\nDelete User Screen Will Be here....";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpDateUserScreen()
	{
		//cout << "\n\nUpDate User Info Screen Will Be here....";
		clsUpDateUserScreen::ShowUpDateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\n\nFind User Screen Will Be here....";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOptions(enManageUsersMenueOptions ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case clsManageUsersScreen::eListUsers:
		{
			system("Cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case clsManageUsersScreen::eAddNewUser:
		{
			system("Cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case clsManageUsersScreen::eDeleteUser:
		{
			system("Cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case clsManageUsersScreen::eUpDateUser:
		{
			system("Cls");
			_ShowUpDateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case clsManageUsersScreen::eFindUser:
		{
			system("Cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case clsManageUsersScreen::eMainMenue:
		{
	
		}
		};
	}

public:

	static void ShowManageUsersMenue()
	{
		system("Cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("\t   Manage Users Menue Screen");

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;
		cout << setw(40) << left << "" << "\t      Manage Users Menue" << endl;
		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		cout << setw(40) << left << "" << "\t[1] List Users." << endl;
		cout << setw(40) << left << "" << "\t[2] Add New User." << endl;
		cout << setw(40) << left << "" << "\t[3] Delete User." << endl;
		cout << setw(40) << left << "" << "\t[4] UpDate User." << endl;
		cout << setw(40) << left << "" << "\t[5] Find User." << endl;
		cout << setw(40) << left << "" << "\t[6] Main Menue." << endl;

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		_PerformManageUsersMenueOptions((enManageUsersMenueOptions)_ReadManageUsersMenueOptions());
	}

};