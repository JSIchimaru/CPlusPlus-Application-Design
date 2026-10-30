#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <string>
using namespace std;

const int MAX_BOOKS = 10;

class Book {
private:
    string title;
    string author;
    int bookID;
    int publicationYear;

public:
    // Constructor
    Book(string bookTitle, string bookAuthor, int id, int year);

    // Member functions
    void displayBook();
    void setPublicationYear(int newYear);

    // Getter
    string getTitle();
};

// Base User class
class User {
protected:
    string username;

public:
    User(string name);
    string getUsername();
};

// Admin user
class Admin : public User {
public:
    Admin(string name);

    void addRecord();
    void deleteRecord();
};

// Regular user
class RegularUser : public User {
public:
    RegularUser(string name);

    void viewRecords();
    void searchRecords();
};

// Function declarations
void showMessage();

void addBook(
    int ids[],
    string titles[],
    string authors[],
    int years[],
    int& bookCount
);

void viewBooks(
    int ids[],
    string titles[],
    string authors[],
    int years[],
    int bookCount
);

void searchBooks(
    int ids[],
    string titles[],
    string authors[],
    int years[],
    int bookCount
);

void removeBook(
    int ids[],
    string titles[],
    string authors[],
    int years[],
    int& bookCount
);

void calculateAverageYear(
    int years[],
    int bookCount
);

// Binary search function
int binarySearch(
    int ids[],
    int size,
    int target
);

#endif#pragma once
