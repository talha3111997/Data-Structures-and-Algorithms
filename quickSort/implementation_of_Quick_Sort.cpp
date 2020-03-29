#include "stdafx.h"
#include <iostream>
#include <functional>
#include<time.h>
using namespace std;

class QS {
public:
	int partition(int A[], int low, int high) {
		int pivot = A[high];
		int i = (low - 1);
		
		
			for (int j = low; j <= high - 1; j++) {
				if (A[j] <= pivot) { 
					i++;
					swap(&A[i],&A[j]);
				
			    }

		    }
			swap(&A[i + 1], &A[high]);
			return (i+1);
	}

	void quickSort(int A[], int low , int high) {
		if (high > low) {
			int pi = partition(A, low, high);
			quickSort(A, low, pi - 1);
			quickSort(A, pi +1 , high);
		
		}

	}
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
	void printArray(int A[], int size) {
		
		for (int i = 0; i < size; i++) {
			cout << A[i]<< endl;

		}
	}
	void initialize(int a[], int n) {
		for (int i = 0; i < n; i++) {
			a[i] = (rand() % 100) + 1;

		}

	}
	void equalize(int a[], int b[], int size) {
		for (int i = 0; i < size; i++) {
			b[i] = a[i];
		}
	}
	void desc(int a[], int size) {
		int key = 0, j = 0;
		for (int i = 1; i < size; i++) {
			key = a[i];
			j = i - 1;
			while (j >= 0 and a[j] < key) {
				a[j + 1] = a[j];
				j--;
				a[j + 1] = key;
			}
		}

	}



};

int main()
{
	int n = 0;

	cout << " Welcome to Quick Sort \n Enter the size of the random array or enter any negative value to exit : ";

	cin >> n;
	while (n >= 0) {
		
	int *A = new int[n];
	int *temp = new int[n];
	QS obj;
	obj.initialize(A, n);
	obj.equalize(A, temp, n);
	obj.desc(temp, n);
	clock_t startTime = clock();
	obj.quickSort(temp, 0, n - 1);
	cout << "\ntime of Quick sort algorithm having array size " << n << " in descending order is : " << double(clock() - startTime) / CLOCKS_PER_SEC;
	//cout << "\nSorted array : \n";
	//obj.printArray(temp, n);
	cout << "\n Welcome to Quick Sort \n Enter the size of the random array or enter any negative value to exit : ";

	cin >> n;
}
	//system("pause");
    return 0;
}


