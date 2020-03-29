
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MinHeapArray {
	//#define size 50

	int capacity = 0;
	int *harray;
	int current_size = 0;
public:
	void welcome() {
		char option = ' ';
		cout << "Welcome to Minimum Heap\n"
			"Enter the capacity of the heap : ";
		cin >> capacity;
		//capacity += 1;
		harray = new int[capacity];
		do {
			cout << "\nchose the option to do with the Min Heap\n"
				"1. Insert / Push an element \n"
				"2. Print \n"
				"3. Get the Minimum or Root value\n"
				"4. Pop\n"
				"5. Height of Tree \n"
				"6. Size of Tree \n"
				"7. Exit\n\n";

			option = _getch();

			switch (option) {
			case '1':
				push();
				break;

			case'2':

				print();
				break;


			case '3':
				cout << "The value of the root is : " << top() << endl;
				break;

			case'4':

				pop();
				break;
			case '5':
				cout << "The value of height is : " << height() << endl;
				break;

			case'6':

				cout << "The size of the tree is : " << size() << endl;
				break;
			case '7':
				break;
				break;
			default:
				cout << "Wrong Input , Try Again\n";
				break;
			}

		} while (option != 7);

	}
	int pop() {

		if (isEmpty()) {
			cout << "Sorry, Heap is empty\n";
			return 0;
		}
		/*	harray[current_size--] = NULL;
		cout << "Heap has been popped\n";*/
		if (current_size == 1) {
			int temp = harray[current_size--];
			cout << "Heap has been popped\n";
			return temp;
		}

		int temp;
		temp = harray[1];
		harray[1] = harray[current_size];
		current_size--;
		buildHeap(harray, current_size);
		cout << "Heap has been popped\n";
		return temp;
	}
	void buildHeap(int a[], int size) {
		// int *temp = new int [size];
		for (int i = 1; i <= size; i++) {
			insert(a, i);
		}
	}

	int  top() {

		return harray[1];

	}
	int parent(int child) {
		return (child) / 2;
	}
	int left(int i)
	{
		return 2 * i;
	}
	int right(int i) {
		return (2 * i) + 1;
	}
	bool isEmpty() {
		if (current_size == 0) {
			return true;
		}
		return false;
	}
	void swap(int *a, int *b) {
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	void insert(int a[], int i) {

		while (i != 0 && a[parent(i)] > a[i]) {
			swap(&a[parent(i)], &a[i]);
			i = parent(i);
		}

	}
	void push() {
		if (current_size == capacity) {
			cout << "\nSorry cannot add, heap overflows";
			return;
		}
		int input;
		cout << "Enter the element to insert:";
		cin >> input;
		current_size++;
		int i = current_size;

		harray[i] = input;

		while (i != 0 && harray[parent(i)] > harray[i]) {
			swap(&harray[parent(i)], &harray[i]);
			i = parent(i);
		}
	}
	int size() {
		return current_size;
	}

	void print() {
		cout << "The trees elements are : \n";
		for (int i = 1; i <= current_size; i++) {

			cout << harray[i] << "\t";

		}
	}
	int height() {
		int count = 0;
		int traverse = current_size;
		while (traverse > 0) {
			traverse = parent(traverse);
			count++;
		}
		return count;
	}
};


int main()
{

	MinHeapArray obj;
	obj.welcome();
	return 0;
}

