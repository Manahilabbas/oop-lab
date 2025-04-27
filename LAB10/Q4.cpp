// Q4. You are testing how file pointers work in a file while reading and writing.
// Requirements:
// 1. Write the sentence "C++ is a powerful programming language." to a file named
// info.txt using ofstream in ios::out mode.
// 2. Reopen the file using fstream with both ios::in | ios::out modes.
// 3. Display the initial position of get pointer using tellg() and put pointer using tellp().
// 4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
// from there.
// 5. Use seekp(6) to move the write pointer to the same position, and overwrite
// "powerful" with "dynamic" (same length).
// 6. Use tellg() and tellp() again to show the new pointer positions.
// 7. Display the updated content of the file.
#include <iostream>
#include <fstream>  
using namespace std;    
int main(){
    fstream file("info.txt", ios::out | ios::in | ios::trunc); 
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    file << "C++ is a powerful programming language.";
    file.close(); 
    file.open("info.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file for reading and writing." << endl;
        return 1;
    }
    cout << "Initial get pointer position: " << file.tellg() << endl;
    cout << "Initial put pointer position: " << file.tellp() << endl;
    file.seekg(8);
    string word;
    file>>word;
    cout << "Word at position 6: " << word << endl;
 
    file.seekp(9);
    file << "dynamic";
    cout << "new get pointer position: " << file.tellg() << endl;
    cout << "new put pointer position: " << file.tellp() << endl;
    file.seekg(0); 
    getline(file,word);
    cout << "Updated content of the file: " <<endl<< word << endl;


    return 0;
}