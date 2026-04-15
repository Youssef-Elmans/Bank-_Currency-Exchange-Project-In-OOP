#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidation.h";
#include"clsListUsersScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsUpdateUserScreen.h";
#include"clsFindUserScreen.h";
#include"clsUser.h";
using namespace std;
class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };

	static short _ReadManageUsersOption() {
		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 To 6]? ";
		short Choice = clsInputValidation::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6? ");
		return Choice;
	}
	static void _GoBackManageUsersMenue() {
		cout << setw(37) << left << "" << "\nPress Any key To Go Back To Manage Users Menue...";
		system("pause>nul");
		ShowManageUsersMenue();
	}
	static void _ShowListUsersScreen() {
		//cout << "\nShow All Users Screen Will Be Here...\n";
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen() {
		//cout << "\nShow Add New Users Screen Will Be Here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen() {
		//cout << "\nShow Delete User Screen Will Be Here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		//cout << "\nShow Update User Screen Will Be Here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		//cout << "\nShow Find User Screen Will Be Here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _PerformManageUsersMenueOptions(enManageUsersOptions ManageUsersMenueOption) {
		switch (ManageUsersMenueOption) {
		case enManageUsersOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackManageUsersMenue();
			break;
		}

		case enManageUsersOptions::eMainMenue:
		{



		}

		}
	}
public:
	static void ShowManageUsersMenue() {
		if (!CheckAccessesRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";
		_PerformManageUsersMenueOptions(enManageUsersOptions(_ReadManageUsersOption()));
	}

};