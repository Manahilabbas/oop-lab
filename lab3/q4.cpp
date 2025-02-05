#include <iostream>
#include <iomanip>  // For setprecision and fixed
#include <cmath>    // For fmod
using namespace std;

class Angle {
private:
    int degrees;   
    float minutes; 
    char direction; 

public:
    // Constructors
    Angle(int deg, float min, char dir) {
        degrees = deg;
        minutes = min;
        direction = dir;
    }
    Angle() {
        degrees = 134;
        minutes = 12.9;
        direction = 'S';
    }
    void setAngle(int deg, float min, char dir) {
         degrees = deg;
        minutes = min;
        direction = dir;
    }
    void displayAngle() {
        cout << degrees << "\xF8" << fixed << setprecision(1) << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle location;  // Initial location

    cout << "Initial location: ";
    location.displayAngle();

    while (true) {
        char choice;
        cout << "\nDo you want to enter a new location? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;  
        }

        int deg;
        float min;
        char dir;
        cout << "Enter degrees, minutes, and direction (N, S, E, W): ";
        cin >> deg >> min >> dir;
        deg+=min/60;
        min=fmod(min,60);

        location.setAngle(deg, min, dir);

        cout << "You entered: ";
        location.displayAngle();
    }

    cout << "Program ended.\n";
    return 0;
}
