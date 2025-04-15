

// • Class Library (Optional for advanced students):
// o Data Members:
// ▪ A collection (e.g., array/list) of Book objects.
// o Member Functions:
// ▪ addBook(), removeBook(), searchBook(): Manage the collection.

// Flow:
// • Define Book in header and source files to separate interface and implementation.
// • In main(), create a Book object and display its metadata.
#include <iostream>
#include "book.h"
using namespace std;

int main() {
    Book obj("1984", "George Orwell", "1234567890");
    
    cout << "Book title: " << obj.getTitle() << endl;
    cout << "Book author: " << obj.getAuthor() << endl;
    cout << "Book ISBN: " << obj.getISBN() << endl;

    return 0;
}
