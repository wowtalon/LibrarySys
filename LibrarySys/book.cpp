#include "book.h"

Book::Book() {
	this->name = "";
	this->author = "";
	this->ISBN = "";
	this->isAvailable = false;
}
Book::Book(const Book& b) {
	this->name = b.getName;
	this->author = b.getAuthor;
	this->ISBN = b.getISBN;
	this->isAvailable = b.getIsAvailable;
}
Book::Book(string name, string author, string ISBN, bool b) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
	this->isAvailable = b;
}

bool Book::insert() {

}

bool Book::deleteByISBN(string ISBN) {

}

bool Book::borrow(string ISBN) {

}

void Book::findAll() {

}
void Book::findByName(string name) {

}
void Book::findByAuthor(string author) {

}
void Book::findByISBN(string ISBN) {

}

string Book::getName() {
	return this->name;
}

string Book::getAuthor() {
	return this->author;
}

string Book::getISBN() {
	return this->ISBN;
}

bool Book::getIsAvailable() {
	return this->isAvailable;
}