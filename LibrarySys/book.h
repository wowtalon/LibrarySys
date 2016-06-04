#pragma once
#ifndef H_BOOK_INC
#define H_BOOK_INC

#include "stdafx.h"

class Book {
private:
	string name;
	string ISBN;
	string author;
	vector<string> v_name;
	vector<string> v_ISBN;
	vector<string> v_author;
	vector<bool> v_isAvailable;
public:
	Book();
	Book(const Book& b);
	Book(string name, string author, string ISBN);
	bool insert();
	bool deleteByISBN(string ISBN);
	bool borrow(string ISBN);
	void findAll();
	void findByName(string name);
	void findByAuthor(string author);
	void findByISBN(string ISBN);
};

#endif