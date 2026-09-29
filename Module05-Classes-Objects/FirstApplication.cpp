// FirstApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>
#include "RecordTools.h"
using namespace std;



int main() {

    // Application information
    string userName = "Joe";
    string applicationName = "My Book Tracker";
    double versionNumber = 5.0;

    // Dataset
    string bookTitles[MAX_BOOKS] = {
    "Harry Potter Collection (Harry Potter #1-6)",
    "The Lord of the Rings (The Lord of the Rings #1-3)",
    "Atlas Shrugged",
    "War and Peace",
    "The Odyssey"
    };

    string authors[MAX_BOOKS] = {
        "J.K. Rowling",
        "J.R.R. Tolkien",
        "Ayn Rand",
        "Leo Tolstoy",
        "Homer"
    };

    int publicationYears[MAX_BOOKS] = {
        2005,
        2004,
        1999,
        1998,
        1998
    };
    
    int bookCount = 5;

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
    while (choice != 7) {
        cout << "\n=== MY BOOK TRACKER ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Show First Year Through Pointer" << endl;
        cout << "6. Calculate Average Publication Year" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose an option: ";

        // Validate menu input
        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number from 1 to 7."
                << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Route choices to functions
        switch (choice) {
        case 1:
            addBook(bookTitles, authors,
                publicationYears, bookCount);
            break;

        case 2:
            viewBooks(bookTitles, authors,
                publicationYears, bookCount);
            break;

        case 3:
            searchBooks();
            break;

        case 4:
            removeBook();
            break;

        case 5: {
            if (bookCount == 0) {
                cout << "There are no books yet." << endl;
            }
            else {
                int* yearPtr = &publicationYears[0];
                cout << "First publication year through pointer: "
                    << *yearPtr << endl;
            }
            break;
        }

        case 6:
            calculateAverageYear(publicationYears, bookCount);
            break;

        case 7:
            cout << "Goodbye! Thanks for using My Book Tracker."
                << endl;
            break;

        default:
            cout << "Invalid choice. Please choose 1 to 7."
                << endl;
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
