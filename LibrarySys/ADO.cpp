#include "ADO.h"


ADO::ADO() {

}
ADO::ADO(string table) {

}
bool ADO::openTable(string table) {
	in.open(table + ".txt");
	if (!in) cout << "�ļ������ڣ�" << endl;
}
ResultSet select(string column, string value) {

}
bool ADO::insert(Record r) {

}
bool ADO::update(Record r1, Record r2) {

}
bool ADO::delByColumn(string column, string value) {

}