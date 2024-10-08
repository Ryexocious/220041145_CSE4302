#ifndef CELCIUS_H
#define CELCIUS_H
class Fahrenheit;
class Kelvin;  
class celcius {
private:
    double temp;
public:
    celcius(double temp = -273.15);
    void assign(double t);         
    void display() const;        
    double toFahrenheit() const;     
    double toKelvin() const;        
    operator Fahrenheit() const;     
    operator Kelvin() const;         
};

#endif //CELCIUS_H

