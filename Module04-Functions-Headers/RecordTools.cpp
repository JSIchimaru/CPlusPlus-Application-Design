#include <iostream>
#include <string>
#include <limits>
#include "RecordTools.h"

using namespace std;

// ================================
// Book class functions
// ================================

Book::Book(string bookTitle, string bookAuthor, int id, int year) {
	title = bookTitle;
	author = bookAuthor;
	bookID = id;
	publicationYear = year;
}

void Book::displayBook() {
	cout << "Book ID: " << bookID << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publication Year: " << publicationYear << endl;
}

void Book::setPublicationYear(int newYear) {
	publicationYear = newYear;
}

string Book::getTitle() {
	return title;
}

// ================================
// User class funtions
// ================================

User::User(string name) {
	username = name;
}

string User::getUsername() {
	return username;
}

// ================================
// Admin class functions
// ================================

Admin::Admin(string name) : User(name) {}

void Admin::addRecord() {
	cout << "Admin access: you can add books." << endl;
}

void Admin::deleteRecord() {
	cout << "Admin access: you can delete books." << endl;
}

// ================================
// Regular User class functions
// ================================

RegularUser::RegularUser(string name) : User(name) {}

void RegularUser::viewRecords() {
	cout << "Regular usee access: you can view books." << endl;
}

void RegularUser::searchRecords() {
	cout << "Regular user access: you can search for books." << endl;
}

// ================================
// General functions
// ================================

void showMessage() {
	cout << "Book Tracker system ready!" << endl;
}

// ================================
// Add Book
// ================================

void addBook(
	int ids[],
	string titles[],
	string authors[],
	int years[],
	int& bookCount
) {
	if (bookCount >= MAX_BOOKS) {
		cout << "Your book list is full." << endl;
		return;
	}

	ids[bookCount] = bookCount + 1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter book title: ";
	getline(cin, titles[bookCount]);

	cout << "Enter publication year: ";

	while (!(cin >> years[bookCount])) {
		cout << "Please enter a valid year: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Book ID: " << ids[bookCount] << endl;

	bookCount++;

	cout << "Book added successfully!" << endl;

}

// ================================
// View Books
// ================================

void viewBooks(
	int ids[],
	string titles[],
	string authors[],
	int years[],
	int bookCount
) {
	cout << "\n=== YOUR BOOKS ===" << endl;

	if (bookCount == 0) {
		cout << "No books have been added yet." << endl;
		return;
	}

	for (int i = 0; i < bookCount; i++) {
		cout << "\nBook ID: " << ids[i] << endl;
		cout << "Title: " << titles[i] << endl;
		cout << "Author: " << authors[i] << endl;
		cout << "Publication Year: " << years[i] << endl;
		cout << "------------------------" << endl;
	}
}

// ================================
// Binary Search
// ================================

int binarySearch(
	int ids[],
	int size,
	int target
) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {

		int mid = left + (right - left) / 2;

		if (ids[mid] == target) {
			return mid;
		}

		if (ids[mid] < target) {
			left = mid + 1;
		}

		else {
			right = mid - 1;
		}
	}

	return -1;
}

// ================================
// Search Books
// ================================

void searchBooks(
	int ids[],
	string titles[],
	string authors[],
	int years[],
	int bookCount
) {
	if (bookCount == 0) {
		cout << "There are no books to search." << endl;
		return;
	}

	int targetID;

	cout << "Enter the Book ID to search for: ";
	cin >> targetID;

	int result = binarySearch(ids, bookCount, targetID);

	if (result != -1) {
		cout << "\nBook found!" << endl;
		cout << "Book ID: " << ids[result] << endl;
		cout << "Title: " << titles[result] << endl;
		cout << "Author: " << authors[result] << endl;
		cout << "Publication Year: " << years[result] << endl;
	}
	else {
		cout << "Book ID " << targetID
			<< "was not found." << endl;
	}
}

// ================================
// Remove Book
// ================================

void removeBook(
	int ids[],
	string titles[],
	string authors[],
	int years[],
	int& bookCount
) {
	if (bookCount == 0) {
		cout << "There are no books to remove." << endl;
		return;
	}

	int targetID;

	cout << "Enter the Book ID to remove: ";
	cin >> targetID;

	int result = binarySearch(ids, bookCount, targetID);

	if (result == -1) {
		cout << "Book ID " << targetID << " was not found." << endl;
		return;
	}

	for (int i = result; i < bookCount - 1; i++) {
		ids[i] = ids[i + 1];
		titles[i] = titles[i + 1];
		authors[i] = authors[i + 1];
		years[i] = years[i + 1];
	}

	bookCount--;

	cout << "Book removed successfully." << endl;
}

// ================================
// Calculate Average Year
// ================================

void calculateAverageYear(
	int years[],
	int bookCount
) {
	if (bookCount == 0) {
		cout << "There are no books to calculate." << endl;
		return;
	}

	int total = 0;

	for (int i = 0; i < bookCount; i++) {
		total += years[i];
	}

	double average =
		static_cast<double>(total) / bookCount;

	cout << "Average publication year: "
		<< average << endl;
}