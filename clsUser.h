#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsPerson.h";
#include"clsString.h";
#include"clsDate.h";
using namespace std;
class clsUser :public clsPerson
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _Username;
	string _Password;
	short _Permissions;
	bool  _MarkedForDelete = false;
	static float _GetPasswordEncryptionKey() {
		float PasswordEncryptionKey = 5;
		return PasswordEncryptionKey;
	}
	static clsUser _ConvertLineToUserObject(string Line, string Delim = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Delim);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsString::Decrypt(vUserData[5], _GetPasswordEncryptionKey()), stoi(vUserData[6]));
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFile() {
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	static string _ConvertUserObjectToLine(clsUser User, string Delim = "#//#") {
		string UserLine = "";
		UserLine += User.FirstName + Delim;
		UserLine += User.LastName + Delim;
		UserLine += User.Email + Delim;
		UserLine += User.Phone + Delim;
		UserLine += User.Username + Delim;
		UserLine += clsString::Encrypt(User.Password, _GetPasswordEncryptionKey()) + Delim;
		UserLine += to_string(User.Permissions);
		return UserLine;
	}
	static void _SaveUsersDataToFile(vector <clsUser>vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		string DataLine;
		if (MyFile.is_open()) {
			for (clsUser& User : vUsers) {
				if (!User.MarkedForDelete()) {
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine << endl;
				}

			}
			MyFile.close();
		}
	}
	void _Update() {
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : _vUsers) {
			if (U.Username == Username) {
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}
	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << endl << DataLine;
			MyFile.close();
		}
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	string _PrepareLoginRecord(string Delim = "#//#") {
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Delim;
		LoginRecord += Username + Delim;
		LoginRecord += clsString::Encrypt(Password, _GetPasswordEncryptionKey()) + Delim;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}
	struct stLoginRegisterInfo;
	static stLoginRegisterInfo _ConvertLoginRegisterRecordToStructureInfo(string Line, string Delim = "#//#") {
		vector<string> vLoginRegisterData;
		vLoginRegisterData = clsString::Split(Line, Delim);
		stLoginRegisterInfo LoginRegisterData;
		LoginRegisterData.DateTime = vLoginRegisterData[0];
		LoginRegisterData.Username = vLoginRegisterData[1];
		LoginRegisterData.Password = clsString::Decrypt(vLoginRegisterData[2], _GetPasswordEncryptionKey());
		LoginRegisterData.Permissions = vLoginRegisterData[3];
		return LoginRegisterData;
	}
public:
	struct stLoginRegisterInfo {
		string DateTime;
		string Username;
		string Password;
		string Permissions;
	};
	enum enPermissions {
		pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8,
		pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegisters = 128,pCurrencyExchange=256
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username,
		string Password, short Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}
	string GetUsername() {
		return _Username;
	}
	void SetUsername(string Username) {
		_Username = Username;
	}
	__declspec(property(get = GetUsername, put = SetUsername)) string Username;
	string GetPassword() {
		return _Password;
	}
	void SetPassword(string Password) {
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	short GetPermissions() {
		return _Permissions;
	}
	void SetPermissions(short Permissions) {
		_Permissions = Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;
	bool MarkedForDelete() {
		return _MarkedForDelete;
	}
	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	}
	static clsUser Find(string Username) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line, "#//#");
				if (User.Username == Username) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string Username, string Password) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line, "#//#");
				if (User.Username == Username && User.Password == Password) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static bool IsUserExist(string Username) {
		clsUser User = clsUser::Find(Username);
		return (!User.IsEmpty());
	}
	enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFailedUserExists = 2 };
	enSaveResults Save() {
		switch (_Mode) {
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (IsUserExist(_Username))
				return enSaveResults::svFailedUserExists;

			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}
			break;
		}
		}
	}
	static clsUser GetAddNewUserObject(string Username) {
		return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	}
	bool Delete() {
		bool Found = false;
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& User : _vUsers) {
			if (User.Username == _Username) {
				User._MarkedForDelete = true;
				Found = true;
				break;
			}
		}
		if (!Found)
			return false;

		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	static vector<clsUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	}
	bool CheckAcessesPermission(enPermissions Permission) {
		if (this->Permissions == enPermissions::pAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;

		else
			return false;
	}
	void RegisterLogin() {
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		string DataLine;
		if (MyFile.is_open()) {
			DataLine = _PrepareLoginRecord();
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	static vector <stLoginRegisterInfo> GetLoginRegisters() {
		vector <stLoginRegisterInfo> vLoginRegisters;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				stLoginRegisterInfo LoginRegister = _ConvertLoginRegisterRecordToStructureInfo(Line);
				vLoginRegisters.push_back(LoginRegister);
			}
			MyFile.close();
		}
		return vLoginRegisters;
	}
};