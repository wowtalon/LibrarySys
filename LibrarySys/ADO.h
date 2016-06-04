#pragma once
#ifndef H_ADO_INC
#define H_ADO_INC

#include "stdafx.h"

struct ResultSet {
	map<string, string> columns;
};

class ADO {
private:
	string location;
	vector<string> line;

	// ��¼���ı�ͷ
	vector<string> header;

	ResultSet ret;
public:
	ADO();

	// ��ʼ��ADO�ļ�����λ��
	ADO(string location);

	// ��ȡ�ļ�
	ResultSet select(string sql);

	// д�ļ�
	bool insert(string sql);

	// �޸��ļ�
	bool update(string sql);

};

#endif