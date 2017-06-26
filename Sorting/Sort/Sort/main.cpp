#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int* const array, int size);
void insertionSort(int* const array, int size);
void mergeSort(int* const array, int startIdx, int endIdx);
void merge(int* const array, int startIdx, int midIdx, int endIdx);

int main(){
	const int size = 100;

	int* values = new int[size];
	int* valuesToSort = new int[size];

	srand(time(NULL));
	for(int i = 0; i < size; i++){
		values[i] = rand() % size;
	}

	high_resolution_clock::time_point t1, t2;


	//profile bubble sort
	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();
	bubbleSort(valuesToSort, size);
	t2 = high_resolution_clock::now();

	for(int i = 0; i < size; i++){
		cout << values[i] << ", ";
	}
	cout << endl << endl;

	cout << "Bubble sort took " << (t2 - t1).count() << " nanoseconds\n";

	//pause
	cout << "Press enter to profile Insertion sort" << endl;
	cin.get();
	cout << endl;

	//profile insertion sort
	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();
	insertionSort(valuesToSort, size);
	t2 = high_resolution_clock::now();

	for(int i = 0; i < size; i++){
		cout << valuesToSort[i] << ", ";
	}
	cout << endl << endl;

	cout << "Insertion sort took " << (t2 - t1).count() << " nanoseconds\n";

	//pause
	cout << "Press enter to profile Merge sort" << endl;
	cin.get();
	cout << endl;

	//profile insertion sort
	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();
	mergeSort(valuesToSort, 0, size - 1);
	t2 = high_resolution_clock::now();

	for(int i = 0; i < size; i++){
		cout << valuesToSort[i] << ", ";
	}
	cout << endl << endl;

	cout << "Merge sort took " << (t2 - t1).count() << " nanoseconds\n";

	delete[] values;
	delete[] valuesToSort;
	system("pause");
	return 0;
}

//bubble sort
void bubbleSort(int* const array, int size){
	for(int i = 0; i < size; i++){
		for(int j = size - 1; j > i; j--){
			if(array[j] < array[j - 1]){
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}

//insert sort
void insertionSort(int* const array, int size){
	int key;
	for(int i = 1; i < size; i++){
		key = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] > key){
			array[j + 1] = array[j];
			j = j - 1;
			array[j + 1] = key;
		}
	}
}

//merge sort
void mergeSort(int* const array, int startIdx, int endIdx){
	int midIdx;
	if(startIdx < endIdx){
		midIdx = (startIdx + endIdx) / 2;
		mergeSort(array, startIdx, midIdx);
		mergeSort(array, (midIdx + 1), endIdx);
		merge(array, startIdx, midIdx, endIdx);
	}
}

void merge(int* const array, int startIdx, int midIdx, int endIdx){
	const int leftEnd = midIdx - startIdx + 1;
	const int rightEnd = endIdx - midIdx;

	
}