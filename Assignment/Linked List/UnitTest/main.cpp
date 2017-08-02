#include"LinkedList.h"
#define CATCH_CONFIG_RUNNER

#include"catch.hpp"
#include<iostream>
using namespace std;

TEST_CASE("items added/removed from list correctly", "[Linked List]"){
	LinkedList test;
	REQUIRE(test.empty() == true);
	test.pushBack(5);
	test.pushBack(15);
	test.pushFront(10);
	REQUIRE(test.count() == 3);
	REQUIRE(test.getFirst() == 10);
	REQUIRE(test.getLast() == 15);
	SECTION("poping/pushing changes the first and last node"){
		test.popFront();
		test.popBack();
		REQUIRE(test.getFirst() == 5);
		REQUIRE(test.getLast() == 5);
		REQUIRE(test.count() == 1);
		test.pushBack(20);
		test.pushFront(-7);
		REQUIRE(test.getFirst() == -7);
		REQUIRE(test.getLast() == 20);
	}
	SECTION("changing first/last node directly"){
		test.setFirst(0);
		test.setLast(40);
		REQUIRE(test.getFirst() == 0);
		REQUIRE(test.getLast() == 40);
	}
	SECTION("Clearing whole list"){
		test.clear();
		REQUIRE(test.empty() == true);
	}
	SECTION("remove all instances of a number from list"){
		for(int i = 0; i < 5; i++){
			test.pushBack(10);
		}
		test.pushBack(9);
		REQUIRE(test.count() == 9);
		test.remove(10);
		LinkedListIterator iter;
		REQUIRE(test.find(10) == iter);
	}
}

TEST_CASE("iterator tests","[LinkedList]"){
	LinkedList test;
	LinkedListIterator iter;
	test.pushBack(5);
	test.pushBack(10);
	test.pushBack(15);
	SECTION("begin/end iterators point to correct place"){
		iter = test.begin();
		REQUIRE(test.find(5) == iter);
		iter = test.end();
		LinkedListIterator nullIter;
		REQUIRE(nullIter == iter);
	}
	SECTION("erase function removes elements properly"){
		iter = test.begin();
		test.erase(iter);
		iter.setNode(nullptr);
		REQUIRE(test.find(5) == iter);
	}
	SECTION("Indert function adds to correct place"){
		iter = test.begin();
		test.insert(iter, 20);
		REQUIRE((test.begin().getNode()->getNext()->getData()) == 20);
	}
}


int main(int argc, char* argv[]){
	int result = Catch::Session().run(argc, argv);
	
	system("pause");
	return (result < 0xff ? result : 0xff);
}
