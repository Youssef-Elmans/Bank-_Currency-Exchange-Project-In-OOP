#pragma once
#include<iostream>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsCurrenciesListScreen.h";
#include"clsInputValidation.h";
#include"clsFindCurrencyScreen.h";
#include"clsUpdateCurrencyRateScreen.h";
#include"clsCurrencyCalculatorScreen.h";
using namespace std;
class clsCurrencyExchangeScreen :protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eGoBackMainMenue = 5 };

	static short _ReadCurrencyExchangeMenueOption() {
		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 To 5]? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 5? ");
		return Choice;
	}
	static void _ShowListCurrenciesScreen() {
		//cout << "\nShow List Currencies Screen Will Be Here...\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen() {
		//cout << "\nShow Find Currency Screen Will Be Here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen() {
		//cout << "\nShow Update Rate Screen Will Be Here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen() {
		//cout << "\nShow Currency Calculator Screen Will Be Here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyExchangeMenue() {
		cout << "\n\nPress Any key To Go Back To Currency Exchange Menue...";
		system("pause>nul");
		ShowCurrencyExchangeMenue();
	}
	static void _PerformCurrencyExchangeMenueOptions(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption) {
		switch (CurrencyExchangeMenueOption) {
		case enCurrencyExchangeMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeMenueOptions::eGoBackMainMenue:
		{

		}
		}
	}
public:

	static void ShowCurrencyExchangeMenue() {
		if (!CheckAccessesRights(clsUser::enPermissions::pCurrencyExchange)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCurrencyExchangeMenueOptions((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
	}
};