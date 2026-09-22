// FirstApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Function to add a book
void addBook() {
    cout << "Add Book selected." << endl;
}

// Function to view books
void viewBooks() {
    cout << "View Books selected." << endl;
}

// Function to search for a book
void searchBooks() {
    cout << "Search Books selected." << endl;
}

// Function to remove a book
void removeBook() {
    cout << "Remove Book selected." << endl;
}

// Function to display books from the dataset
void displayDataset() {
    // Book dataset
    string bookTitles[5] = {
        "Harry Potter Collection (Harry Potter #1-6)",
        "The Lord of the Rings (The Lord of the Rings #1-3)",
        "Atlas Shrugged",
        "War and Peace",
        "The Odyssey"
    };

    string authors[5] = {
        "J.K. Rowling",
        "J.R.R. Tolkien",
        "Ayn Rand",
        "Leo Tolstoy",
        "Homer"
    };

    int publicationYears[5] = {
        2005,
        2004,
        1999,
        1998,
        1998
    };

    int* yearPtr = &publicationYears[0];

    cout << "\n=== BOOK DATASET ===" << endl;

    // DIsplay all records
    for (int i = 0; i < 5; i++) {
        cout << "Book: " << bookTitles[i] << endl;
        cout << "Author: " << authors[i] << endl;
        cout << "Publication Year: " << publicationYears[i] << endl;
        cout << "------------------------" << endl;
    }

    cout << "First publication year through poiner: "
        << *yearPtr << endl;
}

int main() {
    // Application information
    string userName = "Joe";
    string applicationName = "My Book Tracker";
    double versionNumber = 4.0;

    // Display welcome screen
    cout << "===================================" << endl;
    cout << "       Welcome to My Book Tracker  " << endl;
    cout << "===================================" << endl;
    cout << "User: " << userName << endl;
    cout << "Application: " << applicationName << endl;
    cout << "Version: " << versionNumber << endl;
    cout << "===================================" << endl;

    int choice = 0;

    // Main menu loop
    while (choice != 6) {
        cout << "\n=== MY BOOK TRACKER ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. View Book Dataset" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        // Route menu choices to functions
        switch (choice) {
        case 1:
            addBook();
            break;

        case 2:
            viewBooks();
            break;

        case 3:
            searchBooks();
            break;

        case 4:
            removeBook();
            break;

        case 5:
            displayDataset();
            break;

        case 6:
            cout << "Goodbye! Thanks for using My Book Tracker." << endl;
            break;

        default:
            cout << "Invalid choice. Please choose an option from 1 to 5." << endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
