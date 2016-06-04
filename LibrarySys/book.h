#pragma once
#ifndef H_BOOK_INC
#define H_BOOK_INC

#include "stdafx.h"
#include "ADO.h"

class Book {
private:
	string name;
	string ISBN;
	string author;
	bool isAvailable;
	/*vector<string> v_name;
	vector<string> v_ISBN;
	vector<string> v_author;
	vector<bool> v_isAvailable;*/
	ADO *ado;
public:
	Book();
	Book(const Book& b);
	Book(string name, string author, string ISBN, bool b);
	bool insert();
	bool deleteByISBN(string ISBN);
	bool borrow(string ISBN, string username);
	bool re(string ISBN, string username);
	ResultSet findAll();
	ResultSet findByName(string name);
	ResultSet findByAuthor(string author);
	ResultSet findByISBN(string ISBN);
	string getName();
	string getAuthor();
	string getISBN();
	bool getIsAvailable();
};


#endif