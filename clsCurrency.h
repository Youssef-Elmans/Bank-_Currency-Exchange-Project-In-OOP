#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsString.h";
using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Delim = "#//#") {

		vector <string>vCurrencyData;
		vCurrencyData = clsString::Split(Line, Delim);
		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency CurrencyObj, string Delim = "#//#") {
		string CurrencyLine = "";
		CurrencyLine += CurrencyObj.Country() + Delim;
		CurrencyLine += CurrencyObj.CurrencyCode() + Delim;
		CurrencyLine += CurrencyObj.CurrencyName() + Delim;
		CurrencyLine += to_string(CurrencyObj.Rate());
		return CurrencyLine;
	}
	static vector <clsCurrency> _LoadCurrenciesDataFromFile() {
		vector <clsCurrency>vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}


		return vCurrencies;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencies) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		string DataLine;
		if (MyFile.is_open()) {
			for (clsCurrency& Currency : vCurrencies) {
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl;

			}
			MyFile.close();
		}
	}
	void _Update() {
		vector <clsCurrency> vCurrencies;
		vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency& Currency : vCurrencies) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}


	static clsCurrency _GetEmptyCurrencyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}
	float Rate() {
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line, "#//#");
				if (clsString::UpperAllLetters(Currency.CurrencyCode()) == clsString::UpperAllLetters(CurrencyCode)) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line, "#//#");
				if (clsString::UpperAllLetters(Currency.Country()) == clsString::UpperAllLetters(Country)) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrenciesDataFromFile();
	}

	static bool IsCurrencyExistByCode(string CurrencyCode) {
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency1.IsEmpty());
	}
	static bool IsCurrencyExisByCountry(string Country) {
		clsCurrency Currency1 = clsCurrency::FindByCountry(Country);
		return (!Currency1.IsEmpty());
	}
	float ConvertToUSD(float Amount) {
		return (Amount / Rate());
	}
	float ConvertUSDToIt(float DollarsAmount) {
		return (DollarsAmount * Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency CurrencyTo) {
		float AmountInUSD = ConvertToUSD(Amount);
		if (CurrencyTo.CurrencyCode() == "USD")
			return AmountInUSD;
		return (CurrencyTo.ConvertUSDToIt(AmountInUSD));
	}
};