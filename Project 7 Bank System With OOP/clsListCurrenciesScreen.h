//class ListCurrenciesScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsString.h"
using namespace std;

class clsListCurrenciesScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(4) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << setw(4) << left << "" << "| " << setw(6) << left << Currency.CurrencyCode();
		cout << setw(4) << left << "" << "| " << setw(40) << left << Currency.CurrencyName();
		cout << setw(4) << left << "" << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowListCurrenciesScreen()
	{
		/*if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}*/

		vector <clsCurrency> vCurrenies = clsCurrency::GetCurrenciesList();

		string Title = "\t    Currencies List Screen";
		string SubTitle = "\t      (" + to_string(vCurrenies.size()) + ") Currency(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(4) << left << "" << clsString::Seperator("_", 110) << endl << endl;
		cout << setw(4) << left << "" << "| " << setw(30) << left << "Country";
		cout << setw(4) << left << "" << "| " << setw(6) << left << "Code";
		cout << setw(4) << left << "" << "| " << setw(40) << left << "Name";
		cout << setw(4) << left << "" << "| " << setw(10) << left << "Rate/(1$)" << endl;
		cout << setw(4) << left << "" << clsString::Seperator("_", 110) << endl << endl;

		if (vCurrenies.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Currencies Availble In The System!\n";
		}
		else
		{
			for (clsCurrency& C : vCurrenies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
			cout << setw(4) << left << "" << clsString::Seperator("_", 110) << endl << endl;
		}
	}
};