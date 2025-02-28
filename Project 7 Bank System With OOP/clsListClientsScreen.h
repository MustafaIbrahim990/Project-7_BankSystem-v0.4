//class ListClientsScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsPerson.h"
using namespace std;

class clsListClientsScreen : protected clsScreen
{
private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(2) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << setw(2) << left << "" << "| " << setw(20) << left << Client.FullName();
		cout << setw(2) << left << "" << "| " << setw(12) << left << Client.Phone;
		cout << setw(2) << left << "" << "| " << setw(20) << left << Client.Email;
		cout << setw(2) << left << "" << "| " << setw(10) << left << Client.PINCode;
		cout << setw(2) << left << "" << "| " << setw(12) << left << Client.AccountBalance;
	}

public:

	static void ShowListClientsScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t\tClient List Screen";
		string SubTitle = "\t        (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(2) << left << "" << clsString::Seperator("_", 115) << endl << endl;
		cout << setw(2) << left << "" << "| " << setw(15) << left << "Account Number";
		cout << setw(2) << left << "" << "| " << setw(20) << left << "Client Name";
		cout << setw(2) << left << "" << "| " << setw(12) << left << "Phone";
		cout << setw(2) << left << "" << "| " << setw(20) << left << "Email";
		cout << setw(2) << left << "" << "| " << setw(10) << left << "PIN Code";
		cout << setw(2) << left << "" << "| " << setw(12) << left << "Account Balance" << endl;
		cout << setw(2) << left << "" << clsString::Seperator("_", 115) << endl << endl;

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Clients Availble In The System.\n";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}
			cout << setw(2) << left << "" << clsString::Seperator("_", 115) << endl << endl;
		}
	}

};