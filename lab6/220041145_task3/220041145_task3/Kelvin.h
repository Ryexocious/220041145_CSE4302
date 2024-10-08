#ifndef KELVIN_H
#define KELVIN_H
class celcius;
class Fahrenheit; 
class Kelvin {
private:
    double temp;
public:
    Kelvin(double temp = 0.0);
    void assign(double t);
    void display() const;
    double toCelsius() const;
    double toFahrenheit() const;
    operator celcius() const;
    operator Fahrenheit() const;
};
#endif //KELVIN_H


