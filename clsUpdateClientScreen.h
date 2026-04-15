#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidation.h";
#include"clsUser.h";
using namespace std;
class clsUpdateClientScreen :protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidation::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidation::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidation::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidation::ReadString();

		cout << "\nEnter Pincode: ";
		Client.PinCode = clsInputValidation::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidation::ReadFloatNumber("");

	}
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
	static void ShowUpdateClientScreen() {
		if (!CheckAccessesRights(clsUser::enPermissions::pUpdateClients)) {
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Not Found, Choose another One: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
		_ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult = Client1.Save();
		switch (SaveResult) {
		case clsBankClient::enSaveResults::svSucceded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
			cout << "\nError Account Was Not Saved Because Its Empty";
			break;
		}
	}
};