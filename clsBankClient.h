#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "clsPerson.h";
#include"clsString.h";
#include"Global.h";
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool  _MarkForDelete = false;
	static clsBankClient _ConvertLineToClientObject(string Line, string Delim = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Delim);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}
	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile() {
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Delim = "#//#") {
		string ClientLine = "";
		ClientLine += Client.FirstName + Delim;
		ClientLine += Client.LastName + Delim;
		ClientLine += Client.Email + Delim;
		ClientLine += Client.Phone + Delim;
		ClientLine += Client.AccountNumber() + Delim;
		ClientLine += Client.PinCode + Delim;
		ClientLine += to_string(Client.AccountBalance);
		return ClientLine;
	}
	static void _SaveClientsDataToFile(vector <clsBankClient>vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string DataLine;
		if (MyFile.is_open()) {
			for (clsBankClient& Client : vClients) {
				if (!Client._MarkForDelete) {
					DataLine = _ConvertClientObjectToLine(Client);
					MyFile << DataLine << endl;
				}

			}
			MyFile.close();
		}
	}
	void _Update() {
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}
	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << endl << DataLine;
			MyFile.close();
		}
	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	string _PrepareTransferOperationRecord(clsBankClient DestinationClient, float TransferAmount, string Delim = "#//#") {
		string TransferOperationRecord = "";
		TransferOperationRecord += clsDate::GetSystemDateTimeString() + Delim;
		TransferOperationRecord += this->_AccountNumber + Delim;
		TransferOperationRecord += DestinationClient.AccountNumber() + Delim;
		TransferOperationRecord += to_string(TransferAmount) + Delim;
		TransferOperationRecord += to_string(this->AccountBalance) + Delim;
		TransferOperationRecord += to_string(DestinationClient.AccountBalance) + Delim;
		TransferOperationRecord += CurrentUser.Username;
		return TransferOperationRecord;
	}
	struct stTransferInfo;
	static stTransferInfo _ConvertTransferLogRecordToStructureInfo(string Line, string Delim = "#//#") {
		vector<string> vTransferLogsInfo;
		vTransferLogsInfo = clsString::Split(Line, Delim);
		stTransferInfo TransferInfo;
		TransferInfo.DateTime = vTransferLogsInfo[0];
		TransferInfo.SrcAccountNumber = vTransferLogsInfo[1];
		TransferInfo.DstAccountNumber = vTransferLogsInfo[2];
		TransferInfo.TransAmount = stof(vTransferLogsInfo[3]);
		TransferInfo.SrcAccountBalance = stof(vTransferLogsInfo[4]);
		TransferInfo.DstAccountBalance = stof(vTransferLogsInfo[5]);
		TransferInfo.Username = vTransferLogsInfo[6];
		return TransferInfo;
	}
public:
	struct stTransferInfo {
		string DateTime;
		string SrcAccountNumber;
		string DstAccountNumber;
		float TransAmount;
		float SrcAccountBalance;
		float DstAccountBalance;
		string Username;
	};
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	string AccountNumber() {
		return _AccountNumber;
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	bool IsEmpty() {
		return(_Mode == enMode::EmptyMode);
	}
	static clsBankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line, "#//#");
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line, "#//#");
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFailedAccountNumberExists = 2 };
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
			if (IsClientExist(_AccountNumber))
				return enSaveResults::svFailedAccountNumberExists;

			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}
			break;
		}
		}
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete() {
		bool Found = false;
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : _vClients) {
			if (Client.AccountNumber() == _AccountNumber) {
				Client._MarkForDelete = true;
				Found = true;
				break;
			}
		}
		if (!Found)
			return false;

		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector<clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances() {
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient& Client : vClients)
			TotalBalances += Client.AccountBalance;

		return TotalBalances;
	}
	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance)
			return false;
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient) {
		if (Amount > AccountBalance)
			return false;

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		return true;
	}
	void TransferLogToFile(clsBankClient DestinationClient, float TransferAmount) {
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		string DataLine;
		if (MyFile.is_open()) {
			DataLine = _PrepareTransferOperationRecord(DestinationClient, TransferAmount);
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}
	static vector <stTransferInfo> GetTransferLogs() {
		vector <stTransferInfo> vTransferLogsInfo;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				stTransferInfo TransferLog = _ConvertTransferLogRecordToStructureInfo(Line);
				vTransferLogsInfo.push_back(TransferLog);
			}
			MyFile.close();
		}
		return vTransferLogsInfo;
	}
};