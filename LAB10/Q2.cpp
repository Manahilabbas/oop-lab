#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Resume {
    string name;
    string email;
    int yearsOfExperience;
    string summary;
};

void writeResume(const Resume& r) {
    ofstream outFile("resume.txt", ios::out | ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    outFile << "Name: " << r.name << endl;
    outFile << "Email: " << r.email << endl;
    outFile << "Years of Experience: " << r.yearsOfExperience << endl;
    outFile << "Summary: " << r.summary << endl;

    outFile.close();
    cout << "\nResume saved successfully.\n";
}

void displayResume() {
    ifstream inFile("resume.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    cout << "\n--- Resume Contents ---\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

int main() {
    Resume r;

    cout << "Enter your resume details:\n";
    cout << "Name: ";
    getline(cin, r.name);
    cout << "Email: ";
    getline(cin, r.email);
    cout << "Years of Experience: ";
    cin >> r.yearsOfExperience;
    cin.ignore();
    cout << "Summary: ";
    getline(cin, r.summary);

    writeResume(r);
    displayResume();

    return 0;
}
