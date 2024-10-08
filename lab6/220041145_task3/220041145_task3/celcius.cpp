#include "celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>
using namespace std;

celcius::celcius(double temp) {
    if (temp < -273.15) {
        cout << "error below zero\n";
        this->temp = -273.15;
    }
    else {
        this->temp = temp;
    }
}
void celcius::assign(double t) {
    if (t < -273.15) {
        cout << "error below zero\n";
        this->temp = -273.15;
    }
    else {
        this->temp = t;
    }
}
void celcius::display() const {
    cout << "The temperature is " << temp << " Celsius.\n";
}
double celcius::toFahrenheit() const {
    return temp * 9 / 5 + 32;
}
double celcius::toKelvin() const {
    return temp + 273.15;
}
celcius::operator Fahrenheit() const {
    return Fahrenheit(this->toFahrenheit());
}
celcius::operator Kelvin() const {
    return Kelvin(this->toKelvin());
}
