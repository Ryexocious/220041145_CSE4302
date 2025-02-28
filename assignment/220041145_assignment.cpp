#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit; // in kg

public:
    Vehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit)
        : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit) {}

    virtual ~Vehicle() {} // Virtual destructor

    virtual void maintenance() const = 0; // Pure virtual function
};

// Gasoline
class GasolineVehicle : public virtual Vehicle {
protected:
    double fuelTankCapacity; // in liters
    string fuelType; // e.g., petrol, octane

public:
    GasolineVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, const string& fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}

    virtual void maintenance() const override {
        cout << "GasolineVehicle - maintenance" << endl;
    }
};

// Electric
class ElectricVehicle : public virtual Vehicle {
protected:
    double batteryCapacity; // in KWh
    int chargingTime; // in minutes

public:
    ElectricVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double batteryCapacity, int chargingTime)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}

    virtual void maintenance() const override {
        cout << "ElectricVehicle - maintenance" << endl;
    }
};

// Hybrid
class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                  double fuelTankCapacity, const string& fuelType, double batteryCapacity, int chargingTime,
                  double energyRegenerationEfficiency)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}

    virtual void maintenance() const override {
        cout << "HybridVehicle - maintenance" << endl;
    }
};

// Motorcycle
class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
               double fuelTankCapacity, const string& fuelType)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}

    virtual void maintenance() const override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

// Car
class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
        double fuelTankCapacity, const string& fuelType, int passengerCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          passengerCapacity(passengerCapacity) {}

    virtual void maintenance() const override {
        cout << "Car - maintenance" << endl;
    }
};

// Truck
class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
          double fuelTankCapacity, const string& fuelType, double cargoCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          cargoCapacity(cargoCapacity) {}

    virtual void maintenance() const override {
        cout << "Truck - maintenance" << endl;
    }
};

// Employee Base
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}
    virtual ~Employee() {} // Virtual destructor
    virtual void introduce() const = 0; // Pure virtual function
};

// Manager
class Manager : public Employee {
public:
    Manager(const string& name, int id) : Employee(name, id) {}

    virtual void introduce() const override {
        cout << "Manager: Mr. " << name << endl;
    }
};

// Driver
class Driver : public Employee {
public:
    Driver(const string& name, int id) : Employee(name, id) {}

    virtual void introduce() const override {
        cout << "Driver: " << name << endl;
    }
};

// Branch
class Branch {
private:
    vector<Vehicle*> vehicles;
    vector<Employee*> employees;

public:
    ~Branch() {
        for (Vehicle* v : vehicles) delete v;
        for (Employee* e : employees) delete e;
    }

    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void maintenance_all_vehicle() const {
        for (const Vehicle* v : vehicles) {
            v->maintenance();
        }
    }

    void introduceEmployees() const {
        for (const Employee* e : employees) {
            e->introduce();
        }
    }
};

int main() {
    Branch dhaka;

    // Add vehicles
    dhaka.addVehicle(new Motorcycle("MC123", "Yamaha", 150, 10, "Petrol"));
    dhaka.addVehicle(new Car("CAR456", "Toyota", 500, 50, "Petrol", 4));
    dhaka.addVehicle(new Truck("TR789", "Volvo", 2000, 150, "Diesel", 10000));
    dhaka.addVehicle(new HybridVehicle("HYB001", "Tesla", 1000, 40, "Petrol", 75, 120, 0.85));

    // Add employees
    dhaka.addEmployee(new Manager("Alice", 1));
    dhaka.addEmployee(new Driver("Bob", 2));

    // Maintenance and introductions
    cout << "Vehicle Maintenance:" << endl;
    dhaka.maintenance_all_vehicle();

    cout << "\nEmployee Introductions:" << endl;
    dhaka.introduceEmployees();
}
