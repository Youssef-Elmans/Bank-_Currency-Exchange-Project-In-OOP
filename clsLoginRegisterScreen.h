#pragma once
#include<iostream>
#include"clsScreen.h";
#include<iomanip>
#include"clsUser.h";
class clsLoginRegisterScreen:protected  clsScreen
{
private:
	static void _PrintLoginReisterRecord(clsUser::stLoginRegisterInfo LoginRgisterInfo) {
		cout << setw(8) << left << "" << "| " << left << setw(27) << LoginRgisterInfo.DateTime;
		cout << "| " << left << setw(30) << LoginRgisterInfo.Username;
		cout << "| " << left << setw(20) << LoginRgisterInfo.Password;
		cout << "| " << left << setw(20) << LoginRgisterInfo.Permissions;
	}
public:
	static void ShowLoginRegisterScreen() {
		if (!CheckAccessesRights(clsUser::enPermissions::pLoginRegisters)) {
			return;
		}
		vector <clsUser::stLoginRegisterInfo> vLoginRegistersInfo = clsUser::GetLoginRegisters();
		string Title = "\t Login Register List Screen";
		string SubTitle = "\t  (" + to_string(vLoginRegistersInfo.size()) + ") Records(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "__________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(27) << "Date/Time";
		cout << "| " << left << setw(30) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t______________________________";
		cout << "_______________________________________________________________________\n\n";
		///*if (vLoginRegistersInfo.size() == 0)
		//	cout << "\t\t\t\tNo Login Registers Available!\n";*/
			

		//else {
			for (clsUser::stLoginRegisterInfo& LoginRgisterInfo : vLoginRegistersInfo) {
				_PrintLoginReisterRecord(LoginRgisterInfo);
				cout << endl;
			}
		//}
		cout << setw(8) << left << "" << "___________________________________________";
		cout << "__________________________________________________________\n";
	}
};