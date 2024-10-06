#ifndef employe_H
#define employe_H
#include <iostream>
#include <string>
#include<cstring>
using namespace std;
class employee
{
private:
	string name;
	string doy;
	int salary;
public:
	employee();
	
	void setname(const string& name);
	void setdate(const string& dob);
	void setsal(int sal);
	string getname() const;
	string getdoy()const;
	int getsal() const;
	void setinfo();
	void getinfo() const;
	static employee agecompare(employee& a, employee& b);

};
#endif //employe_H