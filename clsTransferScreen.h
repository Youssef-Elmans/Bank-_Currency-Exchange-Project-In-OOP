#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
using namespace std;
class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card: \n";
		cout << "--------------------------------------------------\n";
		cout << "Full Name        : " << Client.FullName() << endl;
		cout << "Acc. Number      : " << Client.AccountNumber() << endl;
		cout << "Balance          : " << Client.AccountBalance << endl;
		cout << "--------------------------------------------------\n";
	}
	static string _ReadAccountNumber(string Message) {
		string AccountNumber = "";
		cout << endl << Message;
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\n Client With Acount Number [" << AccountNumber << "] Does Not Exist,Choose Another One.\n";
			cout << endl << Message;
			AccountNumber = clsInputValidation::ReadString();
		}

		return AccountNumber;
	}
	static float _ReadAmount(clsBankClient SourceClient) {
		double Amount = 0;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputValidation::ReadDoubleNumberBetween(0, SourceClient.AccountBalance, "Amount Exceeds The Available Balance, Enter Another Amount? ");
		return Amount;
	}
public:
	static void ShowTransferScreen() {
		_DrawScreenHeader("\t  Transfer Screen");


		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer From: "));
		_PrintClient(SourceClient);


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer To: "));
		_PrintClient(DestinationClient);


		float Amount = _ReadAmount(SourceClient);

		cout << "\nAre You Sure You Want To Perform This Operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			if (SourceClient.Transfer(Amount, DestinationClient)) {
				cout << "\nTransfer Done Successfully.\n";

				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);
				SourceClient.TransferLogToFile(DestinationClient,Amount);

			}
			else {
				cout << "\nTransfer Failed \n";
			}
		}
		else
			cout << "\nOperation Was Cancelled.\n";
	}

};