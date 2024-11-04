#pragma once
#include"Account.h"
class LoanAccount : public Account
{
private:
	float interestrate;
	float monthlyDepositeAmmount;
	const static int accountprefix = 900;
	static string nextaccount;
public:
	void nextaccountno(string s);
	void set(string a, float c);
	void getter();
};

