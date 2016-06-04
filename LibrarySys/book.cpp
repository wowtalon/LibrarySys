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
	if (this->ISBN != "") {
		if (this->findByISBN(this->ISBN).record.empty()) {
			r.columns["name"] = this->name;
			r.columns["author"] = this->author;
			r.columns["ISBN"] = this->ISBN;
			r.columns["isAvailable"] = this->isAvailable;
			ado->insert(r);
		}
		else {
			cout << "ISBN existed!" << endl;
		}
	}
	else {
		cout << "Invailable value!" << endl;
	}
}

bool Book::deleteByISBN(string ISBN) {
	return ado->delByColumn("ISBN", ISBN);
}

bool Book::borrow(string ISBN, string username) {
	ResultSet ret = this->findByISBN(ISBN);
	if (!ret.record.empty()) {
		Record r = ret.record[0];
		if (r.columns["isAvailable"] == "*") {
			Record r1;
			r1 = r;
			r1.columns["isAvailable"] = username;
			return ado->update(r, r1);
		}
		else {
			cout << "Invalid book." << endl;
			return false;
		}
	}
	else {
		cout << "This book is not exist." << endl;
		return false;
	}
}

bool Book::re(string ISBN, string username) {
	ResultSet ret = this->findByISBN(ISBN);
	if (ret.record.empty()) {
		return false;
	}
	else {
		Record r = ret.record[0];
		if (r.columns["isVailable"] == username) {
			Record r1 = r;
			r1.columns["isVailable"] = "*";
			return ado->update(r, r1);
		}
		else {
			return false;
		}
	}
}

ResultSet Book::findAll() {
	return ado->selectByColumn("*", "*");
}
ResultSet Book::findByName(string name) {
	return ado->selectByColumn("name", name);
}
ResultSet Book::findByAuthor(string author) {
	return ado->selectByColumn("author", author);
}
ResultSet Book::findByISBN(string ISBN) {
	return ado->selectByColumn("ISBN", ISBN);
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