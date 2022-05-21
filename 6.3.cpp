#include <iostream>
#include <iostream>
#include <chrono>

using namespace std;

using namespace std;

class StopWatch
{
public:
	StopWatch();

	~StopWatch();


private:
	std::chrono::time_point<std::chrono::steady_clock> end, start;
	std::chrono::duration<double> duration;
};


StopWatch::StopWatch()
{
	this->start = std::chrono::steady_clock::now();
}

StopWatch::~StopWatch()
{
	if (end == std::chrono::steady_clock::time_point())								// if we already stopped the clock
		end = std::chrono::steady_clock::now();

	duration = end - start;

	double result = duration.count();

	std::cout << "Time\t" << result << " seconds" << std::endl;
}


void CreateArray(int A[], int B[], const int NUM) {
	srand(1);

	for (int i = 0; i < NUM; i++)
		A[i] = B[i] = rand() % 100;
}

void RestoreArray(int A[], int B[], const int NUM) {
	for (int i = 0; i < NUM; i++)
		A[i] = B[i];
}


int partition(int arr[], int start, int end)
{
	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}


	

int main()
{
	const unsigned int NUM = 50000;

	int A[NUM];
	int B[NUM];

	CreateArray(A, B, NUM);

	{
		StopWatch si;

		for (int i = 0; i < NUM; i++) {
			int j = i;

			while (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);

				if (--j == 0)
					break;

			}
		}
	}

	RestoreArray(A, B, NUM);

	{
		StopWatch qs;

		quickSort(A, 0, NUM - 1);
	}

	return 0;
}
