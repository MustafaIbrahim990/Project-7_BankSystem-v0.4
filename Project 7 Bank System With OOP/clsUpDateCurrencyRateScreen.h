// class UpDateCurrencyRateScreen

#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
using namespace std;

class clsUpDateCurrencyRateScreen : protected clsScreen
{
private:

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

	static float _ReadNewRate()
	{
		float NewRate = 0;

		cout << "Enter New Rate? ";
		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

	static string _ReadCurrencyCode()
	{
		string Code = "";

		cout << "\nPlease Enter Currency Code : ";
		Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Currency [" << Code << "] is Not Found, Enter another One : ";
			Code = clsInputValidate::ReadString();
		}
		return Code;
	}

public:

	static void ShowUpDateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t   UpDate Currecny Screen");

		string CurrencyCode = "";

		CurrencyCode = _ReadCurrencyCode();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		char Answer = 'n';

		cout << "Are You Sure You Want to UpDate The Rate Of This Currency [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpDate Currency Rate : \n";
			cout << clsString::Seperator("-", 30) << endl;
			float NewRate = _ReadNewRate();
			cout << clsString::Seperator("-", 30) << endl;

			Currency.UpDateRate(NewRate);
			
			cout << "\nCurrency Rate UpDate Successfully : -)\n";
			_PrintCurrency(Currency);
		}
	}
};