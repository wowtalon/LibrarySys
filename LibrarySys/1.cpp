#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string table = "book";
	const std::string t = table + ".txt";
	ifstream in;
	in.open(t, ios::in);
	if (!in) cout << "�ļ������ڣ�" << endl;
	else cout << "OK!" << endl;
	return 0;
} 
