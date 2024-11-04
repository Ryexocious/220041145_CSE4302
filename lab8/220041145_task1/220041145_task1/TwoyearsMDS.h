#pragma once
#include"monthlydepositeScheme.h"
class TwoyearsMDS :public monthlydepositeScheme
{
private:
	float maximuminterest;
public:
	void setter(string a, float c, float d);
};

