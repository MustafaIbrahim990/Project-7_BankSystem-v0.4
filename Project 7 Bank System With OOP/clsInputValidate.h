//class InputValidate

#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsInputValidate
{
public:

	//------------------------

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	//------------------------

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date >= From && Date <= To
		//Date >= To && Date <= From

		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
				))
		{
			return true;
		}

		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
				))
		{
			return true;
		}

		return false;
	}

	//------------------------

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Please Enter Again?\n")
	{
		int Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Please Enter Again?\n")
	{
		short Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Please Enter Again?\n")
	{
		float Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Please Enter Again?\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	//------------------------

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is Not Within Range, Please Enter Again?\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is Not Within Range, Please Enter Again?\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is Not Within Range, Please Enter Again?\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}
		return Number;
	}

	static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage = "Number is Not Within Range, Please Enter Again?\n")
	{
		double Number = ReadDoubleNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDoubleNumber();
		}
		return Number;
	}

	//------------------------

	static string ReadString()
	{
		string str = "";

		getline(cin >> ws, str);
		return str;
	}

	//------------------------

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	//------------------------

};