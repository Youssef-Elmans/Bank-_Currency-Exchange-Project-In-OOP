#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsInputValidation
{
public:

	static int ReadIntNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		int Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static int ReadPositiveIntNumber(string Message)
	{
		int Number = 0;
		do
		{
			Number = ReadIntNumber(Message);
		} while (Number <= 0);

		return Number;
	}


	static short ReadShortNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		short Number;
		cout << Message;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static short ReadPositiveShortNumber(string Message)
	{
		short Number = 0;
		do
		{
			Number = ReadShortNumber(Message);
		} while (Number <= 0);
		return Number;
	}
	static float ReadFloatNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		float Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static float ReadPositiveFloatNumber(string Message)
	{
		float Number = 0;
		do
		{
			Number = ReadFloatNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static double ReadDoubleNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n")
	{
		double Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static double ReadPositiveDoubleNumber(string Message)
	{
		double Number = 0;
		do
		{
			Number = ReadDoubleNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static long ReadLongNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n") {
		long Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static long ReadPositiveLongNumber(string Message)
	{
		long Number = 0;
		do
		{
			Number = ReadLongNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static long long ReadLongLongNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n") {
		long long Number;
		cout << Message << endl;
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static long long ReadPositiveLongLongNumber(string Message)
	{
		long long Number = 0;
		do
		{
			Number = ReadLongLongNumber(Message);
		} while (Number <= 0);

		return Number;
	}
	static bool ReadBoolNumber(string Message, string ErrorMessage = "Invalid Number , Enter a Valid One : \n") {
		bool Number = false;
		do {
			cout << Message << endl;
			cin >> Number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
				cin >> Number;
			}
		} while (Number > 1 || Number < 0);
		return Number;
	}

	static bool IsNumberBetween(int From, int To, int ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(short From, short To, short ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(float From, float To, float ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(double From, double To, double ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(long From, long To, long ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static bool IsNumberBetween(long long From, long long To, long long ComparedNumber) {
		return (ComparedNumber >= From && ComparedNumber <= To);
	}
	static int ReadIntNumberBetween(int From, int To, string NotValidNumberMessage) {
		int Number;
		Number = ReadIntNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadIntNumber("");
		}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string NotValidNumberMessage) {
		short Number;
		Number = ReadShortNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadShortNumber("");
		}
		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string NotValidNumberMessage) {
		float Number;
		Number = ReadFloatNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadFloatNumber("");
		}
		return Number;
	}
	static long ReadLongNumberBetween(long From, long To, string NotValidNumberMessage) {
		long Number;
		Number = ReadLongNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadLongNumber("");
		}
		return Number;
	}
	static long long ReadLongLongNumberBetween(long long From, long long To, string NotValidNumberMessage) {
		long long Number;
		Number = ReadLongLongNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadLongLongNumber("");
		}
		return Number;
	}
	static double ReadDoubleNumberBetween(double From, double To, string NotValidNumberMessage) {
		double Number;
		Number = ReadDoubleNumber("");
		while (!IsNumberBetween(From, To, Number)) {
			cout << NotValidNumberMessage << endl;
			Number = ReadDoubleNumber("");
		}
		return Number;
	}
	static char ReadChar(string Message) {
		char Character;
		cout << Message;
		cin >> Character;
		return Character;
	}
	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};