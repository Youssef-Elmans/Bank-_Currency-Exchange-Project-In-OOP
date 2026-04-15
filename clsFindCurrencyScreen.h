#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsCurrency.h";
using namespace std;
class clsFindCurrencyScreen :protected clsScreen
{
private:
	enum enFindCurrencyWayOptions { eByCode = 1, ByCountry = 2 };
	static short _ReadFindCurrencyWayOption() {
		cout << "Find By: [1] Code Or [2] Country ? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 2, "Enter Number Between 1 To 2? ");
		return Choice;
	}
	static void _PrintCurrencyRecord(clsCurrency Currency) {
		cout << "\nCurrency Card: \n";
		cout << "--------------------------------------------------\n";
		cout << "Country         : " << Currency.Country() << endl;
		cout << "Code            : " << Currency.CurrencyCode() << endl;
		cout << "Name            : " << Currency.CurrencyName() << endl;
		cout << "Rate/(1$)       : " << Currency.Rate() << endl;
		cout << "--------------------------------------------------\n";
	}
	static void _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyRecord(Currency);
		}


		else
			cout << "\nUser Was Not Found :-)\n";
	}
public:
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
		clsCurrency Currency1 = clsCurrency::FindByCountry("");
		switch (enFindCurrencyWayOptions(_ReadFindCurrencyWayOption())) {
		case enFindCurrencyWayOptions::eByCode:
		{
			string CurrencyCode = "";
			cout << "\nPlease Enter Currency Code: ";
			CurrencyCode = clsInputValidation::ReadString();
			while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode)) {
				cout << "\Currency Is Not Found, Choose another One: ";
				CurrencyCode = clsInputValidation::ReadString();
			}
			Currency1 = clsCurrency::FindByCode(CurrencyCode);
			break;
		}
		case enFindCurrencyWayOptions::ByCountry:
		{
			string CountryName = "";
			cout << "\nPlease Enter Country Name: ";
			CountryName = clsInputValidation::ReadString();
			while (!clsCurrency::IsCurrencyExisByCountry(CountryName)) {
				cout << "\Currency Is Not Found, Choose another One: ";
				CountryName = clsInputValidation::ReadString();
			}
			Currency1 = clsCurrency::FindByCountry(CountryName);
			break;
		}
		}
		_ShowResults(Currency1);
	}
};