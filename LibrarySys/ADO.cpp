#include "ADO.h"


ADO::ADO() {

}
ADO::ADO(string table) {

}
bool ADO::openTable(string table) {
	in.open(table + ".txt");
	if (!in) cout << "�ļ������ڣ�" << endl;
}
ResultSet select(string column, string value);
bool insert(Record r);
bool update(Record r1, Record r2);