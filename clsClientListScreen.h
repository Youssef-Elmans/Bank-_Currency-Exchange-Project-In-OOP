#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsUser.h";
using namespace std;
class clsClientListScreen : protected clsScreen
{
private :
	static void _PrintClientRecord(clsBankClient Client) {
		cout <<setw(8)<<left<<"" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:
	static void ShowClientsList() {
		if (!CheckAccessesRights(clsUser::enPermissions::pListClients)) {
			return;
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t Client List Screen";
		string SubTitle = "\t  ("+to_string(vClients.size())+") Client(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8)<<left<<"" << "\n\t___________________________________________";
		cout << "_____________________________________________________\n\n";
		cout << setw(8)<<left<<"" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8)<<left<<"" << "\n\t______________________________";
		cout << "__________________________________________________________________\n\n";
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In The System!\n";

		else {
			for (clsBankClient& Client : vClients) {
				_PrintClientRecord(Client);
				cout << endl;
			}
		}
		cout <<setw(8)<<left<<"" << "___________________________________________";
		cout << "_____________________________________________________\n";
	}
};