#pragma once
#include"monthlydepositeScheme.h"
class initialdepositeMDS :public monthlydepositeScheme
{
private:
	float maximuminterest;
	float initialdepositeammount;
public:
	void setter(string a, float c, float d, float e);
};

