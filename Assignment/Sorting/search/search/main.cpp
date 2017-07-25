#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//Just need to modify the test cases to get data on a worst case scenario for both(so value in th last element for linear, and somewhere else for binary)
int linearSearch(const int* array, int size, int value);
int binarySearch(const int* array, int size, int value);

int main(){
	const int size = 100000;

	int searchKey;
	int idx;
	//array to store search times
	long long searchTimes[10][2];
	long long totalLinear = 0;
	long long totalBinary = 0;

	high_resolution_clock::time_point t1, t2;

	//create large array
	int* values = new int[size];
	for(int i = 0; i < size; i++){
		values[i] = i;
	}

	srand(time(NULL));
	
	cout << "profiling ";
	for(int i = 0; i < 10; i++){
		cout << ".";
		//do the searches here!

		//randomly choose a value to search for
		searchKey = (rand() * rand()) % size;

		//lin search
		t1 = high_resolution_clock::now();
		idx = linearSearch(values, size, searchKey);
		t2 = high_resolution_clock::now();

		searchTimes[i][0] = duration_cast<nanoseconds>(t2 - t1).count();

		//bin search
		t1 = high_resolution_clock::now();
		idx = binarySearch(values, size, searchKey);
		t2 = high_resolution_clock::now();

		searchTimes[i][1] = duration_cast<nanoseconds>(t2 - t1).count();

		//show running totl of times
		totalLinear += searchTimes[i][0];
		totalBinary += searchTimes[i][1];
	}

	cout << endl;

	//average the search times for them both, display
	cout << "Average linear search time was " << totalLinear << " nanoseconds\n";
	cout << "Average binary search time was " << totalBinary << " nanoseconds\n";

	delete[] values;
	system("pause");
	return 0;
}

//linear search
int linearSearch(const int* array, int size, int value){
	for(int i = 0; i < size; i++){
		if(array[i] == value){
			return i;
		}
	}
	return -1;
}

//binarySearch()
int binarySearch(const int* array, int size, int value){
	//checks to see if array isn't 0 size
	if(size <= 0) {
		return -1;
	}

	int min = -1;
	int max = size ;
	int mid;

	while(min != max){
		mid = (min + max) / 2;

		if(array[mid] == value){
			return mid;
		}else if(array[mid] > value){
			max = mid - 1;
		}else if(array[mid] < value){
			min = mid + 1;
		}
	}
	return -1;
}