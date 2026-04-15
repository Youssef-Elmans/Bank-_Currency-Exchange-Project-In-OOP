#pragma once
#include<iostream>
#include"clsInputValidation.h";
#include"clsScreen.h";
#include"clsBankClient.h";
using namespace std;

class clsDepositScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card: \n";
		cout << "--------------------------------------------------\n";
		cout << "First Name          : " << Client.FirstName << endl;
		cout << "Last Nam            : " << Client.LastName << endl;
		cout << "Full Name           : " << Client.FullName() << endl;
		cout << "Email               : " << Client.Email << endl;
		cout << "Phone               : " << Client.Phone << endl;
		cout << "Account Number      : " << Client.AccountNumber() << endl;
		cout << "Password            : " << Client.PinCode << endl;
		cout << "Balance             : " << Client.AccountBalance << endl;
		cout << "--------------------------------------------------\n";
	}
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidation::ReadString();
		return AccountNumber;
	}

public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t   Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\n Client With Acount Number [" << AccountNumber << "] Does Not Exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		double Amount = 0;
		cout << "\nPlease Enter Deposit Ammount ? ";
		Amount = clsInputValidation::ReadDoubleNumber("");

		cout << "\nAre You Sure You Want To Perform This Transaction? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client1.AccountBalance;
		}
		else
			cout << "\nOperation Was Cancelled.\n";
	}
};