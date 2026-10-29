// Make-Up Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "RecordTools.h"

using namespace std;

int main()  {
    
    string userName = "Joe";
    string applicationName = "My Book Tracker";
    double versionNumber = 4.5;

    cout << "===================================" << endl;
    cout << "       Welcome to My Book Tracker  " << endl;
    cout << "===================================" << endl;
    cout << "User: " << userName << endl;
    cout << "Application: " << applicationName << endl;
    cout << "Version: " << versionNumber << endl;
    cout << "===================================" << endl;

    showMessage();

    int bookIDs[MAX_BOOKS] = {};
    string bookTitles[MAX_BOOKS] = {};
    string authors[MAX_BOOKS] = {};
    int publicationYears[MAX_BOOKS] = {};

    int bookCount = 0;
   
    fstream MyFile("books.csv", ios::in);

    if (!MyFile.is_open()) {
        cout << "\nError: Could not open books.csv." << endl;
        cout << "Make sure the file is in the program's "
            << "working directory." << endl;
        return 1;
    }

    string header;
    getline(MyFile, header);

    string title;
    string author;
    string yearText;

    while (
        bookCount < MAX_BOOKS &&
        getline(MyFile, title, ',') &&
        getline(MyFile, author, ',') &&
        getline(MyFile, yearText)
     ){ 
        try {
            int year = stoi(yearText);

            bookIDs[bookCount] = bookCount + 1;
            bookTitles[bookCount] = title;
            authors[bookCount] = author;
            publicationYears[bookCount] = year;

            bookCount++;
        }
        catch (...) {
            cout << "Skipping a row with an invalid year."
                << endl;
        }
    }

    MyFile.close();

    cout << "\nLoaded " << bookCount
        << " books from books.csv." << endl;

    int choice = 0;

    while (choice != 6) {

        cout << "\n=== MY BOOK TRACKER ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Search Books" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. View Book Dataset and Pointer" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number from 1 to 6."
                << endl;

            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            continue;
        }

        switch (choice) {

        case 1:
            addBook(
                bookIDs,
                bookTitles,
                authors,
                publicationYears,
                bookCount
            );
            break;

        case 2:
            viewBooks(
                bookIDs,
                bookTitles,
                authors,
                publicationYears,
                bookCount
            );
            break;

        case 3:
            searchBooks(
                bookIDs,
                bookTitles,
                authors,
                publicationYears,
                bookCount
            );
            break;

        case 4:
            removeBook(
                bookIDs,
                bookTitles,
                authors,
                publicationYears,
                bookCount
            );
            break;

        case 5: {
            cout << "\n=== BOOK DATASET ===" << endl;

            if (bookCount == 0) {
                cout << "No book records are available."
                    << endl;
                break;
            }

            for (int i = 0; i < bookCount; i++) {
                cout << "\nBook ID: " << bookIDs[i] << endl;
                cout << "Title: " << bookTitles[i] << endl;
                cout << "Author: " << authors[i] << endl;
                cout << "Publication Year: "
                    << publicationYears[i] << endl;
            }

            int* yearPtr = &publicationYears[0];
            cout << "\nFirst publication year through pointer: "
                << *yearPtr << endl;
            
            break;

        }

        case 6:
            cout << "Goodbye! Thanks for using "
                << applicationName << "." << endl;
            break;

        default:
            cout << "Invalid choice. Please choose 1 to 6."
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
