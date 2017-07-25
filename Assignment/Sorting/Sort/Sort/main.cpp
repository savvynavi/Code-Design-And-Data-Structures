#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int* const array, int size);
void insertionSort(int* const array, int size);
void mergeSort(int* const arrayA, int size);
void mergeSplit(int* const arrayA, int startIdx, int endIdx, int* const arrayB);
void merge(int* const arrayA, int startIdx, int midIdx, int endIdx, int* const arrayB);
void copyArray(int* const arrayA, int startIdx, int endIdx, int* const arrayB);


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
		cout << valuesToSort[i] << ", ";
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
	mergeSort(valuesToSort, size);
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
void mergeSort(int* const arrayA, int size){
	int* arrayB = new int[size];
	copyArray(arrayA, 0, size, arrayB);
	mergeSplit(arrayB, 0, size, arrayA);
}

void mergeSplit(int* const arrayA, int startIdx, int endIdx, int* const arrayB){
	//Once array size is one, it is sorted
	if (endIdx - startIdx <= 1) {
		return;
	}

	int midIdx = (startIdx + endIdx) / 2; 

	//split left until the size is 1
	mergeSplit(arrayB, startIdx, midIdx, arrayA);
	//Split right until size is 1
	mergeSplit(arrayB, midIdx, endIdx, arrayA);
	
	//Merge them together in order
	merge(arrayA, startIdx, midIdx, endIdx, arrayB);
}

void merge(int* const arrayA, int startIdx, int midIdx, int endIdx, int* const arrayB){
	//Current indexes
	int i = startIdx;
	int j = midIdx;

	for (int k = startIdx; k < endIdx; k++) {
		//As long as there is a left side to merge into original and either there is no more right side to merge or current index value is smaller than or equal to other current index, merge left side
		if (i < midIdx && (j >= endIdx || arrayA[i] <= arrayA[j])) {
			arrayB[k] = arrayA[i];
			i = i + 1;
		}
		//if not merging left, merge right
		else {
			arrayB[k] = arrayA[j];
			j = j + 1;
		}
	}
}

void copyArray(int* const arrayA, int startIdx, int endIdx, int* const arrayB){
	for (int k = startIdx; k < endIdx; k++)
		arrayB[k] = arrayA[k];
}