#include "user.h"

User::User() {
	this->username = "";
	this->password = "";
	isLogon = false;
}

User::User(string username, string password, string name) {
	this->username = username;
	this->password = password;
	this->name = name;
	isLogon = false;
}

void User::set(string username, string password, string name) {
	this->username = username;
	this->password = password;
	this->name = name;
	isLogon = false;
}

bool User::editPassword(string password) {
	if (isLogon == false) {
		cout << "You have not login." << endl;
		return false;
	}
	Record r, r1;
	r.columns["username"] = this->username;
	r.columns["name"] = this->name;
	r.columns["password"] = password;
	r1 = ado->selectByColumn("username", this->username).record[0];
	return ado->update(r1, r);
}

bool User::editName(string name) {
	if (isLogon == false) {
		cout << "You have not login." << endl;
		return false;
	}
	Record r, r1;
	r.columns["username"] = this->username;
	r.columns["name"] = name;
	r.columns["password"] = this->password;
	r1 = ado->selectByColumn("username", this->username).record[0];
	return ado->update(r1, r);
}

bool User::login() {
	ResultSet ret = ado->selectByColumn("username", this->username);
	if (ret.record.empty()) {
		cout << "invalid username." << endl;
		return false;
	}
	else {
		Record r = ret.record[0];
		if (r.columns["password"] == this->password) {
			isLogon = true;
			return true;
		}
		else return false;
	}
}

void User::setType(string type) {
	this->type = type;
}

string User::getUsername() {
	return this->username;
}


// ADMIN

Admin::Admin() {
	User();
	this->setType("admin");
}
Admin::Admin(string username, string password, string name) {
	User(username, password, name);
	this->setType("admin");
}

Customer::Customer() {
	User();
	this->setType("Customer");
}
Customer::Customer(string username, string password, string name) {
	User(username, password, name);
	this->setType("Customer");
}
bool Customer::borrowByISBN(string ISBN) {
	Book book;
	return book.borrow(ISBN, this->getUsername());
}
bool Customer::returnByISBN(string ISBN) {
	Book book;
	return book.re(ISBN, this->getUsername());
}
