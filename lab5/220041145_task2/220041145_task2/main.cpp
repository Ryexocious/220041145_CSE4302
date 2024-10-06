#include"employee.h"
using namespace std;
int main() {
	employee a, b;
	a.setinfo();
	b.setinfo();
	a.getinfo();
	b.getinfo();
	employee c = employee::agecompare(a, b);
	c.getinfo();
}
