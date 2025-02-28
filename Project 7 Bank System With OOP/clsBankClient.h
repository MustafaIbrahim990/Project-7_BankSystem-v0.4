//class BankClient

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUser.h"
using namespace std;

const string ClientsFileName = "ClientsData.txt";
const string TransferLogFileName = "TransferLog.txt";

class clsBankClient : public clsPerson
{
private:

	enum enMode { eEmptyMode = 0, eUpDateMode = 1, eAddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PINCode;
	double _AccountBalance;
	bool _MarkedForDeleted = false;

	//Declarations :

	struct stTransferLogRecord;

	//-------------------------

	static stTransferLogRecord _ConvertTransferLoginLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLog;

		vector <string> TransferLogRecordDateLine = clsString::Split(Line, Seperator);

		TransferLog.DateTime = TransferLogRecordDateLine[0];
		TransferLog.SourceAccountNumber = TransferLogRecordDateLine[1];
		TransferLog.DestinationAccountNumber = TransferLogRecordDateLine[2];
		TransferLog.Amount = stod(TransferLogRecordDateLine[3]);
		TransferLog.SourceAccountBalanceAfter = stod(TransferLogRecordDateLine[4]);
		TransferLog.DestinationAccountBalanceAfter = stod(TransferLogRecordDateLine[5]);
		TransferLog.UserName = TransferLogRecordDateLine[6];

		return TransferLog;
	}

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::eUpDateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient ClientData, string Sperator = "#//#")
	{
		string ClientRecord = "";

		ClientRecord += ClientData.FirstName + Sperator;
		ClientRecord += ClientData.LastName + Sperator;
		ClientRecord += ClientData.Email + Sperator;
		ClientRecord += ClientData.Phone + Sperator;
		ClientRecord += ClientData.AccountNumber() + Sperator;
		ClientRecord += ClientData.PINCode + Sperator;
		ClientRecord += to_string(ClientData.AccountBalance);

		return ClientRecord;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClientData;
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient ClientData = _ConvertLineToClientObject(Line);
				vClientData.push_back(ClientData);
			}
			MyFile.close();
		}
		return vClientData;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClient)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out);
		string strClientData = "";

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClient)
			{
				if (C._MarkedForDeleted == false)
				{
					strClientData = _ConvertClientObjectToLine(C);
					MyFile << strClientData << endl;
				}
			}
			MyFile.close();
		}
	}

	void _UpDate()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClient);
	}

	void _AddDateLineToFile(string strDateLine)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << strDateLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDateLineToFile(_ConvertClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLoginRecord(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{
		string TransferLoginRecord = "";

		TransferLoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLoginRecord += AccountNumber() + Seperator;
		TransferLoginRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLoginRecord += to_string(Amount) + Seperator;
		TransferLoginRecord += to_string(AccountBalance) + Seperator;
		TransferLoginRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLoginRecord += UserName;

		return TransferLoginRecord;
	}

	void _RegisterTransferLog(double Amount, clsBankClient SourceClient, string UserName)
	{
		string strDateLine = _PrepareTransferLoginRecord(Amount, SourceClient, UserName);

		fstream MyFile;
		MyFile.open(TransferLogFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << strDateLine << endl;
			MyFile.close();
		}
	}

public:

	struct stTransferLogRecord
	{
		string DateTime = "";
		string SourceAccountNumber = "";
		string DestinationAccountNumber = "";
		double Amount = 0;
		double SourceAccountBalanceAfter = 0;
		double DestinationAccountBalanceAfter = 0;
		string UserName = "";
	};

	//--------------------------------

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINCode, double AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINCode;
		_AccountBalance = AccountBalance;
	}

	//--------------------------------

	string AccountNumber()
	{
		return _AccountNumber;
	}

	//--------------------------------

	bool MarkedForDeleted()
	{
		return _MarkedForDeleted;
	}

	//--------------------------------

	void SetPINCode(string PINCode)
	{
		_PINCode = PINCode;
	}

	string GetPINCode()
	{
		return _PINCode;
	}

	__declspec(property(get = GetPINCode, put = SetPINCode)) string PINCode;

	//--------------------------------

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	//--------------------------------

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	//--------------------------------

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PINCode)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PINCode == PINCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	//--------------------------------

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	//--------------------------------

	enum enSaveResults { svFalidEmptyOject = 0, svSucceded = 1, svFalidAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFalidEmptyOject;
				break;
			}
		}
		case enMode::eUpDateMode:
		{
			_UpDate();
			return enSaveResults::svSucceded;
			break;
		}
		case enMode::eAddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFalidAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::eUpDateMode;
				return enSaveResults::svSucceded;
			}
			break;
		}
		};
	}

	//--------------------------------

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::eAddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	//--------------------------------

	bool Delete()
	{
		vector <clsBankClient> vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkedForDeleted = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClient);
		*this = _GetEmptyClientObject();

		return true;
	}

	//--------------------------------

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	//--------------------------------

	static double GetTotalBalances(vector <clsBankClient> vClients)
	{
		//vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

	//--------------------------------

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	//--------------------------------

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	//--------------------------------

	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}

	//--------------------------------

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open(TransferLogFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLoginLineToRecord(Line);
				vTransferLogRecord.push_back(TransferLogRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}

};