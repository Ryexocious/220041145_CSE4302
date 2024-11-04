#include "SavingsAccount.h"
string SavingsAccount::nextaccount;
void SavingsAccount :: nextaccountno(string s) {
	nextaccount = s;
}
void SavingsAccount::setter(string a, float c) {
	Account::Account(a, c);
	Account::set(nextaccount, accountprefix);
}
void SavingsAccount::getter() {
	Account::print();
	cout << "interestrate " << interestrate << "\n";
	cout << "depositeammount" << monthlyDepositeAmmount << '\n';
	cout << "accountpref" << accountprefix << "\n";
	cout << "nextaccount" << nextaccount << '\n';
}