/*Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.*/
#include <iostream>
using namespace std;

class ValidateString {
    string test;

public:
    // Parameterized constructor
    ValidateString(string s = "abc") : test(s) {}

    /**
     * This function is constant because it does not modify the object state.
     * If we do not make it const, calling it on a const object would cause a compilation error.
     */
    bool checkString() const {
        for (char c : test) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString S1("abc"), S2("12ab"), S3("1234-");

    cout << "S1 is " << (S1.checkString() ? "valid" : "invalid") << endl;
    cout << "S2 is " << (S2.checkString() ? "valid" : "invalid") << endl;
    cout << "S3 is " << (S3.checkString() ? "valid" : "invalid") << endl;

    return 0;
}
