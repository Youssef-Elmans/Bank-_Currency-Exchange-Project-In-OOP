#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h";
#include"clsCurrency.h";
using namespace std;
class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency Currency) {
		cout << setw(8) << left << "" << "| " << left << setw(25) << Currency.Country();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(20) << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen() {
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currency(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "__________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(25) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t______________________________";
		cout << "_______________________________________________________________________\n\n";
		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Logged In The System!\n";

		else {
			for (clsCurrency& Currency : vCurrencies) {
				_PrintCurrencyRecord(Currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "___________________________________________";
		cout << "__________________________________________________________\n";
	}
};