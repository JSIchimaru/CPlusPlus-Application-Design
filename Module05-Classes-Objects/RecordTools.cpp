#include <iostream>
#include <string>
#include <limits>
#include "RecordTools.h"

using namespace std;

void showMessage() {
	cout << "Book Tracker system ready!" << endl;
}

void addBook(string titles[], string authors[], 
			 int years[], int& bookCount) {

	if (bookCount >= MAX_BOOKS) {
		cout << "Your book list is full." << endl;
		return;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter book title: ";
	getline(cin, titles[bookCount]);

	cout << "Enter author: ";
	getline(cin, authors[bookCount]);

	cout << "Enter publication year: ";
	while (!(cin >> years[bookCount])) {
		cout << "Please enter a valid year: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	bookCount++;

	cout << "Book added successfully!" << endl;
}

void viewBooks(string titles[], string authors[],
	           int years[], int bookCount) {
	
	cout << "\n=== YOUR BOOKS ===" << endl;

	if (bookCount == 0) {
		cout << "No books have been added yet." << endl;
		return;
	}

	for (int i = 0; i < bookCount; i++) {
		cout << "\nBook " << i + 1 << endl; 
		cout << "Title: " << titles[i] << endl;
		cout << "Author: " << authors[i] << endl;
		cout << "Publication Year: " << years[i] << endl;
		cout << "------------------------" << endl;
	}
}

void searchBooks() {
	cout << "Search Books selected." << endl;
}

void removeBook() {
	cout << "Remove Book selected." << endl;
}

void calculateAverageYear(int years[], int bookCount) {

	if (bookCount == 0) {
		cout << "There are no books to calculate." << endl;
		return;
	}

	int total = 0;

	for (int i = 0; i < bookCount; i++) {
		total += years[i];
	}

	double average = static_cast<double>(total) / bookCount;

	cout << "Average publication year: "
		<< average << endl;
}