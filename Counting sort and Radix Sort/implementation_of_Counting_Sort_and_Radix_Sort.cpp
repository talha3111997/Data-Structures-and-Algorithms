#include "stdafx.h"
#include <iostream>
#include <queue>
#include <time.h>
#include <functional>
using namespace std;

class Sort {
public:
	void countingSort(long data[], const long n) {
		long i;
		long largest = data[0];
		long *tmp = new long[n];
		for (i = 1; i < n; i++)
			if (largest < data[i])
				largest = data[i];
		unsigned long *count = new unsigned long[largest + 1];
		for (i = 0; i <= largest; i++) {
			count[i] = 0;
		}
		for (i = 0; i < n; i++)
			count[data[i]]++;
		for (i = 1; i <= largest; i++)
			count[i] = count[i - 1] + count[i];
		for (i = n-1 ; i >=0 ; i--)
		{
			tmp[count[data[i]] - 1] = data[i];
			count[data[i]]--;
		}
		for (i = 0; i < n; i++) {
			data[i] = tmp[i];
		}
	}

	void radixSort(long data[], int n) {
		register int d, j, k, factor;
		const int radix = 10;
		const int digits = 10;
		queue<long> queues[radix];
		for (d = 0, factor = 1; d < digits; factor *= radix, d++) {
			for (j = 0; j < n; j++)
				queues[(data[j] / factor) % radix].push(data[j]);
			for (j = k = 0; j < radix; j++)
				while (!queues[j].empty()) {
					data[k++] = queues[j].front();
					queues[j].pop();
				}
		}
	}
	void printArray(long A[], int size) {

		for (int i = 0; i < size; i++) {
			cout << A[i] << endl;

		}
	}

	void initialize(long a[], int n) {
		for (int i = 0; i < n; i++) {
			a[i] = (rand() % 100) + 1;

		}
	}
		void equalize(long a[], long b[], int size) {
			for (int i = 0; i < size; i++) {
				b[i] = a[i];
			}
		}

		void asc(long a[], int size) {
			countingSort(a, size);
		}

};
int main()
{
	int n = 0;


	cout << " Welcome to Counting & Radix Sort \n Enter the size of the random array or enter any negative value to exit : ";

	cin >> n;
	while (n >= 0) {

		long *A = new long[n];
		long *temp = new long[n];
		Sort obj;
		obj.initialize(A, n);
		obj.equalize(A, temp, n);

		// Counting sort in ascending order
		obj.asc(temp, n);
		clock_t startTime = clock();
		obj.countingSort(temp, n);
		cout << "\n Time of Counting sort algorithm in ascending order having array size " << n << " is : " << double(clock() - startTime) / CLOCKS_PER_SEC;
		// Counting sort in descending order
	
		sort(temp, temp + n, greater<long>());
		clock_t startTime2 = clock();
		obj.countingSort(temp, n);
		cout << "\n Time of Counting sort algorithm in descending order having array size " << n << " is : " << double(clock() - startTime2) / CLOCKS_PER_SEC;

		
		// Radix sort in ascending order
		obj.asc(A, n);
		clock_t startTime3 = clock();
		obj.radixSort(A, n);
		cout << "\n Time of Redix sort algorithm in ascending order having array size " << n << " is : " << double(clock() - startTime3) / CLOCKS_PER_SEC;
		// Radix sort in descending order
		
		sort(A, A + n, greater<long>());
		clock_t startTime4 = clock();
		obj.radixSort(A, n);
		cout << "\n Time of Redix sort algorithm in descending order having array size " << n << " is : " << double(clock() - startTime4) / CLOCKS_PER_SEC;


		cout << "\n\n Enter the size of the random array or enter any negative value to exit : ";

		cin >> n;
	}
	//system("pause");

    return 0;
}

