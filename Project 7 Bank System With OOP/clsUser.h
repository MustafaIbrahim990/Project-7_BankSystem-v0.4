//class User

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

const string UsersFileName = "UsersDate.txt";
const string LoginRegisterFileName = "LoginRegister.txt";

class clsUser : public clsPerson
{
private:

	enum enMode { eEmptyMode = 0, eUpDateMode = 1, eAddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _PassWord;
	int _Permissions;
	bool _MarkedForDeleted = false;

	//Declarations:

	struct stLoginRegisterRecord;

	//-------------------------

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;

		vector <string> LoginRegisterRecordDateLine = clsString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = LoginRegisterRecordDateLine[0];
		LoginRegisterRecord.UserName = LoginRegisterRecordDateLine[1];
		LoginRegisterRecord.PassWord = clsUtil::DecryptText(LoginRegisterRecordDateLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterRecordDateLine[3]);

		return LoginRegisterRecord;
	}

	string _PrepareLoginRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";

		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(PassWord) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	static clsUser _ConvertLineToUserObject(string strUserData, string Seperator = "#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::Split(strUserData, Seperator);

		return clsUser(enMode::eUpDateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser UserData = _ConvertLineToUserObject(Line);
				vUsers.push_back(UserData);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static string _ConvertUserObjectToLine(clsUser UserData, string Sperator = "#//#")
	{
		string UserRecord = "";

		UserRecord += UserData.FirstName + Sperator;
		UserRecord += UserData.LastName + Sperator;
		UserRecord += UserData.Email + Sperator;
		UserRecord += UserData.Phone + Sperator;
		UserRecord += UserData.UserName + Sperator;
		UserRecord += clsUtil::EncryptText(UserData.PassWord) + Sperator;
		UserRecord += to_string(UserData.Permissions);

		return UserRecord;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUser)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out);
		string strUserData = "";

		if (MyFile.is_open())
		{
			for (clsUser& U : vUser)
			{
				if (U._MarkedForDeleted == false)
				{
					strUserData = _ConvertUserObjectToLine(U);
					MyFile << strUserData << endl;
				}
			}
			MyFile.close();
		}
	}

	void _UpDate()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddDateLineToFile(string strDateLine)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << strDateLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDateLineToFile(_ConvertUserObjectToLine(*this));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

public:

	enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpDateClientInfo = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64, pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime = "";
		string UserName = "";
		string PassWord = "";
		int Permissions = 0;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permissions;
	}

	//-------------------------

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	//-------------------------

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	//-------------------------

	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}

	string GetPassWord()
	{
		return _PassWord;
	}

	__declspec(property(get = GetPassWord, put = SetPassWord)) string PassWord;

	//-------------------------

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	//-------------------------

	bool MarkedForDeleted()
	{
		return _MarkedForDeleted;
	}

	//-------------------------

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string PassWord)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.PassWord == PassWord)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	//-------------------------

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	//-------------------------

	enum enSaveResults { svFalidEmptyOject = 0, svSucceded = 1, svFalidUserNameExists = 2 };

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
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFalidUserNameExists;
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

	//-------------------------

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDeleted = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	//-------------------------

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	//-------------------------

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	//-------------------------

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permissions & this->Permissions) == Permissions)
			return true;
		else
			return false;
	}

	//-------------------------

	void RegisterLogin()
	{
		string stDateLine = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDateLine << endl;
			MyFile.close();
		}
	}

	//-------------------------

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stLoginRegisterRecord LoginRegisterRecord;
			
			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}

	//-------------------------



};