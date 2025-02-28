//class Date

#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include <ctime>
#include "clsString.h";
using namespace std;

class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(string stringDate)
	{
		vector <string> vDate = clsString::Split(stringDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short DaysOrderInYear, short Year)
	{
		clsDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date._Year;
	}

	//--------------------------------

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	//--------------------------------

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	//--------------------------------

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	//--------------------------------

	static bool IsValidDate(clsDate Date)
	{
		return (Date.Day >= 1 && Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year)) && (Date.Month >= 1 && Date.Month <= 12);
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	//--------------------------------

	void Print()
	{
		cout << DateToString() << endl;
		//cout << Formate(DateFormat);
	}

	//--------------------------------

	static clsDate GetSystemDate()
	{
		short Day, Month, Year;

		time_t t = time(0);
		tm* now = localtime(&t);

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}

	//--------------------------------

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day)) + "/" + (to_string(Month)) + "/" + (to_string(Year)) 
			+ " - " + (to_string(Hour)) + ":" + (to_string(Minute)) + ":" + (to_string(Second));
	}

	//--------------------------------

	static bool IsLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	//--------------------------------

	static short NumberOfDaysInAYear(short Year)
	{
		return (IsLeapYear(Year) ? 366 : 365);
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	//--------------------------------

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	//--------------------------------

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	//--------------------------------

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	//--------------------------------

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		if (Month == 2)
		{
			return IsLeapYear(Year) ? 29 : 28;
		}

		short arr31Days[7] = { 1,3,5,7,8,10,12 };

		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1] == Month)
			{
				return 31;
			}
		}
		return 30;
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	//--------------------------------

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return NumberOfDaysInAMonth(Month, Year) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	//--------------------------------

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	//--------------------------------

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	//--------------------------------

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;

		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		short a, y, m;

		a = (14 - Date._Month) / 12;

		y = Date._Year - a;
		m = Date._Month + (12 * a) - 2;

		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}

	//--------------------------------

	static string DayShortName(short DayNumber)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayNumber];
	}

	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	//--------------------------------

	static string MonthShortName(short Month)
	{
		string arrMonthName[] = { "Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };

		return arrMonthName[Month - 1];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	//--------------------------------

	static void PrintMonthCalender(short Month, short Year)
	{
		short Current = DayOfWeekOrder(1, Month, Year);
		short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		printf("  _______________%s_______________\n\n", MonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < Current; i++)
		{
			printf("     ");
		}

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  _________________________________\n");
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	//--------------------------------

	static void PrintYearCalender(short Year)
	{
		printf("  _________________________________\n\n");
		printf("         Calender _ %d\n", Year);
		printf("  _________________________________\n\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
			cout << "\n";
		}
	}

	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	//--------------------------------

	static short TotalDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}

	static short TotalDaysFromTheBeginningOfTheYear(clsDate Date)
	{
		return TotalDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	}

	short TotalDaysFromTheBeginningOfTheYear()
	{
		return TotalDaysFromTheBeginningOfTheYear(*this);
	}

	//--------------------------------

	static clsDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DaysOrderInYear;
		short NumberOfDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			NumberOfDays = NumberOfDaysInAMonth(Date._Month, Date._Year);

			if (RemainingDays > NumberOfDays)
			{
				RemainingDays -= NumberOfDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	};

	//--------------------------------

	void AddDays(short Days)
	{
		short RemainingDays = Days + TotalDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}

	//--------------------------------

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	//--------------------------------

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	//--------------------------------

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	//--------------------------------

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;


		return enDateCompare::After;
	}

	//--------------------------------

	static bool IsLastDayInAMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastDayInAMonth()
	{
		return IsLastDayInAMonth(*this);
	}

	//--------------------------------

	static bool IsLastMonthInAYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInAYear()
	{
		return IsLastMonthInAYear(_Month);
	}

	//--------------------------------

	static clsDate AddOneDay(clsDate& Date)
	{
		if (IsLastDayInAMonth(Date))
		{
			Date.Day = 1;

			if (IsLastMonthInAYear(Date.Month))
			{
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	void AddOneDay()
	{
		AddOneDay(*this);
	}

	//--------------------------------

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	//--------------------------------

	static int GetDiffranceInDays(clsDate Date1, clsDate Date2, bool InCludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			while (IsDate1BeforeDate2(Date1, Date2))
			{
				Days++;
				Date1 = AddOneDay(Date1);
			}
		}
		return (InCludeEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDiffranceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDiffranceInDays(*this, Date2, IncludeEndDay);
	}

	//--------------------------------

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDiffranceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}

	//--------------------------------

	static clsDate AddXDays(clsDate& Date, short Days)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void AddXDays(short Days)
	{
		AddXDays(*this, Days);
	}

	//--------------------------------

	static clsDate AddOneWeek(clsDate& Date)
	{
		/*for (short i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}*/
		Date = AddXDays(Date, 7);
		return Date;
	}

	void AddOneWeek()
	{
		AddOneWeek(*this);
	}

	//--------------------------------

	static clsDate AddXWeeks(clsDate& Date, short Weeks)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = AddOneWeek(Date);
		}
		return Date;
	}

	void AddXWeeks(short Weeks)
	{
		AddXWeeks(*this, Weeks);
	}

	//--------------------------------

	static clsDate AddOneMonth(clsDate& Date)
	{
		if (IsLastMonthInAYear(Date.Month))
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void AddOneMonth()
	{
		AddOneMonth(*this);
	}

	//--------------------------------

	static clsDate AddXMonths(clsDate& Date, short Months)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = AddOneMonth(Date);
		}
		return Date;
	}

	void AddXMonths(short Months)
	{
		AddXMonths(*this, Months);
	}

	//--------------------------------

	static clsDate AddOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}

	void AddOneYear()
	{
		AddOneYear(*this);
	}

	//--------------------------------

	static clsDate AddXYears(clsDate& Date, short Years)
	{
		Date.Year += Years;
		return Date;
	}

	void AddXYears(short Years)
	{
		AddXYears(*this, Years);
	}

	//--------------------------------

	static clsDate AddOneDecade(clsDate& Date)
	{
		//One Decade = 10 Years.

		Date.Year += 10;
		return Date;
	}

	void AddOneDecade()
	{
		AddOneDecade(*this);
	}

	//--------------------------------

	static clsDate AddXDecades(clsDate& Date, short Decades)
	{
		Date.Year += (Decades * 10);
		return Date;
	}

	void AddXDecades(short Decades)
	{
		AddXDecades(*this, Decades);
	}

	//--------------------------------

	static clsDate AddOneCentury(clsDate& Date)
	{
		//One Century = 100 Years.

		Date.Year += 100;
		return Date;
	}

	void AddOneCentury()
	{
		AddOneCentury(*this);
	}

	//--------------------------------

	static clsDate AddOneMillennium(clsDate& Date)
	{
		//One Millennium = 1000 Years.

		Date.Year += 1000;
		return Date;
	}

	void AddOneMillennium()
	{
		AddOneMillennium(*this);
	}

	//--------------------------------

	static bool IsFirstMonthInAYear(short Month)
	{
		return (Month == 1);
	}

	bool IsFirstMonthInAYear()
	{
		return IsFirstMonthInAYear(_Month);
	}

	//--------------------------------

	static bool IsFirstDayInAMonth(short Day)
	{
		return (Day == 1);
	}

	bool IsFirstDayInAMonth()
	{
		return IsFirstDayInAMonth(_Day);
	}

	//--------------------------------

	static clsDate DecreaseOneDay(clsDate& Date)
	{
		if (Date.IsFirstDayInAMonth())
		{
			if (Date.IsFirstMonthInAYear())
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	void DecreaseOneDay()
	{
		DecreaseOneDay(*this);
	}

	//--------------------------------

	static clsDate DecreaseXDays(clsDate& Date, short Days)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseOneDay(Date);
		}
		return Date;
	}

	void DecreaseXDays(short Days)
	{
		DecreaseXDays(*this, Days);
	}

	//--------------------------------

	static clsDate DecreaseOneWeek(clsDate& Date)
	{
		Date = DecreaseXDays(Date, 7);
		return Date;
	}

	void DecreaseOneWeek()
	{
		DecreaseOneWeek(*this);
	}

	//--------------------------------

	static clsDate DecreaseXWeeks(clsDate& Date, short Weeks)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseOneWeek(Date);
		}
		return Date;
	}

	void DecreaseXWeeks(short Weeks)
	{
		DecreaseXWeeks(*this, Weeks);
	}

	//--------------------------------

	static clsDate DecreaseOneMonth(clsDate& Date)
	{
		if (Date.IsFirstDayInAMonth())
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		short NumberofDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberofDaysInCurrentMonth)
		{
			Date.Day = NumberofDaysInCurrentMonth;
		}

		return Date;
	}

	void DecreaseOneMonth()
	{
		DecreaseOneMonth(*this);
	}

	//--------------------------------

	static clsDate DecreaseXMonths(clsDate& Date, short Months)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseOneMonth(Date);
		}
		return Date;
	}

	void DecreaseXMonths(short Months)
	{
		DecreaseXMonths(*this, Months);
	}

	//--------------------------------

	static clsDate DecreaseOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}

	void DecreaseOneYear()
	{
		DecreaseOneYear(*this);
	}

	//--------------------------------

	static clsDate DecreaseXYears(clsDate& Date, short Years)
	{
		Date.Year -= Years;
		return Date;
	}

	void DecreaseXYears(short Years)
	{
		DecreaseXYears(*this, Years);
	}

	//--------------------------------

	static clsDate DecreaseOneDecade(clsDate& Date)
	{
		//One Decade = 10 Years.

		Date.Year -= 10;
		return Date;
	}

	void DecreaseOneDecade()
	{
		DecreaseOneDecade(*this);
	}

	//--------------------------------

	static clsDate DecreaseXDecades(clsDate& Date, short Decades)
	{
		Date.Year -= (10 * Decades);
		return Date;
	}

	void DecreaseXDecades(short Decades)
	{
		DecreaseXDecades(*this, Decades);
	}

	//--------------------------------

	static clsDate DecreaseOneCentury(clsDate& Date)
	{
		//One Century = 100 Years.

		Date.Year -= 100;
		return Date;
	}

	void DecreaseOneCentury()
	{
		DecreaseOneCentury(*this);
	}

	//--------------------------------

	static clsDate DecreaseOneMillennium(clsDate& Date)
	{
		//One Millennium = 1000 Years.

		Date.Year -= 1000;
		return Date;
	}

	void DecreaseOneMillennium()
	{
		DecreaseOneMillennium(*this);
	}

	//--------------------------------

	enum enWeekDays { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6 };

	static bool IsEndOfWeek(clsDate Date)
	{
		//End Of Week : Sat.

		return (DayOfWeekOrder(Date) == enWeekDays::Sat);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	//--------------------------------

	static bool IsWeekEnd(clsDate Date)
	{
		//Week End : Fri and (Thu Or Sat).
		short DayIndex = DayOfWeekOrder(Date);

		return (DayIndex == enWeekDays::Fri) || (DayIndex == enWeekDays::Sat);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	//--------------------------------

	static bool IsBusinessDay(clsDate Date)
	{
		//Not Business Day : Fri and Thu.

		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	//--------------------------------

	static short CalculateBussinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}
		return Days;
	}

	//--------------------------------

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return (short)enWeekDays::Sat - DayOfWeekOrder(Date);
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	//--------------------------------

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDiffranceInDays(Date, EndOfMonthDate, true);

		//return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	//--------------------------------

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDiffranceInDays(Date, EndOfYearDate, true);

		//return NumberOfDaysInAYear(Date.Year) - TotalDaysFromTheBeginningOfTheYear(Date);
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	//--------------------------------

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		/*short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}
		return Days;*/

		return CalculateBussinessDays(DateFrom, DateTo);
	}

	//--------------------------------

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom))
			{
				WeekEndCounter++;
			}

			DateFrom = AddOneDay(DateFrom);
		}

		// Date : 1/1/2022  
		//Vacation Days : 5
		//Come to Work in Friday.That Wrong.

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = AddOneDay(DateFrom);
		}
		return  DateFrom;
	}

	//--------------------------------

	static clsDate StringToDate(string DateString, string delimiter)
	{
		clsDate Date;
		vector <string> vDateString = clsString::Split(DateString, delimiter);

		Date._Day = stoi(vDateString[0]);
		Date._Month = stoi(vDateString[1]);
		Date._Year = stoi(vDateString[2]);

		return Date;
	}

	//--------------------------------

	static string DateToString(clsDate Date, string delimiter = "/")
	{
		return to_string(Date.Day) + delimiter + to_string(Date.Month) + delimiter + to_string(Date.Year);
	}

	string DateToString(string delimiter = "/")
	{
		return DateToString(*this, delimiter);
	}

	//--------------------------------

	static string Formate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWords(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = clsString::ReplaceWords(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = clsString::ReplaceWords(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}

	string Formate(string DateFormat = "dd/mm/yyyy")
	{
		return Formate(*this, DateFormat);
	}

	//--------------------------------
};