#pragma once
#include <iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
using namespace std;
class clsTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTransferLogRecord(clsBankClient::stTransferInfo TransferLogInfo) {
		cout << setw(8) << left << "" << "| " << left << setw(20) << TransferLogInfo.DateTime;
		cout << "| " << left << setw(12) << TransferLogInfo.SrcAccountNumber;
		cout << "| " << left << setw(12) << TransferLogInfo.DstAccountNumber;
		cout << "| " << left << setw(12) << TransferLogInfo.TransAmount;
		cout << "| " << left << setw(12) << TransferLogInfo.SrcAccountBalance;
		cout << "| " << left << setw(12) << TransferLogInfo.DstAccountBalance;
		cout << "| " << left << setw(12) << TransferLogInfo.Username;
	}
public:
	static void ShowTransfersLogScreen() {
		vector <clsBankClient::stTransferInfo> vTransferLogsInfo = clsBankClient::GetTransferLogs();
		string Title = "\t Transfer Log List Screen";
		string SubTitle = "\t  (" + to_string(vTransferLogsInfo.size()) + ") Records(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "__________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t______________________________";
		cout << "_______________________________________________________________________\n\n";
		if (vTransferLogsInfo.size() == 0)
			cout << "\t\t\t\tNo Transfer Logs Available!\n";


		else {
			for (clsBankClient::stTransferInfo& TransferLogInfo : vTransferLogsInfo) {
				_PrintTransferLogRecord(TransferLogInfo);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "___________________________________________";
		cout << "__________________________________________________________\n";
	}
};