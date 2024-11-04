#pragma once
#include"Account.h"
class SavingsAccount : public Account
{
private:
	float interestrate;
	float monthlyDepositeAmmount;
	const static int accountprefix = 200;
	static string nextaccount;
public:
	void nextaccountno(string s);
	void setter(string a, float c);
	void getter();
};

