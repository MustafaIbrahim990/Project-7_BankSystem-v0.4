//class Utlity

#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsUtil
{
public:

	//-------------------------

	static bool IsAgeInRange(short Age, short From, short To)
	{
		return (Age >= From && Age <= To);
	}

	//-------------------------

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		};
		return Text;
	}

	//-------------------------

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		};
		return Text;
	}

	//-------------------------

	//#include <cstdlib>

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = 0;

		RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}

	//-------------------------

	enum enCharType { SmallLetters = 1, CapitalLetters = 2, SpecialCharacters = 3, Digits = 4, MixCharacter = 5 };

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == enCharType::MixCharacter)
		{
			CharType = (enCharType)RandomNumber(1, 4);
		}

		switch (CharType)
		{
		case enCharType::SmallLetters:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetters:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacters:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digits:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		default:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		};
	}

	//-------------------------

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}

	//-------------------------

	static string GenerateKey(enCharType CharType = enCharType::CapitalLetters)
	{
		string Key = "";
		Key = Key + GenerateWord(CharType, 4) + "_" + GenerateWord(CharType, 4) + "_" + GenerateWord(CharType, 4) + "_" + GenerateWord(CharType, 4);
		return Key;
	}

	//-------------------------

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (short i = 1; i <= NumberOfKeys; i++)
		{
			cout << GenerateKey(CharType) << endl;
		}
	}

	//-------------------------

	static void FillArrayWithRandomNumbers(int Arr[100], int ArrLength, int From, int To)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}
	}

	//-------------------------

	static void FillArrayWithRandomWords(string Arr[100], int ArrLength, enCharType CharType, short WordLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateWord(CharType, WordLength);
		}
	}

	//-------------------------

	static void FillArrayWithRandomKeys(string Arr[100], int ArrLength, enCharType CharType)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateKey(CharType);
		}
	}

	//-------------------------

	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(float& A, float& B)
	{
		float Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	//-------------------------

	static void ShuffleArray(int Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	//-------------------------

	static void ShuffleArray(string Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	//-------------------------

	static string Tabs(short NumberOfTabs)
	{
		string tabs = "";

		for (short i = 1; i <= NumberOfTabs; i++)
		{
			tabs += "\t";
		}
		return tabs;
	}

	//-------------------------

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		else if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",

				"Twelve","Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eightteen","Nientenn" };

			return arr[Number] + " ";

		}
		else if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		else if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		else if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}
		else if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		else if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}
		else if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}
		else if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Milions " + NumberToText(Number % 1000000);
		}
		else if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}

	//-------------------------

	static string EncryptText(string Text, int EncryptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	//----------------------------------

	static string DecryptText(string TextAfterEncryption, int EncryptionKey = 2)
	{
		for (int i = 0; i <= TextAfterEncryption.length(); i++)
		{
			TextAfterEncryption[i] = char((int)TextAfterEncryption[i] - EncryptionKey);
		};
		return TextAfterEncryption;
	}

	//-------------------------
};