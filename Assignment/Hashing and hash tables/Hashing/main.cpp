#include<iostream>
#include"HashFunction.h"
#include"HashTable.h"
#include<string>

using namespace std;
using namespace HashFunction;

unsigned char* createChar(std::string key){
	int size = key.length();
	unsigned char* tempData = new unsigned char[size];
	for(int i = 0; i < size; i++){
		tempData[i] = key[i];
	}
	tempData[size] = '\0';
	return tempData;
}


int main(){
	unsigned char* data0 = createChar("test");
	unsigned char* data1 = createChar("hash browns and errorrrs");
	unsigned char* data2 = createChar("oh god help me");
	unsigned char* data3 = createChar("why me");
	unsigned char* data4 = createChar("worstfunctionever");
	unsigned char* data5 = createChar("best");

	HashTable<unsigned char*, int> table(6);
	table.print();
	cout << endl;
	table.addValue(data0, 5);
	table.addValue(data1, 15);
	table.addValue(data2, 25);
	table.addValue(data3, 35);
	table.addValue(data4, 45);
	table.addValue(data5, 55);

	table.print();


	system("pause");
	return 0;
}