//class CurrencyScreen

#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpDateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyScreen : protected clsScreen
{
private:

	enum enCurrencyMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpDateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };

	static void _GoBackToCurrencyMenue()
	{
		cout << "\n\n" << setw(40) << left << "" << "Press Any Key to Go Back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyMenue();
	}

	static short _ReadCurrencyMenueOptions()
	{
		short Choose = 0;

		cout << setw(40) << left << "" << "Choose What Do You Want to Do [1 to 5]? ";
		Choose = clsInputValidate::ReadShortNumberBetween(1, 5, "\t\t\t\t\tChoose What Do You Want to Do [1 to 5]? ");
		return Choose;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\n\nList Currencies Screen Will Be here....";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\n\nFind Currency Screen Will Be here....";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpDateCurrencyRateScreen()
	{
		//cout << "\n\nUpDate Rate Screen Will Be here....";
		clsUpDateCurrencyRateScreen::ShowUpDateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n\nCurrency Calculator Screen Will Be here....";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyMenueOptions(enCurrencyMenueOptions CurrencyMenueOptions)
	{
		switch (CurrencyMenueOptions)
		{
		case clsCurrencyScreen::eListCurrencies:
		{
			system("Cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case clsCurrencyScreen::eFindCurrency:
		{
			system("Cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case clsCurrencyScreen::eUpDateRate:
		{
			system("Cls");
			_ShowUpDateCurrencyRateScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case clsCurrencyScreen::eCurrencyCalculator:
		{
			system("Cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;
		}
		case clsCurrencyScreen::eMainMenue:
		{
			
		}
		};
	}

public:

	static void ShowCurrencyMenue()
	{
		system("Cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;
		cout << setw(40) << left << "" << "\t   Currency Exchange Menue" << endl;
		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		cout << setw(40) << left << "" << "\t[1] List Currencies." << endl;
		cout << setw(40) << left << "" << "\t[2] Find Currency." << endl;
		cout << setw(40) << left << "" << "\t[3] UpDate Rate." << endl;
		cout << setw(40) << left << "" << "\t[4] Currency Calculator." << endl;
		cout << setw(40) << left << "" << "\t[5] Main Menue." << endl;

		cout << setw(40) << left << "" << clsString::Seperator("=", 45) << endl;

		_PerformCurrencyMenueOptions((enCurrencyMenueOptions)_ReadCurrencyMenueOptions());
	}
};