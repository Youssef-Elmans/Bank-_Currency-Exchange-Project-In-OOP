#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsUser.h";
#include<iomanip>
using namespace std;
class clsListUsersScreen :protected clsScreen
{
private:
	static void _PrintUserRecord(clsUser User) {
		cout << setw(8) << left << "" << "| " << left << setw(12) << User.Username;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}
public:
	static void ShowUsersListScreen() {
		vector <clsUser> vUsers = clsUser::GetUsersList();
		string Title = "\t Users List Screen";
		string SubTitle = "\t  (" + to_string(vUsers.size()) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "__________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t______________________________";
		cout << "_______________________________________________________________________\n\n";
		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Clients Available In The System!\n";

		else {
			for (clsUser& User : vUsers) {
				_PrintUserRecord(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "___________________________________________";
		cout << "__________________________________________________________\n";
	}
};