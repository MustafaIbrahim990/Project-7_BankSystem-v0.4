// class FindUserScreen

#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindBy { Code = 1, Country = 2 };

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card : \n";

		cout << "--------------------------------------------------";
		cout << "\nCountry              : " << Currency.Country();
		cout << "\nCurrency Code        : " << Currency.CurrencyCode();
		cout << "\nCurrency Name        : " << Currency.CurrencyName();
		cout << "\nRate (1$) =          : " << Currency.Rate();
		cout << "\n--------------------------------------------------\n";
	}

	static string _ReadCurrencyCountry()
	{
		string Country = "";

		cout << "\nPlease Enter Currency Country : ";
		Country = clsInputValidate::ReadString();

		return Country;
	}

	static string _ReadCurrencyCode()
	{
		string Code = "";

		cout << "\nPlease Enter Currency Code : ";
		Code = clsInputValidate::ReadString();

		return Code;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency Found : -)\n";
				_PrintCurrency(Currency);
			}
		}
		else
		{
			cout << "\nCurrency Was Not Found!\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t   Find Currency Screen");

		short Answer = 0;

		cout << "Find By: [1] Code Or [2] Country? ";
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2, "Find By: [1] Code Or [2] Country? ");

		if (Answer == enFindBy::Code)
		{
			string CurrencyCode = "";
			CurrencyCode = _ReadCurrencyCode();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string CurrencyName = "";
			CurrencyName = _ReadCurrencyCountry();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyName);
			_ShowResults(Currency);
		}
	}
};