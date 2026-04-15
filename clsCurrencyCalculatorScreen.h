#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsCurrency.h";
#include"clsString.h";
using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency Currency, string Title = "\nCurrency Card: \n") {
		cout << Title;
		cout << "--------------------------------------------------\n";
		cout << "Country         : " << Currency.Country() << endl;
		cout << "Code            : " << Currency.CurrencyCode() << endl;
		cout << "Name            : " << Currency.CurrencyName() << endl;
		cout << "Rate/(1$)       : " << Currency.Rate() << endl;
		cout << "--------------------------------------------------\n";
	}
	static string _ReadCurrencyCode(string Message) {
		string CurrencyCode = "";
		cout << endl << Message;
		CurrencyCode = clsInputValidation::ReadString();
		while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode)) {
			cout << "\nCurrency Wanted Is Not Found, Choose another One: ";
			cout << endl << Message;
			CurrencyCode = clsInputValidation::ReadString();
		}

		return CurrencyCode;
	}
	static float _ReadExchangeAmount() {
		float ExchangeAmount = 0;
		ExchangeAmount = clsInputValidation::ReadFloatNumber("\nEnter Amount To Exchange: ");
		return ExchangeAmount;
	}
	static clsCurrency _GetCurrency(string Message) {
		string CurrencyCode = _ReadCurrencyCode(Message);
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}
	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo) {
		if (CurrencyFrom.CurrencyCode() == "USD") {
			_PrintCurrencyRecord(CurrencyFrom, "Convert From:\n");
			_PrintCurrencyRecord(CurrencyTo, "To:\n");
			float AmountInCurrencyTo = CurrencyTo.ConvertUSDToIt(Amount);
			cout << Amount << " " << "USD" << " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode() << endl;
		}
		else {
			_PrintCurrencyRecord(CurrencyFrom, "Convert From:\n");
			float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " " << "USD\n";

			if (CurrencyTo.CurrencyCode() == "USD")
			{
				return;

			}

			cout << "\nConverting from USD to:\n";
			_PrintCurrencyRecord(CurrencyTo, "To:\n");
			float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode() << endl;
		}
	}
public:
	static void ShowCurrencyCalculatorScreen() {
		char Continue = 'y';
		while (Continue == 'Y' || Continue == 'y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");
			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currency2 Code: ");
			float ExchangeAmount = _ReadExchangeAmount();
			_PrintCalculationResult(ExchangeAmount, CurrencyFrom, CurrencyTo);

			cout << "\nDo You Wante To Perform Another Calculation? y/n ? ";

			cin >> Continue;


		}


	}
};