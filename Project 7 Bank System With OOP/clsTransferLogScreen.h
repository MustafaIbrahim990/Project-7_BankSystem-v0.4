//class TransferLogScreen

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(3) << left << "" << "| " << setw(25) << left << TransferLogRecord.DateTime;
		cout << setw(3) << left << "" << "| " << setw(9) << left << TransferLogRecord.SourceAccountNumber;
		cout << setw(3) << left << "" << "| " << setw(9) << left << TransferLogRecord.DestinationAccountNumber;
		cout << setw(3) << left << "" << "| " << setw(9) << left << TransferLogRecord.Amount;
		cout << setw(3) << left << "" << "| " << setw(9) << left << TransferLogRecord.SourceAccountBalanceAfter;
		cout << setw(3) << left << "" << "| " << setw(9) << left << TransferLogRecord.DestinationAccountBalanceAfter;
		cout << setw(3) << left << "" << "| " << setw(10) << left << TransferLogRecord.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{
		/*if (!CheckAccessRights(clsUser::enPermissions::))
		{
			return;
		}*/

		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t     (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(3) << left << "" << clsString::Seperator("_", 112) << endl << endl;
		cout << setw(3) << left << "" << "| " << setw(25) << left << "Date/Time";
		cout << setw(3) << left << "" << "| " << setw(9) << left << "s.Acct";
		cout << setw(3) << left << "" << "| " << setw(9) << left << "d.Acct";
		cout << setw(3) << left << "" << "| " << setw(9) << left << "Amount";
		cout << setw(3) << left << "" << "| " << setw(9) << left << "s.Balance";
		cout << setw(3) << left << "" << "| " << setw(9) << left << "d.Balance";
		cout << setw(3) << left << "" << "| " << setw(10) << left << "User" << endl;
		cout << setw(3) << left << "" << clsString::Seperator("_", 112) << endl << endl;

		if (vTransferLogRecord.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Transfer Available In The System.\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& C : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(C);
				cout << endl;
			}
			cout << setw(3) << left << "" << clsString::Seperator("_", 112) << endl << endl;
		}
	}

};