#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTotalBalancesScreen.h";
#include"clsUser.h";
#include"clsTransferScreen.h";
#include"clsTransferLogScreen.h";
using namespace std;
class clsTransactionsScreen :protected clsScreen

{
private:
	enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4,eTransferLog=5, eGoMaineMenue = 6
	};
	static short _ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 To 6]? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6? ");
		return Choice;
	}
	static void _ShowDepositScreen() {
		//cout << "\n Deposit Screen Will Be Here.\n";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		//cout << "\nWithdraw Screen Will Be Here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		//cout << "\nTotal Balances Will Be Here\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	static void _ShowTransferScreen() {
		//cout << "\nTransfer Screen Will Be Here.";
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen() {
		//cout << "\nTransfer Log Screen Will Be Here.";
		clsTransferLogScreen::ShowTransfersLogScreen();
	}
	static void _GoBackToTransctionsMenue() {
		cout << "\n\nPress Any key To Go Back To Transactions Menue...";
		system("pause>nul");
		ShowTransactionsMenue();
	}
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOptions) {
		switch (TransactionsMenueOptions) {
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransctionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransctionsMenue();
			break;
		}

		case enTransactionsMenueOptions::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransctionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransctionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransctionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eGoMaineMenue:
		{

		}

		}
	}
public:
	static void ShowTransactionsMenue() {
		if (!CheckAccessesRights(clsUser::enPermissions::pTransactions)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue Screen\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}
};