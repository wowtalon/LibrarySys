#include "book.h"

Book::Book() {
	this->name = "";
	this->author = "";
	this->ISBN = "";
	this->isAvailable = false;
	ado = new ADO("book");
}
Book::Book(const Book& b) {
	this->name = b.getName;
	this->author = b.getAuthor;
	this->ISBN = b.getISBN;
	this->isAvailable = b.getIsAvailable;
	ado = new ADO("book");
}
Book::Book(string name, string author, string ISBN, bool b) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
	this->isAvailable = b;
	ado = new ADO("book");
}

bool Book::insert() {
	Record r;
	if (this->name != "") {
		if (this->findByISBN(this->ISBN).columns.empty) {
			r.columns["name"] = this->name;
			r.columns["author"] = this->author;
			r.columns["ISBN"] = this->ISBN;
			r.columns["isAvailable"] = this->isAvailable;
			ado->insert(r);
		}
		else {
			throw "ISBN existed!";
		}
	}
	else {
		throw "Invailable value!";
	}
}

bool Book::deleteByISBN(string ISBN) {
	return ado->delByColumn("ISBN", ISBN);
}

bool Book::borrow(string ISBN) {
	if (this->findByISBN(ISBN).columns.size > 0) {
		if (this->findByISBN(ISBN).columns["isAvailable"] == "y") {
			this->findByISBN(ISBN).columns["isAvailable"] = "n";
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Book::findAll() {

}
void Book::findByName(string name) {

}
void Book::findByAuthor(string author) {

}
Record& Book::findByISBN(string ISBN) {

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

ex::ex(char *w) {

}
const char* what() {

}