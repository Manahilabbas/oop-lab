#include <iostream>
using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(string model = " ", double rate = 0.0) : model(model), rate(rate) {}
    
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "--- Car Details ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Daily Rate: $" << rate << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() override {
        return rate;
    }

    void displayDetails() override {
        cout << "--- Bike Details ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Daily Rate: $" << rate << endl;
    }
};

int main() {
    Car carObj("Toyota Corolla", 50.0);
    Bike bikeObj("Yamaha", 20.0);
    Vehicle* ptr;

    ptr = &carObj;
    ptr->displayDetails();
    cout << "Rate: $" << ptr->getDailyRate() << "\n\n";

    ptr = &bikeObj;
    ptr->displayDetails();
    cout << "Rate: $" << ptr->getDailyRate() << endl;

    return 0;
}
