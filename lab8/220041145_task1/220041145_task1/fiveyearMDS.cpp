#include "fiveyearMDS.h"
void fiveyearMDS::setter(string a, float c, float d) {
	monthlydepositeScheme::setter(a, c);
	maximuminterest = d;
}