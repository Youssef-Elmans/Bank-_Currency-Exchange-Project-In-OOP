#pragma once
#include <iostream>
#include"Global.h";
#include"clsUser.h";
#include"clsDate.h";
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
			cout << "\n\t\t\t\t\t  " << SubTitle;


		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.Username << endl;
		cout << "\t\t\t\t\tDate:"<<clsDate::ConvertDateToString(clsDate())<<endl<<endl;
	}
	static bool CheckAccessesRights(clsUser::enPermissions Permission) {
		if (!CurrentUser.CheckAcessesPermission(Permission)) {
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
			return true;
	}
};