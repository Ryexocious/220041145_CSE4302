#include "Fahrenheit.h"
#include "celcius.h"
#include "Kelvin.h"
#include <iostream>
using namespace std;

Fahrenheit::Fahrenheit(double temp) {
    if (temp < -459.67) {
        cout << "error below zero\n";
        this->temp = -459.67;
    }
    else {
        this->temp = temp;
    }
}
void Fahrenheit::assign(double t) {
    if (t < -459.67) {
        cout << "error below zero\n";
        this->temp = -459.67;
    }
    else {
        this->temp = t;
    }
}
void Fahrenheit::display() const {
    cout << "The temperature is " << temp << " Fahrenheit.\n";
}
double Fahrenheit::toCelsius() const {
    return (temp - 32) * 5 / 9;
}
double Fahrenheit::toKelvin() const {
    return (temp - 32) * 5 / 9 + 273.15;
}
Fahrenheit::operator celcius() const {
    return celcius(this->toCelsius());
}
Fahrenheit::operator Kelvin() const {
    return Kelvin(this->toKelvin());
}
