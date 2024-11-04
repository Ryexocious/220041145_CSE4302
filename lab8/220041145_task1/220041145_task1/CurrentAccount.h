#pragma once
#include"Account.h"
class CurrentAccount : public Account
{
private:
	const static int servicecharge=100;
	const static int accountprefix = 100;
	static string nextacc;
public:
	void nextaccountno(string s);
	void setter(string a, float c);
	void getter();
};

