#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidation.h";
#include"clsUser.h";
using namespace std;

class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddNewClientScreen() {
		if (!CheckAccessesRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number Is Already Used, Choose another One: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult = NewClient.Save();
		switch (SaveResult) {
		case clsBankClient::enSaveResults::svSucceded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError Account Was Not Saved Because Its Empty";
			break;
		}
		case clsBankClient::enSaveResults::svFailedAccountNumberExists:
		{
			cout << "\nError Account Was Not Saved Because Account Number Is Used!\n";
			break;
		}
		}
	}
};