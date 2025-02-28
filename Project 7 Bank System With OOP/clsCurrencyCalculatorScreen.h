//class CurrencyCalculatorScreen.

#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsString.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		//cout << "\nCurrency Card : \n";

		cout << "--------------------------------------------------";
		cout << "\nCountry              : " << Currency.Country();
		cout << "\nCurrency Code        : " << Currency.CurrencyCode();
		cout << "\nCurrency Name        : " << Currency.CurrencyName();
		cout << "\nRate (1$) =          : " << Currency.Rate();
		cout << "\n--------------------------------------------------\n";
	}

	static string _ReadCurrencyCode()
	{
		string Code = "";

		Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Currency [" << Code << "] is Not Found, Enter another One : ";
			Code = clsInputValidate::ReadString();
		}
		return Code;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = _ReadCurrencyCode();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nPlease Enter Amount to Exchange? ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		cout << "\nConvert From : \n";
		_PrintCurrency(Currency1);

		cout << "\nTo : \n";
		_PrintCurrency(Currency2);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToOtherCurrency(Amount, Currency2) << " " << Currency2.CurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Contiune = 'Y';

		while (toupper(Contiune) == 'Y')
		{
			system("Cls");
			_DrawScreenHeader("\t  Currecny Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code : ");
			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code : ");
									
			float Amount = _ReadAmount();

			PrintCalculationResults(Amount, Currency1, Currency2);

			cout << "\n\nDo You Want to Perform another Calculation [Y/N]? ";
			cin >> Contiune;
		}
	}
};