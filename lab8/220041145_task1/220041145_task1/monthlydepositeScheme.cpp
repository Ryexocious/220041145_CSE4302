#include "monthlydepositeScheme.h"
string monthlydepositeScheme::nextaccount;
void monthlydepositeScheme :: nextaccountno(string s) {
	nextaccount = s;
}
void monthlydepositeScheme::setter(string a, float c) {
	Account::Account(a, c);
	Account::set(nextaccount, accountprefix);
}
void monthlydepositeScheme::getter() {
	Account::print();
	cout << "interestrate " << interestrate << "\n";
	cout << "depositeammount" << monthlyDepositeAmmount << '\n';
	cout << "accountpref" << accountprefix << "\n";
	cout << "nextaccount" << nextaccount << '\n';
}