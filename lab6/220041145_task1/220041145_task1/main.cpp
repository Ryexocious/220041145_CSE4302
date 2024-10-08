#include"Counter.h"

int main() {
	Counter c1, c2, c3;
	c2.setincrementstep(2);
	c3.setincrementstep(2);
	c2.increment();
	c3.increment();
	c1 = c2 + c3;
	cout << c1.getcount() << "\n";
	c1 += c2;
	cout << c1.getcount() << "\n";
}