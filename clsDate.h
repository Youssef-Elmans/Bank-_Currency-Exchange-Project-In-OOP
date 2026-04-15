#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include "clsString.h";
#include<string>
#include"clsInputValidation.h"
using namespace std;
class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;
	bool IsPositive(short Number) {
		return Number > 0;
	}
public:
	enum enCompare2Dates { Before = -1, Equal = 0, After = 1 };
	void SetDay(short Day) {

		_Day = (IsPositive(Day)) ? Day : 1;

	}
	short GetDay() {
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay))short Day;
	void SetMonth(short Month) {
		_Month = (IsPositive(Month)) ? Month : 1;
	}
	short GetMonth() {
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth))short Month;
	void SetYear(short Year) {
		_Year = (IsPositive(Year)) ? Year : 1;
	}
	short GetYear() {
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear))short Year;
	clsDate() {
		*this = GetSystemDate();
	}

	clsDate(string DateInString) {
		*this = ConvertStringDateToDateClass(DateInString);
	}

	clsDate(short Day, short Month, short Year) {
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DayOrderInYear, short Year) {
		*this = GetDateFromDayOrderInYear(Year, DayOrderInYear);
	}
	static void Print(clsDate Date) {
		cout << ConvertDateToString(Date);
	}
	void Print() {
		Print(*this);
	}
	static bool LeapNotLeapYear(short Year) {
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}
	bool LeapNotLeapYear() {
		return LeapNotLeapYear(_Year);
	}
	static short NumberOfDaysInYear(short Year) {
		return (LeapNotLeapYear(Year)) ? 366 : 365;
	}
	short NumberOfDaysInYear() {
		return NumberOfDaysInYear(_Year);
	}
	static short NumberOfHoursInYear(short Year) {
		return NumberOfDaysInYear(Year) * 24;
	}
	short NumberOfHoursInYear() {
		return NumberOfHoursInYear(_Year);
	}
	static int NumberOfMinutesInYear(short Year) {
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear() {
		return NumberOfMinutesInYear(_Year);
	}


	static int NumberOfSecondsOfYear(short Year) {
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsOfYear() {
		return NumberOfSecondsOfYear(_Year);
	}

	static short NumberOfDaysInMonth(short Year, short Month) {
		if (Month < 1 || Month>12)
			return 0;

		short arrNumberOfDaysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


		return (Month == 2) ? (LeapNotLeapYear(Year) ? 29 : 28) : arrNumberOfDaysInMonths[Month - 1];
	}

	short NumberOfDaysInMonth() {
		return NumberOfDaysInMonth(_Year, _Month);
	}


	static short NumberOfHoursInMonth(short Year, short Month) {
		return NumberOfDaysInMonth(Year, Month) * 24;
	}

	short NumberOfHoursInMonth() {
		return NumberOfHoursInMonth(_Year, _Month);
	}


	static short NumberOfMinutesInMonth(short Year, short Month) {
		return NumberOfHoursInMonth(Year, Month) * 60;
	}

	short NumberOfMinutesInMonth() {
		return NumberOfMinutesInMonth(_Year, _Month);
	}


	static short NumberOfSecondsInMonth(short Year, short Month) {
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}


	short NumberOfSecondsInMonth() {
		return NumberOfSecondsInMonth(_Year, _Month);
	}
	static short DayIndexInWeek(short Year, short Month, short Day) {
		short a = (14 - Month) / 12;

		short y = Year - a;

		short m = Month + 12 * a - 2;

		short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	short DayIndexInWeek() {
		return DayIndexInWeek(_Year, _Month, _Day);
	}
	static short DayIndexInWeek(clsDate Date) {
		return DayIndexInWeek(Date.Year, Date.Month, Date.Day);
	}
	static string MonthShortName(short Month) {
		string arrNameOfMonths[12] = {
			"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
			"Aug", "Sep", "Oct", "Nov", "Dec"
		};
		return arrNameOfMonths[Month - 1];
	}
	string MonthShortName() {
		return MonthShortName(_Month);
	}
	static void PrintMonthCalender(short Year, short Month) {

		short NumberOfDays = NumberOfDaysInMonth(Year, Month);

		short OrderOfFirstDayInMonthOfTheWeek = DayIndexInWeek(Year, Month, 1);

		printf("   __________________%s___________________\n\n", MonthShortName(Month).c_str());

		printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

		short i = 0;

		for (i = 0; i < OrderOfFirstDayInMonthOfTheWeek; i++)
			printf("      ");

		for (short j = 1; j <= NumberOfDays; j++) {
			printf("%6d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}

		printf("\n   ________________________________________\n\n");
	}
	void PrintMonthCalender() {
		PrintMonthCalender(_Year, _Month);
	}
	static void PrintYearCalender(short Year) {
		printf("   ________________________________________\n\n");
		printf("                 Calender - %d\n", Year);
		printf("   ________________________________________\n\n");
		for (short i = 1; i <= 12; i++) {
			PrintMonthCalender(Year, i);
		}

	}
	void PrintYearCalender() {
		PrintYearCalender(_Year);
	}
	static clsDate ReadFullDate() {
		clsDate Date;
		Date.Day = clsInputValidation::ReadShortNumber("Please Enter a Day? ");
		cout << "\n\n";
		Date.Month = clsInputValidation::ReadShortNumber("Please Enter a Month? ");
		cout << "\n\n";
		Date.Year = clsInputValidation::ReadShortNumber("Please Enter a Year? ");
		cout << "\n\n";
		return Date;
	}
	void ReadAndModifyObjectFullDate() {
		*this = ReadFullDate();
	}
	static short TotalDaysFromYearBeginning(short Year, short Month, short Day) {
		short CounterNumberOfDays = 0;
		for (short i = 1; i < Month; i++) {
			CounterNumberOfDays += NumberOfDaysInMonth(Year, i);
		}
		CounterNumberOfDays += Day;
		return CounterNumberOfDays;
	}
	short TotalDaysFromYearBeginning() {
		return TotalDaysFromYearBeginning(_Year, _Month, _Day);
	}
	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDates(DateOfBirth, GetSystemDate(), true);
	}
	static clsDate GetDateFromDayOrderInYear(short Year, short DayOrderInYear) {
		clsDate Date;
		Date.Year = Year;
		Date.Month = 1;
		short MonthDays = 0;
		short RemainingDays = DayOrderInYear;
		while (true) {
			MonthDays = NumberOfDaysInMonth(Year, Date.Month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate GetDateFromDayOrderInYear(short DayOrderInYear) {
		return GetDateFromDayOrderInYear(_Year, DayOrderInYear);
	}
	static clsDate GetDateAfterAddingDays(clsDate DateAfterAddingDays, int DaysToAdd) {
		int RemainingDays = DaysToAdd + TotalDaysFromYearBeginning(DateAfterAddingDays.Year,
			DateAfterAddingDays.Month, DateAfterAddingDays.Day);
		int MonthDays = 0;
		DateAfterAddingDays.Month = 1;
		while (true) {
			MonthDays = NumberOfDaysInMonth(DateAfterAddingDays.Year, DateAfterAddingDays.Month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				DateAfterAddingDays.Month++;
				if (DateAfterAddingDays.Month > 12) {
					DateAfterAddingDays.Month = 1;
					DateAfterAddingDays.Year++;
				}
			}
			else {
				DateAfterAddingDays.Day = RemainingDays;
				break;
			}

		}
		return DateAfterAddingDays;
	}
	clsDate GetDateAfterAddingDays(int DaysToAdd) {
		return GetDateAfterAddingDays(*this, DaysToAdd);
	}
	static bool IsDate1EqualToDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDateEqualToDate2(clsDate Date2) {
		return IsDate1EqualToDate2(*this, Date2);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)) : false);

	}
	bool IsDateBeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsLastDayInMonth(clsDate Date) {
		return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) ? true : false;
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}
	static bool IsLastMonthInYear(short Month) {
		return (Month == 12) ? true : false;
	}
	static clsDate IncreaseDateByOneDay(clsDate DateAfterAddingOneDay) {

		if (IsLastDayInMonth(DateAfterAddingOneDay)) {

			if (IsLastMonthInYear(DateAfterAddingOneDay.Month)) {
				DateAfterAddingOneDay.Day = 1;
				DateAfterAddingOneDay.Month = 1;
				DateAfterAddingOneDay.Year++;
			}
			else {
				DateAfterAddingOneDay.Day = 1;
				DateAfterAddingOneDay.Month++;
			}

		}

		else
			DateAfterAddingOneDay.Day++;

		return DateAfterAddingOneDay;
	}
	void AddOneDay() {
		*this = IncreaseDateByOneDay(*this);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2) {
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}
	void SwapDate(clsDate& Date2) {
		SwapDates(*this, Date2);
	}
	static bool IsDateBetween(clsDate DateFrom, clsDate DateTo, clsDate ComparedDate) {
		if (!(CompareDates(ComparedDate, DateTo) == enCompare2Dates::After
			||
			CompareDates(ComparedDate, DateFrom) == enCompare2Dates::Before))
		{
			return true;
		}

		if (!(CompareDates(ComparedDate, DateFrom) == enCompare2Dates::After
			||
			CompareDates(ComparedDate, DateTo) == enCompare2Dates::Before))
		{
			return true;
		}

		return false;
	}
	bool IsBetween(clsDate Date1, clsDate Date2) {
		return IsDateBetween(Date1, Date2, *this);
	}
	static short GetDifferenceInDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
		short DifferenceInDays = 0;
		short SwapValueFlag = 1;
		if (!(IsDate1BeforeDate2(Date1, Date2) || IsDate1EqualToDate2(Date1, Date2))) {
			SwapValueFlag = -1;
			SwapDates(Date1, Date2);
		}
		while (IsDate1BeforeDate2(Date1, Date2)) {
			DifferenceInDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay) ? ++DifferenceInDays * SwapValueFlag : DifferenceInDays * SwapValueFlag;
	}
	short GetDifferenceInDates(clsDate Date2, bool IncludeEndDay = false) {
		return GetDifferenceInDates(*this, Date2, IncludeEndDay);
	}

	static clsDate GetSystemDate() {
		time_t t = time(0);
		tm* Timenow = localtime(&t);
		short Day, Month, Year;
		Year = Timenow->tm_year + 1900;
		Month = Timenow->tm_mon + 1;
		Day = Timenow->tm_mday;
		return clsDate(Day, Month, Year);
	}
	
	static short MakeSureDayNotExceedsMonthDaysAndValidate(clsDate Date) {
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

		return 	(Date.Day > NumberOfDaysInCurrentMonth) ? NumberOfDaysInCurrentMonth : Date.Day;
	}
	void MakeSureDayNotExceedsMonthDaysAndValidate() {
		_Day = MakeSureDayNotExceedsMonthDaysAndValidate(*this);
	}
	static clsDate IncreaseDateByXdays(short XdaysToAdd, clsDate Date) {
		for (short i = 1; i <= XdaysToAdd; i++)
			Date = IncreaseDateByOneDay(Date);
		return Date;
	}
	void IncreaseDateByXdays(short XdaysToAdd) {
		*this = IncreaseDateByXdays(XdaysToAdd, *this);
	}
	static clsDate IncreaseDateByoneWeek(clsDate Date) {

		for (short i = 1; i <= 7; i++)
			Date = IncreaseDateByOneDay(Date);

		return Date;
	}
	void IncreaseDateByoneWeek() {
		*this = IncreaseDateByoneWeek(*this);
	}

	static clsDate IncreaseDateByXweeks(clsDate Date, short XweeksToAdd) {
		for (short i = 1; i <= XweeksToAdd; i++)
			Date = IncreaseDateByoneWeek(Date);

		return Date;
	}
	void IncreaseDateByXweeks(short XweeksToAdd) {
		*this = IncreaseDateByXweeks(*this, XweeksToAdd);
	}

	static clsDate IncreaseDateByoneMonth(clsDate Date) {
		if (Date.Month == 12) {
			Date.Month == 1;
			Date.Year++;
		}
		else
			Date.Month++;


		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void IncreaseDateByoneMonth() {
		*this = IncreaseDateByoneMonth(*this);
	}
	static clsDate IncreaseDateByXmonths(clsDate Date, short XmonthsToAdd) {

		for (short i = 1; i <= XmonthsToAdd; i++)
			Date = IncreaseDateByoneMonth(Date);

		return Date;
	}
	void IncreaseDateByXmonths(short XmonthsToAdd) {
		*this = IncreaseDateByXmonths(*this, XmonthsToAdd);
	}
	static clsDate IncreaseDateByOneYear(clsDate Date) {

		Date.Year++;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void IncreaseDateByOneYear() {
		*this = IncreaseDateByOneYear(*this);
	}


	static clsDate IncreaseDateByXyears(clsDate Date, short XyearsToAdd) {

		Date.Year += XyearsToAdd;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void IncreaseDateByXyears(short XyearsToAdd) {
		*this = IncreaseDateByXyears(*this, XyearsToAdd);
	}
	static clsDate IncreaseDateByOneDecade(clsDate Date) {

		Date.Year += 10;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void IncreaseDateByOneDecade() {
		*this = IncreaseDateByOneDecade(*this);
	}


	static clsDate IncreaseDateByXdecades(clsDate Date, short XdecadesToAdd) {

		Date.Year += XdecadesToAdd * 10;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void IncreaseDateByXdecades(short XdecadesToAdd) {
		*this = IncreaseDateByXdecades(*this, XdecadesToAdd);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date) {
		Date.Year += 100;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void IncreaseDateByOneCentury() {
		*this = IncreaseDateByOneCentury(*this);
	}
	static clsDate IncreaseDateByOneMillennium(clsDate Date) {
		Date.Year += 1000;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void IncreaseDateByOneMillennium() {
		*this = IncreaseDateByOneMillennium(*this);
	}
	static bool IsFirstDayInMonth(short Day) {
		return (Day == 1) ? true : false;
	}
	bool IsFirstDayInMonth() {
		return IsFirstDayInMonth(this->Day);
	}
	static bool IsFirstMonthInYear(short Month) {
		return (Month == 1) ? true : false;
	}
	bool IsFirstMonthInYear() {
		return IsFirstMonthInYear(this->Month);
	}
	static clsDate DecreaseDateByOneDay(clsDate DateAfterAddingOneDay) {
		if (IsFirstDayInMonth(DateAfterAddingOneDay.Day)) {

			if (IsFirstMonthInYear(DateAfterAddingOneDay.Month)) {
				DateAfterAddingOneDay.Day = 31;
				DateAfterAddingOneDay.Month = 12;
				DateAfterAddingOneDay.Year--;
			}
			else {
				DateAfterAddingOneDay.Month--;
				DateAfterAddingOneDay.Day = NumberOfDaysInMonth(DateAfterAddingOneDay.Year, DateAfterAddingOneDay.Month);
			}

		}

		else
			DateAfterAddingOneDay.Day--;

		return DateAfterAddingOneDay;
	}
	void  DecreaseDateByOneDay() {
		*this = DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByXdays(clsDate Date, short XdaysToSubstract) {
		for (short i = 1; i <= XdaysToSubstract; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}
	void DecreaseDateByXdays(short XdaysToSubstract) {
		*this = DecreaseDateByXdays(*this, XdaysToSubstract);
	}
	static clsDate DecreaseDateByoneWeek(clsDate Date) {

		for (short i = 1; i <= 7; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}
	void DecreaseDateByoneWeek() {
		*this = DecreaseDateByoneWeek(*this);
	}

	static clsDate DecreaseDateByXweeks(clsDate Date, short XweeksToSubstract) {
		for (short i = 1; i <= XweeksToSubstract; i++)
			Date = DecreaseDateByoneWeek(Date);

		return Date;
	}
	void DecreaseDateByXweeks(short XweeksToSubstract) {
		*this = DecreaseDateByXweeks(*this, XweeksToSubstract);
	}

	static clsDate DecreaseDateByoneMonth(clsDate Date) {
		if (Date.Month == 1) {
			Date.Month == 12;
			Date.Year--;
		}
		else
			Date.Month--;


		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void DecreaseDateByoneMonth() {
		*this = DecreaseDateByoneMonth(*this);
	}
	static clsDate DecreaseDateByXmonths(clsDate Date, short XmonthsToSubstract) {

		for (short i = 1; i <= XmonthsToSubstract; i++)
			Date = DecreaseDateByoneMonth(Date);

		return Date;
	}

	void DecreaseDateByXmonths(short XmonthsToSubstract) {
		*this = DecreaseDateByXmonths(*this, XmonthsToSubstract);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date) {

		Date.Year--;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void DecreaseDateByOneYear() {
		*this = DecreaseDateByOneYear(*this);
	}
	static clsDate DecreaseDateByXyears(clsDate Date, short XyearsToSubstract) {

		Date.Year -= XyearsToSubstract;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void DecreaseDateByXyears(short XyearsToSubstract) {
		*this = DecreaseDateByXyears(*this, XyearsToSubstract);
	}
	static clsDate DecreaseDateByOneDecade(clsDate Date) {

		Date.Year -= 10;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void DecreaseDateByOneDecade() {
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXdecades(clsDate Date, short XdecadesToSubstract) {

		Date.Year -= XdecadesToSubstract * 10;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void DecreaseDateByXdecades(short XdecadesToSubstract) {
		*this = DecreaseDateByXdecades(*this, XdecadesToSubstract);
	}
	static clsDate DecreaseDateByOneCentury(clsDate Date) {
		Date.Year -= 100;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);

		return Date;
	}
	void DecreaseDateByOneCentury() {
		*this = DecreaseDateByOneCentury(*this);
	}
	static clsDate DecreaseDateByOneMillennium(clsDate Date) {
		Date.Year -= 1000;
		Date.Day = MakeSureDayNotExceedsMonthDaysAndValidate(Date);
		return Date;
	}
	void DecreaseDateByOneMillennium() {
		*this = DecreaseDateByOneMillennium(*this);
	}
	static bool IsEndOfWeek(clsDate Date) {

		short DayOrderInWeek = DayIndexInWeek(Date);
		return DayOrderInWeek == 6;

	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {

		short DayOrderInWeek = DayIndexInWeek(Date);
		return DayOrderInWeek == 5 || DayOrderInWeek == 6;

	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}
	static bool IsBusinessDay(clsDate Date) {

		return !IsWeekEnd(Date);

	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date) {
		return 6 - DayIndexInWeek(Date);
	}
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date) {
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;
		return GetDifferenceInDates(Date, EndOfMonthDate, true);

	}
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date) {
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;
		return GetDifferenceInDates(Date, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}
	static string GetDayNameOfDate(clsDate Date) {
		string DayNames[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return DayNames[DayIndexInWeek(Date)];
	}
	string GetDayNameOfDate() {
		return GetDayNameOfDate(*this);
	}
	static short CalculateTheActualVacationDays(clsDate VacationStartDate, clsDate VacationEndDate) {

		short DaysCounter = 0;

		while (IsDate1BeforeDate2(VacationStartDate, VacationEndDate)) {

			if (IsBusinessDay(VacationStartDate))
				DaysCounter++;

			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);

		}

		return DaysCounter;
	}
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {
		return  CalculateTheActualVacationDays(DateFrom, DateTo);
	}
	static clsDate GetVacationEndDate(clsDate VacationStartDate, short VacationDays) {
		short WeekEndCounter = 0;

		while (IsWeekEnd(VacationStartDate))
			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++) {

			if (IsWeekEnd(VacationStartDate))
				WeekEndCounter++;

			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);
		}

		while (IsWeekEnd(VacationStartDate))
			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);

		return VacationStartDate;
	}
	clsDate GetVacationEndDate(short VacationDays) {
		return GetVacationEndDate(*this, VacationDays);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}
	static enCompare2Dates CompareDates(clsDate Date1, clsDate Date2) {
		if (IsDate1BeforeDate2(Date1, Date2))
			return enCompare2Dates::Before;

		if (IsDate1EqualToDate2(Date1, Date2))
			return enCompare2Dates::Equal;

		return enCompare2Dates::After;
	}
	enCompare2Dates CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}
	static bool IsValideDate(clsDate Date) {

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2) {
			if (LeapNotLeapYear(Date.Year)) {
				if (Date.Day > 29)
					return false;
			}
			else {
				if (Date.Day > 28)
					return false;
			}
		}
	}
	bool IsValide() {
		return IsValideDate(*this);
	}
	static clsDate ConvertStringDateToDateClass(string DateStr) {

		clsDate Date;

		vector<string> vDateParts;
		vDateParts = clsString::Split(DateStr, "/");
		Date.Day = (short)stoi(vDateParts[0]);
		Date.Month = (short)stoi(vDateParts[1]);
		Date.Year = (short)stoi(vDateParts[2]);
		return Date;
	}
	static string ConvertDateToString(clsDate Date) {
		string DateText = "";
		DateText += to_string(Date.Day) + "/";
		DateText += to_string(Date.Month) + "/";
		DateText += to_string(Date.Year);
		return DateText;
	}
	string ConvertToString() {
		return ConvertDateToString(*this);
	}
	static string FormatDate(string DateText, string Format = "dd/mm/yyyy") {
		string FormattedDate = "";
		clsDate Date = ConvertStringDateToDateClass(DateText);
		FormattedDate = clsString::ReplaceWordUsingBuiltInFunction(Format, "dd", to_string(Date.Day));
		FormattedDate = clsString::ReplaceWordUsingBuiltInFunction(FormattedDate, "mm", to_string(Date.Month));
		FormattedDate = clsString::ReplaceWordUsingBuiltInFunction(FormattedDate, "yyyy", to_string(Date.Year));


		return FormattedDate;
	}
	static string GetSystemDateTimeString() {
		time_t t = time(0);
		tm* Timenow = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = Timenow->tm_year + 1900;
		Month = Timenow->tm_mon + 1;
		Day = Timenow->tm_mday;
		Hour = Timenow->tm_hour;
		Minute = Timenow->tm_min;
		Second = Timenow->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
	}
};