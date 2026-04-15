#pragma once
#include<iostream>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsInputValidation.h";
using namespace std;

class clsFindUserScreen :protected clsScreen
{
private:
	static void _PrintUser(clsUser User) {
		cout << "\nUser Card: \n";
		cout << "--------------------------------------------------\n";
		cout << "First Name          : " << User.FirstName << endl;
		cout << "Last Name            : " << User.LastName << endl;
		cout << "Full Name           : " << User.FullName() << endl;
		cout << "Email               : " << User.Email << endl;
		cout << "Phone               : " << User.Phone << endl;
		cout << "Username            : " << User.Username << endl;
		cout << "Password            : " << User.Password << endl;
		cout << "Permissions         : " << User.Permissions << endl;
		cout << "--------------------------------------------------\n";
	}

public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\tFind User Screen");
		string Username = "";
		cout << "\nPlease Enter Username: ";
		Username = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername Is Not Found, Choose another One: ";
			Username = clsInputValidation::ReadString();
		}
		clsUser User1 = clsUser::Find(Username);
		if (!User1.IsEmpty())
			cout << "\nUser Was Found :-)\n";

		else
			cout << "\nUser Was Not Found :-)\n";

		_PrintUser(User1);
	}
};