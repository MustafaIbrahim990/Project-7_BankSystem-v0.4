//class Person

#pragma once
#include <iostream>
#include "clsString.h"
using namespace std;

class clsPerson
{
private:
	//int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		//_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//ID.

	/*int ID()
	{
		return _ID;
	}*/

	//First Name.

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	//Last Name.

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName))string LastName;

	//Full Name.

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	//Email.

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	//Phone.

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	//Print.

	void Print()
	{
		cout << "\nInfo : \n\n";

		cout << clsString::Seperator("-", 40) << endl;
		//cout << "ID         : " << _ID << endl;
		cout << "First Name : " << _FirstName << endl;
		cout << "Last Name  : " << _LastName << endl;
		cout << "Full Name  : " << FullName() << endl;
		cout << "Email      : " << _Email << endl;
		cout << "Phone      : " << _Phone << endl;
		cout << clsString::Seperator("-", 40) << endl;
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\n\nThe Following Message Sent Successfully to Email : " << _Email << "." << endl;
		cout << "Subject : " << Subject << endl;
		cout << "Body    : " << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\n\nThe Following SMS Sent Successfully to Phone : " << _Phone << "." << endl;
		cout << "Message : " << TextMessage << endl;
	}
};