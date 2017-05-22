#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void bogo(vector<int> &list);
void bubble(vector<int> &list);
void insert(vector<int> &list);
void print(vector<int> &list);

int main(){
	vector<int> list = {5, 2, 8, 7, 3, 1, 9, 4, 6};
	bubble(list);
	print(list);
	system("pause");
	return 0;
}


//if list isn't sorted, shuffles it and checks again until sorted
void bogo(vector<int> &list){

}

//compares adjacent entries in list, swaps if out of order, does this until sorted
void bubble(vector<int> &list){
	bool swapped = true;
	while(swapped == true){
		for(vector<int>::iterator i = next(list.begin()); i != list.end(); ++i){
			swapped = false;
			if(*(i - 1) > (*i)){
				int tmp = *i;
				*i = *(i - 1);
				*(i - 1) = tmp;
				swapped = true;
			}
		}
	}
}

//takes 1 element at a time and moves it backwards through list until sorted
void insert(vector<int> &list){

}

void print(vector<int> &list){
	for(vector<int>::iterator i = list.begin(); i != list.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
}