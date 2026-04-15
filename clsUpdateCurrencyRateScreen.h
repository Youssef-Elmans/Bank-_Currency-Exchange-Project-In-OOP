#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"clsInputValidation.h";
using namespace std;
class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:
	static float _ReadCurrencyRate() {
		float CurrencyRate = clsInputValidation::ReadFloatNumber("\nEnter NewRate: ");
		return CurrencyRate;
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
public:
	static void ShowUpdateCurrencyRateScreen() {
		_DrawScreenHeader("\t Update Currency Screen");
		string CurrencyCode = "";
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidation::ReadString();
		while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode)) {
			cout << "\nCurrency Wanted Is Not Found, Choose another One: ";
			CurrencyCode = clsInputValidation::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyRecord(Currency1);
		cout << "\n\nAre You Sure You Want To Update The Rate Of This Currency? Y/N ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";
			Currency1.UpdateRate(_ReadCurrencyRate());

			cout << "\Currency Updated Successfully :-)\n";
			_PrintCurrencyRecord(Currency1);


		}
		else
			cout << "\nThe Operation Was Cancelled !\n";
	}
};