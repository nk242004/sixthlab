#include <iostream>

using namespace std;

struct INF{
    int key;
    char info;
};

int partition(INF arr[], int start, int end)
{
	int pivot = arr[start].key;

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i].key <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex].key, arr[start].key);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i].key <= pivot) {
			i++;
		}

		while (arr[j].key > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++].key, arr[j--].key);
		}
	}

	return pivotIndex;
}

void quickSort(INF arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}

void CreateArray(INF A[], const int NUM) {
	srand(1);

	for (int i = 0; i < NUM; i++)
		A[i].key = rand() % 100;
}

void ShowArray(INF A[], const int NUM) {
	for (int i = 0; i < NUM; i++)
		cout << A[i].key << ' ';
}


int main()
{
	const int NUM = 25;

	INF A[NUM];

	CreateArray(A, NUM);

	ShowArray(A, NUM);

	cout << endl;

	quickSort(A, 0, NUM - 1);

	ShowArray(A, NUM);

	return 0;
}
