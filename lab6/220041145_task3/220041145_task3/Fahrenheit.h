#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H
class celcius;
class Kelvin;
class Fahrenheit {
private:
    double temp;
public:
    Fahrenheit(double temp = -459.67);
    void assign(double t); 
    void display() const;
    double toCelsius() const;    
    double toKelvin() const;
    operator celcius() const;
    operator Kelvin() const;
};

#endif //FAHRENHEIT_H

