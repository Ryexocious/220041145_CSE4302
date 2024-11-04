#include "Account.h"
Account::Account(string x, float y) : accountname(x),balance(y) {}
void Account::print() {
	cout << "accountNo: " << accountNo << "\n";
	cout << "accountname: " << accountname << '\n';
	cout << "balance:" << balance << "\n";
}
void Account:: set(string s,int y) {
	accountNo = s + to_string(y);
}


