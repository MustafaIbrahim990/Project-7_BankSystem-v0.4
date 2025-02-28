//class Currency

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h";
using namespace std;

const string CurrencyFileName = "Currencies.txt";

class clsCurrency
{
private:

	enum enMode { eEmptyMode = 0, eUpDateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencys;
		vCurrencys = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::eUpDateMode, vCurrencys[0], vCurrencys[1], vCurrencys[2], stof(vCurrencys[3]));
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrency;
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Sperator = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Sperator;
		CurrencyRecord += Currency.CurrencyCode() + Sperator;
		CurrencyRecord += Currency.CurrencyName() + Sperator;
		CurrencyRecord += to_string(Currency.Rate());

		return CurrencyRecord;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::out);
		string strCurrencyData = "";

		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencys)
			{
				strCurrencyData = _ConvertCurrencyObjectToLine(C);
				MyFile << strCurrencyData << endl;
			}
			MyFile.close();
		}
	}

	void _UpDate()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == _CurrencyCode)
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	//-------------------------

	static vector <clsCurrency> GetAllUSDRates()
	{
		return _LoadCurrencyDataFromFile();
	}

	//-------------------------

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	//-------------------------

	string Country()
	{
		return _Country;
	}

	//-------------------------

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	//-------------------------

	string CurrencyName()
	{
		return _CurrencyName;
	}

	//-------------------------

	void UpDateRate(float NewRate)
	{
		_Rate = NewRate;
		_UpDate();
	}

	float Rate()
	{
		return _Rate;
	}

	//-------------------------

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	//-------------------------

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	//-------------------------

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	//-------------------------

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());
	}

};