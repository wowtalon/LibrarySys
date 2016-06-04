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

	// 记录表格的表头
	vector<string> header;

	ResultSet ret;
public:
	ADO();

	// 初始化ADO文件所在位置
	ADO(string location);

	// 读取文件
	ResultSet select(string sql);

	// 写文件
	bool insert(string sql);

	// 修改文件
	bool update(string sql);

};

#endif