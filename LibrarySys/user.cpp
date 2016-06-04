#include "user.h"

User::User() {
	this->username = "";
	this->password = "";
}

User::User(string username, string password, string name) {
	this->username = username;
	this->password = password;
	this->name = name;
}

void User::set(string username, string password, string name) {
	this->username = username;
	this->password = password;
	this->name = name;
}

bool User::editPassword(string password) {
	return ado.update(type + "password=" + password);
}

bool User::editName(string name) {
	return ado.update(type + "name=" + name);
}

bool User::login() {
	if (this->ado.select(type + " " + "name=" + this->username + " password=" + this->password).columns.empty()) {
		return false;
	}
	else {
		return true;
	}
}

void User::setType(string type) {
	this->type = type;
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
