#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make, model;
    int year;
public:
    Vehicle(string mk, string mo, int y)
        : make(mk), model(mo), year(y) {}
    void display() {
        cout << "Make: "  << make  << endl;
        cout << "Model: " << model << endl;
        cout << "Year: "  << year  << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;
    double fuelEfficiency; 
public:
    Car(string mk, string mo, int y, int d, double fe)
        : Vehicle(mk, mo, y), doors(d), fuelEfficiency(fe) {}
    void display() {
        Vehicle::display();
        cout << "Doors: "           << doors          << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " km/l" << endl;
    }
};

class ElectricCar : public Car {
    double batteryLife; 
public:
    ElectricCar(string mk, string mo, int y, int d, double fe, double bl)
        : Car(mk, mo, y, d, fe), batteryLife(bl) {}
    void display() {
        Car::display();
        cout << "Battery Life: " << batteryLife << " km per charge" << endl;
    }
};

int main() {
    ElectricCar ec("Tesla", "Model 3", 2024, 4, 0, 580.0);
    cout << "Electric Car Details" << endl;
    ec.display();
    return 0;
}
