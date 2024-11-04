#include "CurrentAccount.h"
string CurrentAccount::nextacc;
void CurrentAccount::nextaccountno(string s) {
	nextacc = s;
}
void CurrentAccount:: setter(string a, float c) {
	Account::Account(a, c);
	Account::set(nextacc, accountprefix);
}
void CurrentAccount::getter() {
	Account::print();
	cout << "servicecharge " << servicecharge << "\n";
	cout << "accountpref" << accountprefix << "\n";
	cout << "nextaccount" << nextacc << '\n';
}