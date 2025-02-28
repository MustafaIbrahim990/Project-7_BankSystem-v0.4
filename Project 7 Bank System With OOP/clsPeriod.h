//class Period

#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsPeriod
{
private:

	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	void SetStartDate(clsDate Date)
	{
		_StartDate = Date;
	}

	clsDate GetStartDate()
	{
		return _StartDate;
	}

	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;

	//----------------------

	void SetEndDate(clsDate Date)
	{
		_EndDate = Date;
	}

	clsDate GetEndDate()
	{
		return _EndDate;
	}

	__declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;

	//----------------------

	static bool IsOverlap(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::After
			)
			return false;
		else
			return true;
	}

	//----------------------

	static bool IsDateInPeriod(clsPeriod Period, clsDate Date)
	{
		return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before || clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
	}

	bool IsDateInPeriod(clsDate Date)
	{
		return IsDateInPeriod(*this, Date);
	}

	//----------------------

	static int Length(clsPeriod Period, bool IncludeEndDay = false)
	{
		return clsDate::GetDiffranceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	int Length()
	{
		return Length(*this, true);
	}

	//----------------------

	/*int CountOverlapDays(stPeriod Period1, stPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period1.StartDate, Period2))
					OverlapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period2.StartDate, Period1))
					OverlapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}
		return OverlapDays;
	}*/

	//----------------------

	void Print()
	{
		cout << "Strat Date : ";
		_StartDate.Print();

		cout << "End Date   : ";
		_EndDate.Print();
	}

	//----------------------
};