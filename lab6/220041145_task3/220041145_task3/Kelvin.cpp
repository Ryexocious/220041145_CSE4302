#include "Kelvin.h"
#include "celcius.h"
#include "Fahrenheit.h"
#include <iostream>
using namespace std;

Kelvin::Kelvin(double temp) {
    if (temp < 0) {
        cout << "error below zero\n";
        this->temp = 0;
    }
    else {
        this->temp = temp;
    }
}
void Kelvin::assign(double t) {
    if (t < 0) {
        cout << "error below zero\n";
        this->temp = 0;
    }
    else {
        this->temp = t;
    }
}
void Kelvin::display() const {
    cout << "The temperature is " << temp << " Kelvin.\n";
}
double Kelvin::toCelsius() const {
    return temp - 273.15;
}
double Kelvin::toFahrenheit() const {
    return (temp - 273.15) * 9 / 5 + 32;
}
Kelvin::operator celcius() const {
    return celcius(this->toCelsius());
}
Kelvin::operator Fahrenheit() const {
    return Fahrenheit(this->toFahrenheit());
}
