#include "TwoyearsMDS.h"
void TwoyearsMDS:: setter(string a, float c, float d) {
	monthlydepositeScheme::setter(a, c);
	maximuminterest = d;
}