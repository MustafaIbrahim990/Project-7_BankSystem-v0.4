//class String

#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	//----------------------------------

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	//----------------------------------

	static short Length(string str)
	{
		return str.length();
	}

	short Length()
	{
		return _Value.length();
	}

	//----------------------------------

	static string Seperator(string Sperator, short NumberOfSperator)
	{
		string str = "";

		for (int i = 1; i <= NumberOfSperator; i++)
		{
			str += Sperator;
		}
		return str;
	}

	//----------------------------------

	static void PrintFirstLetter(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				cout << str[i] << endl;
			}

			isFirstLetter = ((str[i] == ' ') ? true : false);
		}
	}

	void PrintFirstLetter()
	{
		PrintFirstLetter(_Value);
	}

	//----------------------------------

	static string UpperFirstLetterOfEachWord(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = toupper(str[i]);
			}

			isFirstLetter = ((str[i] == ' ') ? true : false);
		}
		return str;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	//----------------------------------

	static string LowerFirstLetterOfEachWord(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = tolower(str[i]);
			}

			isFirstLetter = ((str[i] == ' ') ? true : false);
		}
		return str;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	//----------------------------------

	static string UpperAllString(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	//----------------------------------

	static string LowerAllString(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	//----------------------------------

	static char InvertLetterCase(char MyChar)
	{
		return isupper(MyChar) ? tolower(MyChar) : toupper(MyChar);
	}

	static string InvertAllLettersCase(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			str[i] = InvertLetterCase(str[i]);
		}
		return str;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	//----------------------------------

	static short CountCapitalLetter(string str)
	{
		short CountCapitalLetter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
				CountCapitalLetter++;
		}
		return CountCapitalLetter;
	}

	short CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	//----------------------------------

	static short CountSmallLetter(string str)
	{
		short CountSmallLetter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (islower(str[i]))
				CountSmallLetter++;
		}
		return CountSmallLetter;
	}

	short CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	//----------------------------------

	enum enWhatToCount { CapitalLetter = 0, SmallLetter = 1, AllLetter = 2 };

	static short CountLetter(string str, enWhatToCount WhatToCount = enWhatToCount::AllLetter)
	{
		short Counter = 0;

		if (WhatToCount == enWhatToCount::AllLetter)
			return str.length();

		for (short i = 0; i < str.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetter && isupper(str[i]))
				Counter++;
			else if (WhatToCount == enWhatToCount::SmallLetter && islower(str[i]))
				Counter++;
		}
		return Counter;
	}

	short CountLetter(enWhatToCount WhatToCount)
	{
		return CountLetter(_Value, WhatToCount);
	}

	//----------------------------------

	static short CountSpecificLetter(string str, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (MatchCase)
			{
				if (str[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(str[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	//----------------------------------

	static bool IsVowelLetter(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'o') || (Letter == 'u') || (Letter == 'i'));
	}

	//----------------------------------

	static short CountVowelLetter(string str)
	{
		short Counter = 0;

		for (short i = 0; i < str.length(); i++)
		{
			if (IsVowelLetter(str[i]))
				Counter++;
		}
		return Counter;
	}

	short CountVowelLetter()
	{
		return CountVowelLetter(_Value);
	}

	//----------------------------------

	static void PrintAllVowels(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (IsVowelLetter(str[i]))
				printf("%c   ", str[i]);
		}
	}

	void PrintAllVowels()
	{
		PrintAllVowels(_Value);
	}

	//----------------------------------

	static void PrintEachWord(string str)
	{
		string delimiter = " ";
		short Postion = 0;
		string sWord = "";

		while ((Postion = str.find(delimiter)) != std::string::npos)
		{
			sWord = str.substr(0, Postion);

			if (sWord != "")
			{
				cout << sWord << endl;
			}
			str.erase(0, Postion + delimiter.length());
		}

		if (str != "")
		{
			cout << str << endl;
		}
	}

	void PrintEachWord()
	{
		PrintEachWord(_Value);
	}

	//----------------------------------

	static short CountWords(string str)
	{
		short Counter = 0;

		string delimiter = " ";
		short Position = 0;
		string sWord = "";

		while ((Position = str.find(delimiter)) != std::string::npos)
		{
			sWord = str.substr(0, Position);

			if (sWord != "")
			{
				Counter++;
			}
			str.erase(0, Position + delimiter.length());
		}

		if (str != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	//----------------------------------

	static vector <string> Split(string str, string delimiter)
	{
		vector <string> vString;

		//string delimiter = " ";
		short Position = 0;
		string sWord = "";

		while ((Position = str.find(delimiter)) != std::string::npos)
		{
			sWord = str.substr(0, Position);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			str.erase(0, Position + delimiter.length());
		}

		if (str != "")
		{
			vString.push_back(str);
		}

		return vString;
	}

	vector <string> Split(string delimiter)
	{
		return Split(_Value, delimiter);
	}

	//----------------------------------

	static string TrimLeft(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	//----------------------------------

	static string TrimRight(string str)
	{
		for (short i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	//----------------------------------

	static string Trim(string str)
	{
		return (TrimLeft(TrimRight(str)));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	//----------------------------------

	static string JoinString(vector <string> vString, string delimiter)
	{
		string str = "";

		for (string& Word : vString)
		{
			str = str + Word + delimiter;
		}
		return str.substr(0, str.length() - delimiter.length());
	}

	static string JoinString(string arrString[], int arrLength, string delimiter)
	{
		string str = "";

		for (short i = 0; i < arrLength; i++)
		{
			str = str + arrString[i] + delimiter;
		}
		return str.substr(0, str.length() - delimiter.length());
	}

	//----------------------------------

	static string ReverseWords(string str, string delimiter)
	{
		string str2 = "";
		vector <string> vString = Split(str, delimiter);

		vector <string> ::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			iter--;
			str2 += *iter + delimiter;
		}
		return str2.substr(0, str2.length() - delimiter.length());
	}

	void ReverseWords(string delimiter)
	{
		_Value = ReverseWords(_Value, delimiter);
	}

	//----------------------------------

	static string ReplaceWords(string str, string StringToReplace, string sReplaceTo)
	{
		short Position = str.find(StringToReplace);

		while (Position != std::string::npos)
		{
			str = str.replace(Position, StringToReplace.length(), sReplaceTo);
			Position = str.find(StringToReplace);
		}
		return str;
	}

	string ReplaceWords(string str, string StringToReplace, string sReplaceTo, string delimiter, bool MatchCase = true)
	{
		vector <string> vString = Split(str, delimiter);

		for (string& Word : vString)
		{
			if (MatchCase)
			{
				if (Word == StringToReplace)
				{
					Word = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(Word) == LowerAllString(StringToReplace))
				{
					Word = sReplaceTo;
				}
			}
		}
		return JoinString(vString, delimiter);
	}

	//----------------------------------

	static string RemovePunctuations(string str)
	{
		string str2 = "";

		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
			{
				str2 += str[i];
			}
		}
		return str2;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

	//----------------------------------

};