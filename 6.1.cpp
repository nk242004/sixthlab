#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    const int SIZE = 10;

    int arr[SIZE] = {29, 40, 42, 41, 97, 80, 88, 94, 25};

    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << ' ';

    cout << endl;

    for (int i = 0; i < SIZE; i++)
        for (int j = SIZE - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }

    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << ' ';

    cout << endl;

	return 0;
}
