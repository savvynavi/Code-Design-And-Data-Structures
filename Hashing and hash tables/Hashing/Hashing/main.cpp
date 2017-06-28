#include<iostream>
#include"HashFunction.h"
#include"HashTable.h"
using namespace std;
using namespace HashFunction;

int main(){
	unsigned char* data;
	data = new unsigned char('test');
	//cout << badHash("test", 4) << endl;
	//cout << ELFHash(data, 4) << endl;

	//template<string, array>
	HashTable<unsigned char*, int> table(5);

	table.addValue(data);
	table.print(data);
	cout << endl;
	//cout << table[data] << endl;
	system("pause");
	return 0;
}