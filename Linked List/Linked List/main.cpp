#include"LinkedList.h"
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){
	LinkedList list;

	list.pushBack(10);
	list.pushBack(12);
	list.pushFront(10);

	list.setFirst(99);
	auto iter2 = list.find(99);
	list.insert(iter2, 5);
	iter2 = list.begin();
	while(iter2.getNode() != nullptr){
		cout << *iter2 << endl;
		iter2++;
	}
	system("pause");
	return 0;
}