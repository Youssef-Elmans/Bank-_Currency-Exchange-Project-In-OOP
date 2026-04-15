#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsClientListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h";
#include"clsTransactionsScreen.h";
#include"clsManageUsersScreen.h";
#include"Global.h";
#include"clsUser.h";
#include"clsLoginRegisterScreen.h";
#include"clsCurrencyExchangeScreen.h";
using namespace std;
class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchangeMenue = 9, eExit = 10
	};
	static short _ReadMainMenueOption() {
		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 To 10]? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 10, "Enter Number Between 1 To 10? ");
		return Choice;
	}
	static void _GoBackToMainMenue() {
		cout << setw(37) << left << "" << "\nPress Any key To Go Back To Main Menue...";
		system("pause>nul");
		ShowMainMenue();
	}
	static void _ShowAllClientsScreen() {
		//cout << "\nShow All Clients Screen Will Be Here...\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen() {
		//cout << "\nShow Add New Clients Screen Will Be Here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen() {
		//cout << "\nShow Delete Client Screen Will Be Here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientScreen() {
		//cout << "\nShow Update Client Screen Will Be Here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen() {
		//cout << "\nShow Find Client Screen Will Be Here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsMenue() {
		//cout << "\nShow Transactions Menue Screen Will Be Here...\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	static void _ShowManageUsersMenue() {
		//cout << "\nShow Manage Users Screen Will Be Here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();

	}
	static void _ShowLoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchangeMenue() {
		//cout << "\nShow Currency Exchange Menue Will Be Here...\n";
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
	}
	/*static void _ShowEndScreen() {
		cout << "\nShow End Screen Will Be Here...\n";

	}*/
	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}
	static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOption) {
		switch (MainMenueOption) {
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:

		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchangeMenue:
		{
			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			//_ShowEndScreen();
			_Logout();
			break;
		}
		}
	}
public:
	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";
		_PerformMainMenueOptions(enMainMenueOptions(_ReadMainMenueOption()));
	}

};