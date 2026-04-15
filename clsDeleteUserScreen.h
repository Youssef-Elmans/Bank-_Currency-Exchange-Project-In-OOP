#pragma once
#include<iostream>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsInputValidation.h";
using namespace std;
class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User) {
		cout << "\nUser Card: \n";
		cout << "--------------------------------------------------\n";
		cout << "First Name          : " << User.FirstName << endl;
		cout << "Last Nam            : " << User.LastName << endl;
		cout << "Full Name           : " << User.FullName() << endl;
		cout << "Email               : " << User.Email << endl;
		cout << "Phone               : " << User.Phone << endl;
		cout << "Username            : " << User.Username << endl;
		cout << "Password            : " << User.Password << endl;
		cout << "Permissions         : " << User.Permissions << endl;
		cout << "--------------------------------------------------\n";
	}
public:
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User Screen");
		string Username = "";
		cout << "\nPlease Enter Username: ";
		Username = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername Is Not Found, Choose another One: ";
			Username = clsInputValidation::ReadString();
		}
		clsUser User1 = clsUser::Find(Username);
		_PrintUser(User1);
		cout << "\n\nAre You Sure You Want To Delete This User? Y/N ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			if (User1.Delete()) {
				cout << "\nUser Delected Successfully :-)\n";
				_PrintUser(User1);
			}
			else
				cout << "\nError User Was Not Deleted\n";
		}
	}
};