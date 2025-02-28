//class LoginScreen

#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFalid = false;
		short FalidLoginCount = 0;

		string UserName = "", PassWord = "";

		do
		{
			if (LoginFalid)
			{
				FalidLoginCount++;

				system("Cls");
				_DrawScreenHeader("\t\tLogin Screen");

				cout << "Invalid UserName/PassWord! \n";
				cout << "You have " << (3 - FalidLoginCount) << " Trial(s) to Login.\n\n";
			}

			if (FalidLoginCount == 3)
			{
				//cout << "\nYour Are Locked After 3 Falid Trials.\n";
				cout << "\nSystem Locked...\n";
				return false;
			}

			cout << "Please Enter UserName? ";
			cin >> UserName;

			cout << "Please Enter PassWord? ";
			cin >> PassWord;

			CurrentUser = clsUser::Find(UserName, PassWord);

			LoginFalid = CurrentUser.IsEmpty();

		} while (LoginFalid);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("Cls");
		_DrawScreenHeader("\t\tLogin Screen");
		
		return _Login();
	}
};