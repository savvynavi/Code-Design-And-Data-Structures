#include<iostream>
#include"HashFunction.h"
#include"HashTable.h"
#include<string>
#define CATCH_CONFIG_RUNNER
#include"catch.hpp"
using namespace std;
using namespace HashFunction;

unsigned char* createChar(std::string key);

TEST_CASE("Testing hashing functions", "[HashTable]"){
	HashTable<unsigned char*, int> test(20);
	unsigned char* key1 = createChar("keyWords");
	unsigned char* key2 = createChar("testingTable");
	unsigned char* key3 = createChar("hashedText");
	test.addValue(key1, 10);
	test.addValue(key2, 20);
	test.addValue(key3, 30);
	SECTION("adding/removing from table"){
		REQUIRE(test[key1] == 10);
		test.removeValue(key1);
		REQUIRE(test[key1] == NULL);
	}
	SECTION("testing clear"){
		test.clear();
		REQUIRE(test[key2] == NULL);
	}
}

int main(int argc, char* argv[]){
	int result = Catch::Session().run(argc, argv);

	system("pause");
	return (result < 0xff ? result : 0xff);
}

unsigned char* createChar(std::string key){
	int size = key.length();
	unsigned char* tempData = new unsigned char[size];
	for(int i = 0; i < size; i++){
		tempData[i] = key[i];
	}
	tempData[size] = '\0';
	return tempData;
}