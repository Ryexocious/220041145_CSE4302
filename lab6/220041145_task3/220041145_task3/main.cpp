#include "celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>
using namespace std;

int main() {
    celcius x(25.0);
    x.display();
    Fahrenheit y = x;
    y.display();
    Kelvin z = x;
    z.display();
    y.assign(98.6);
    y.display();
    x = y;
    x.display();
    z = y;
    z.display();
    z.assign(300.0);
    z.display();
    x = z;
    x.display();
    y = z;
    y.display();

}
