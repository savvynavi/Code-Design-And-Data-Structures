#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void bogo(vector<int> &list);
void bubble(vector<int> &list);
void insert(vector<int> &list);
void print(vector<int> &list);

int main(){
	vector<int> list = {5, 2, 8, 7, 3, 1, 9, 4, 6};
	bogo(list);
	print(list);
	system("pause");
	return 0;
}


//if list isn't sorted, shuffles it and checks again until sorted
void bogo(vector<int> &list){
	while(!is_sorted(list.begin(), list.end())){
		random_shuffle(list.begin(), list.end());
	}
}

//compares adjacent entries in list, swaps if out of order, does this until sorted
void bubble(vector<int> &list){
	for(int i = 1; i < list.size(); i++){
		for(int j = 0; j < list.size() - 1; j++){
			if(list[j] > list[i]){
				int tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

//takes 1 element at a time and moves it backwards through list until sorted
void insert(vector<int> &list){
	int insertValue;
	int subEnd;
	for(int i = 1; i < list.size(); i++){
		insertValue = list[i];
		subEnd = i;
		while((subEnd > 0) && (list[subEnd - 1] > insertValue)){
			list[subEnd] = list[subEnd - 1];
			subEnd = subEnd - 1;
		}
		list[subEnd] = insertValue;
	}
}

//prints out list contents
void print(vector<int> &list){
	for(vector<int>::iterator i = list.begin(); i != list.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
}