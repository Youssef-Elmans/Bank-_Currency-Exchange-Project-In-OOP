#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidation.h";
using namespace std;
class clsUpdateUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidation::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidation::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidation::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidation::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidation::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();

	}
	static bool _ShouldGivePermission(char Permission) {
		return toupper(Permission) == 'Y';
	}
	static short _ReadPermissionsToSet() {
		short Permissions = 0;

		if (_ShouldGivePermission(clsInputValidation::ReadChar("Do You Want To Give Full Access? Y/N? "))) {
			return -1;
		}
		cout << "Do You Want To Give Access To:\n\n";
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Show Client List? Y/N? "))) ? clsUser::enPermissions::pListClients : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Add New Client? Y/N? "))) ? clsUser::enPermissions::pAddNewClient : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Delete Client? Y/N? "))) ? clsUser::enPermissions::pDeleteClient : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Update Client? Y/N? "))) ? clsUser::enPermissions::pUpdateClients : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Find Client? Y/N? "))) ? clsUser::enPermissions::pFindClient : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Transactions? Y/N? "))) ? clsUser::enPermissions::pTransactions : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Manage Users? Y/N? "))) ? clsUser::enPermissions::pManageUsers : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Login Registers? Y/N? "))) ? clsUser::enPermissions::pLoginRegisters : 0);
		Permissions |= static_cast<short> ((_ShouldGivePermission(clsInputValidation::ReadChar("Currency Exchange? Y/N? "))) ? clsUser::enPermissions::pCurrencyExchange : 0);
		return Permissions;
	}
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
	static void ShowUpdateUserScreen() {
		_DrawScreenHeader("\t Update User Screen");
		string Username = "";
		cout << "\nPlease Enter Username: ";
		Username = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername Is Not Found, Choose another One: ";
			Username = clsInputValidation::ReadString();
		}
		clsUser User1 = clsUser::Find(Username);
		_PrintUser(User1);
		cout << "\n\nUpdate User Info:";
		cout << "\n____________________\n";
		_ReadUserInfo(User1);
		clsUser::enSaveResults SaveResult = User1.Save();
		switch (SaveResult) {
		case clsUser::enSaveResults::svSucceded:
		{
			cout << "\nUser Updated Successfully :-)\n";
			_PrintUser(User1);
			break;
		}
		case clsUser::enSaveResults::svFailedEmptyObject:
			cout << "\nError User Was Not Saved Because Its Empty";
			break;
		}
	}
};