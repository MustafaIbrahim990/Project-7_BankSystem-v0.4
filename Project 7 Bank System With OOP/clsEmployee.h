//class Employee

#pragma once
#include <iostream>
#include "clsPerson.h"
using namespace std;

class clsEmployee : public clsPerson
{
private:
	string _Title;
	string _Department;
	double _Salary;

public:

	clsEmployee(string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	//-----------------------

	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string GetTitle()
	{
		return _Title;
	}

	__declspec(property(get = GetTitle, put = SetTitle))string Title;

	//-----------------------

	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	string GetDepartment()
	{
		return _Department;
	}

	__declspec(property(get = GetDepartment, put = SetDepartment))string Department;

	//-----------------------

	void SetSalary(double Salary)
	{
		_Salary = Salary;
	}

	double GetSalary()
	{
		return _Salary;
	}

	__declspec(property(get = GetSalary, put = SetSalary))double Salary;

	//-----------------------

	void Print()
	{
		cout << "\nInfo : \n\n";

		cout << clsString::Seperator("-", 50) << endl;
		//cout << "ID              : " << ID() << endl;
		cout << "First Name      : " << GetFirstName() << endl;
		cout << "Last Name       : " << GetLastName() << endl;
		cout << "Full Name       : " << FullName() << endl;
		cout << "Email           : " << GetEmail() << endl;
		cout << "Phone           : " << GetPhone() << endl;
		cout << "Title           : " << _Title << endl;
		cout << "Department      : " << _Department << endl;
		cout << "Salary          : " << _Salary << " $ " << endl;
		cout << clsString::Seperator("-", 50) << endl;
	}
};