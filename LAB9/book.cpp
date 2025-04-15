// Classes and Structure:
// • Class Book (Header: Book.h, Implementation: Book.cpp):
// o Data Members:
// ▪ title, author, ISBN (strings): Store book metadata.
// o Member Functions:
// ▪ Constructor to initialize book details.
// ▪ getTitle(), getAuthor(), getISBN(): Return book properties.
#include "book.h"

Book::Book(string t, string a, string i) {
    title = t;
    author = a;
    ISBN = i;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getISBN() {
    return ISBN;
}



