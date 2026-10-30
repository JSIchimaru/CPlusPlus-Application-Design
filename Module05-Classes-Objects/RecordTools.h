#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <string>
using namespace std;

const int MAX_BOOKS = 10;

void showMessage();

void addBook(string titles[], string authors[],
			 int years[], int bookCount);

void viewBooks(string titles[], string authors[], 
			   int years[], int& bookCount);

void searchBooks();

void removeBook();

void calculateAverageYear(int years[], int bookCount)


#endif
