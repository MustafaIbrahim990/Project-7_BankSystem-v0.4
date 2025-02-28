//class TotalBalancesScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(8) << "" << "| " << setw(20) << left << Client.AccountNumber();
		cout << setw(8) << "" << "| " << setw(40) << left << Client.FullName();
		cout << setw(8) << "" << "| " << setw(14) << left << Client.AccountBalance;
	}

public:

	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t\tBalances List Screen";
		string SubTitle = "\t        (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << "" << clsString::Seperator("_", 100) << endl << endl;
		cout << setw(8) << "" << "| " << setw(20) << left << "Account Number";
		cout << setw(8) << "" << "| " << setw(40) << left << "Client Name";
		cout << setw(8) << "" << "| " << setw(14) << left << "Account Balance" << endl;
		cout << setw(8) << "" << clsString::Seperator("_", 100) << endl << endl;

		double TotalBalances = clsBankClient::GetTotalBalances(vClients);

		if (vClients.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Clients Availble In The System.\n";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}
			cout << setw(8) << "" << clsString::Seperator("_", 100) << endl << endl;
			cout << "\n\t\t\t\t\t\t Total Balances = " << TotalBalances << " $ " << endl;
			cout << "\n\t\t\t\t\t[ " << clsUtil::NumberToText(TotalBalances) << " ]" << endl;
		}
	}
};