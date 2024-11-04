#include "LoanAccount.h"
string LoanAccount::nextaccount;
void LoanAccount ::nextaccountno(string s) {
	nextaccount = s;
}
void LoanAccount:: set(string a, float c) {
	Account::Account(a, c);
	Account::set(nextaccount, accountprefix);
}
void LoanAccount::getter() {
	Account::print();
	cout << "interestrate " << interestrate << "\n";
	cout << "depositeammount" << monthlyDepositeAmmount << '\n';
	cout << "accountpref" << accountprefix << "\n";
	cout << "nextaccount" << nextaccount << '\n';
}