#include "initialdepositeMDS.h"
void initialdepositeMDS::setter(string a, float c, float d,float e) {
	monthlydepositeScheme::setter(a, c);
	maximuminterest = d;
	initialdepositeammount = e;
}