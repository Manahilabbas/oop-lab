#include <iostream>
#include <conio.h>  
#include <iomanip>  

using namespace std;

class tollBooth {
private:
    unsigned int carCount; 
    double cashCollected;   

public:
    tollBooth()  {
        carCount=0;
        cashCollected=0.0;
    }

    void payingCar() {
        carCount++;
        cashCollected += 0.50;  
        cout<<"added"<<endl;
    }
    void nopayCar() {
        carCount++;
         cout<<"added"<<endl;
    }
    void display() const {
        cout << "Total cars: " << carCount << endl;
        cout << "Total cash collected: $" << fixed << setprecision(2) << cashCollected << endl;
    }
};

int main() {
    tollBooth booth; 
    char c;

    cout << "Press 'P' for a paying car, 'N' for a non-paying car, and 'D' to exit and display totals." << endl;

    while (true) {
        c=_getch();
    
            
            if (c == 'D'||c=='d') {
                booth.display();
                break; 
            }
            if (c == 'P' || c == 'p') {
                booth.payingCar(); 
            }
            else if (c == 'N' || c == 'n') {
                booth.nopayCar(); 
        
    }}

    return 0;
}

