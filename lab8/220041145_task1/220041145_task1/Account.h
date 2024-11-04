#pragma once
#include<iostream>
#include<string>
using namespace std;
class Account
{
private:
	string accountNo;
	string accountname;
	float balance;
public:
	Account(string x, float y);
	void print();
	void set(string pref, int next);
};

