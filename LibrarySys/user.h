#pragma once
#ifndef H_USER_INC
#define H_USER_INC

#include "stdafx.h"
#include "ADO.h"

class User {
private:
	ADO ado;
	string username;
	string password;
	string name;
	string type;
public:
	User();
	User(string username, string password, string name);
	void set(string username, string password, string name);
	bool editPassword(string password);
	bool editName(string name);
	bool login();
	void setType(string type);
};

class Admin :public User {
public:
	Admin();
	Admin(string username, string password, string name);
};

class Customer :public User {
private:
	int amount;
public:
	Customer();
	Customer(string username, string password, string name);
	bool borrowByISBN(string ISBN);
	bool returnByISBN(string ISBN);
};

#endif