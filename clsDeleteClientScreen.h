#pragma once
#include<iostream>
#include"clsBankClient.h";
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsUser.h";
using namespace std;
class clsDeleteClientScreen : protected clsScreen
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
public:
	static void ShowDeleteClientScreen() {
		if (!CheckAccessesRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Not Found, Choose another One: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\n\nAre You Sure You Want To Delete This Client? Y/N ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			if (Client1.Delete()) {
				cout << "\nClient Delected Successfully :-)\n";
				_PrintClient(Client1);
			}
			else
				cout << "\nError Client Was Not Deleted\n";
		}
	}
};