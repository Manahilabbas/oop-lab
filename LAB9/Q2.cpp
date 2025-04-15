#include <iostream>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness; 

public:
    LightBulb() : isOn(false), brightness(100) {}

    void turnOn() override {
        isOn = true;
        cout << "LightBulb is turned ON.\n";
    }

    void turnOff() override {
        isOn = false;
        cout << "LightBulb is turned OFF.\n";
    }

    void getStatus() override {
        cout << "--- LightBulb Status ---\n";
        cout << "State: " << (isOn ? "ON" : "OFF") << endl;
        cout << "Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(22.0) {} 

    void turnOn() override {
        isOn = true;
        cout << "Thermostat is turned ON.\n";
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat is turned OFF.\n";
    }

    void getStatus() override {
        cout << "--- Thermostat Status ---\n";
        cout << "State: " << (isOn ? "ON" : "OFF") << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
    }
};

int main() {
    LightBulb light;
    Thermostat thermostat;
    SmartDevice* device;

    device = &light;
    device->turnOn();
    device->getStatus();
    device->turnOff();
    device->getStatus();

  

    device = &thermostat;
    device->turnOn();
    device->getStatus();
    device->turnOff();
    device->getStatus();

    return 0;
}
