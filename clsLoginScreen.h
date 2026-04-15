#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsMainScreen.h";
#include"clsUser.h";
#include"Global.h";
#include"clsInputValidation.h";
#include"clsDate.h";
using namespace std;

class clsLoginScreen :clsScreen
{
private:
	static bool _Login() {
		bool LoginFailed = false;
		string Username;
		string Password;
		short FailedLoginCounter = 0;
		

		do {
			if (LoginFailed) {
				FailedLoginCounter++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You Have " << 3-FailedLoginCounter << " Trial(s) To Login.\n\n";

				if (FailedLoginCounter == 3) {
					cout << "\nYou Are Locked After 3 Failed Trials\n";
					return false;
				}

			}

			cout << "Enter Username ? ";
			Username = clsInputValidation::ReadString();
			cout << "Enter Password ? ";
			Password = clsInputValidation::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};