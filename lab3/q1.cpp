#include <iostream>
#include <iomanip>
using namespace std;

class time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Setters
    void setHours(int h) {
        hours = h;
    }

    void setMinutes(int m) {
        minutes = m;
    }

    void setSeconds(int s) {
        seconds = s;
    }

    // Getters
    int getHours() {
        return hours;
    }

    int getMinutes() {
        return minutes;
    }

    int getSeconds() {
        return seconds;
    }

    // Constructors
    time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Member function to display time
    void display() {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds;
    }

    // Member function to add two time objects
    void addtime(time t1, time t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + (seconds / 60); // Carry over to minutes
        hours = t1.hours + t2.hours + (minutes / 60); // Carry over to hours

        seconds %= 60;  // Keep seconds within 0-59
        minutes %= 60;  // Keep minutes within 0-59
    }
};

int main() {
    int h1, m1, s1, h2, m2, s2;
    
    // Input values for time 1
    cout << "Enter time 1 (hours minutes seconds): ";
    cin >> h1 >> m1 >> s1;

    // Input values for time 2
    cout << "Enter time 2 (hours minutes seconds): ";
    cin >> h2 >> m2 >> s2;

    // Create time objects
    time t1(h1, m1, s1);
    time t2(h2, m2, s2);
    time t3;

    // Add times
    t3.addtime(t1, t2);

    // Display result
    cout << "The total time is: ";
    t3.display();
    cout << endl;

    return 0;
}
