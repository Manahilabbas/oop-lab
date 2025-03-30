#include <iostream>
using namespace std;

class Test {
    int secret;

public:
    Test(int s) : secret(s) {}

    // Friend function declaration
    friend void revealSecret(const Test& obj);
};

// Friend function trying to access private member
void revealSecret(const Test& obj) {
    cout << "The secret value is: " << obj.secret << endl; //  Works because obj is passed
}

int main() {
    Test t1(42);
    revealSecret(t1);

    return 0;
}
