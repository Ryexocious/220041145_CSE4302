#ifndef counter_H
#define counter_H

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Counter
{
private:
	int count;
	int increamentstep;

	void add(int n) {
		count += n;
	}
public:
	Counter() : count(0), increamentstep(1) {}
	Counter(int n) : count(0),increamentstep(n>0?n:1){}
	void setincrementstep(int x);
	int getcount()const;
	void increment();
	void reset(int x);
	Counter operator+(const Counter& x)const;
	Counter operator+=(const Counter& x);
	Counter operator++(int);
	Counter operator++();
	bool operator>(const Counter& x) const;
	bool operator<(const Counter& x) const;
	bool operator>=(const Counter& x) const;
	bool operator<=(const Counter& x) const;
	bool operator==(const Counter& x) const;
	bool operator!=(const Counter& x) const;
};
#endif // counter_H
