#include <iostream>
using namespace std;

class Engine {
    string type;
public:
    Engine(string type = "V6") : type(type) {}
    void showEngine() const { cout << "Engine Type: " << type << endl; }
};

class Wheel {
    int size;
public:
    Wheel(int size = 16) : size(size) {}
    void showWheel() const { cout << "Wheel Size: " << size << " inches" << endl; }
};

class Headlight {
    string type;
public:
    Headlight(string type = "LED") : type(type) {}
    void showHeadlight() const { cout << "Headlight Type: " << type << endl; }
};

class Steering {
    string type;
public:
    Steering(string type = "Power") : type(type) {}
    void showSteering() const { cout << "Steering Type: " << type << endl; }
};

class Car {
    Engine* engine;
    Wheel wheels[4]; 
    Headlight headlights[2]; 
    Steering steering; 
    
public:
    Car(Engine* eng, int wheelSize = 16, string headlightType = "LED", string steeringType = "Power") 
        : engine(eng), steering(steeringType) {
        for (int i = 0; i < 4; i++) wheels[i] = Wheel(wheelSize);
        for (int i = 0; i < 2; i++) headlights[i] = Headlight(headlightType);
    }
    void showCarDetails() const {
        cout << "\nCar Details:\n";
        engine->showEngine();
        for (int i = 0; i < 4; i++) wheels[i].showWheel();
        for (int i = 0; i < 2; i++) headlights[i].showHeadlight();
        steering.showSteering();
    }

    ~Car() { delete engine; }
};

int main() {
    Engine* myEngine = new Engine("V8"); 
    Car myCar(myEngine, 18, "Halogen", "Manual");

    myCar.showCarDetails();

    return 0;
}
