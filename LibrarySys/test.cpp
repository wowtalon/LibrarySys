
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string table = "book";
	ifstream in;
	in.open(table + ".txt");
	if (!in) cout << "文件不存在！" << endl;
	else cout << "OK!" << endl;
	return 0;
}