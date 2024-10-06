#include "employee.h"
#include<sstream>
#include<cstring>
employee::employee() : name("john doe"), doy("01-01-2002"),salary(10000){}

void employee::setname(const string& s) {
	if (s.length()>2) {
		name = s;
	}
	else {
		name = "john doe";
	}
}
void employee::setdate(const string& s){
	istringstream iss(s);
	int d, m, y;
	char chk;
	if (iss >> d >> chk>>m>>chk >> y){
		int current = 2024;
		if (current- y > 18) {
			doy = s;
		}
		else {
			doy="01-01-2002";
		}
	}
	
}
void employee::setsal(int s) {
	if (s >= 10000 && s <= 100000) {
		salary = s;
	}
	else {
		salary = 10000;
	}
}
string employee::getname()const{
	return name;

}
string employee::getdoy()const{
	return doy;

}
int employee::getsal()const {
	return salary;
}
void employee::setinfo() {
	string s,s2;
	int n;
	cin>>s>>s2>>n;
	setname(s);
	setdate(s2);
	setsal(n);
}
void employee::getinfo() const {
	cout << "Name: " << getname() << "\n";
	cout << "Date of Birth: " << getdoy() << "\n";
	cout << "Salary: " << getsal() << "\n";
}
employee employee::agecompare(employee& a, employee& b) {
	string a1 = a.getdoy();
	string a2 = b.getdoy();
	int d1, m1, y1, d2, m2, y2;
	sscanf_s(a1.c_str(), "%d-%d-%d", &d1, &m1, &y1);
	sscanf_s(a2.c_str(), "%d-%d-%d", &d2, &m2, &y2);
	if (y1>y2){
		return b;
	}
	else {
		return a;
	}
}

