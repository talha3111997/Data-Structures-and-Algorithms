LAB 11
MUHAMMAD TALHA UMAIR ALIM
220871

// Lab11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

class BinarySearchTree
{
private:
	struct tree_node {
		tree_node* left;
		tree_node* right;
		int data;
	};
	tree_node* root;
public:
	BinarySearchTree() {
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);
	void remove(int);
	void userInput() {
		int value;
		char option;
		while (1) {
			cout << "\nEnter the value to insert : ";
			cin >> value;
			insert(value);
			
			
			cout << "Press the key x to return to the menu or press any other key to insert another value.\n";
			option = _getch();
			if (option == 'x' || option == 'X') break;
		
		
		}
	}
	void welcome() {
		int user_value;
		while (true) {


			cout << "\n1. Insert new data\n"
				"2. In - Order Traversal\n"
				"3. Pre - Order Traversal\n"
				"4. Post - Order Traversal\n"
				"5. Delete an item\n"
				"6. Exit.\n";
			char option;
			option = _getch();
			switch (option) {
			case '1':
				userInput();
				break;
			case '2':
				print_inorder();
				break;
			case '3':
				print_preorder();
				break;
			case '4':
				print_postorder();
				break;
			case '5':
				cout << "Enter the value you want to remove : ";
				cin >> user_value;
				remove(user_value);
				break;

			case '6':
				break;
			default :
				cout << "\nSorry you have entered a wrong input.\n Try Again \n";
				break;
			}
			if (option == '6')break;
		}
	}
};

void BinarySearchTree::insert(int d) {

	tree_node* new_element = new tree_node;
	tree_node* parent;
	new_element->data = d;
	new_element->left = NULL;
	new_element->right = NULL;
	parent = NULL;
	if (isEmpty()) {
		root = new_element;
	}
	else {
		tree_node* current;
		current = root;
		while (current)
		{
			parent = current;
			if (new_element->data > parent->data)
				current = current->right;
			else current = current->left;
		}
		if (new_element->data > parent->data) {
			parent->right = new_element;
		}
		if (new_element->data < parent->data) {
			parent->left = new_element;
		}
	}
}

void BinarySearchTree::remove(int d) {
	//First locate the element, if the element is not found, simply generate an error message
	// Then there will be three cases in removing d. Code accordingly
	// 1. Removing a leaf node
	// 2. Removing a node with a single child
	// 3. Removing a node with 2 children, then adjust its parents and grand children links 

	// cout << "Add your code for removal of an element" << endl;
	if (root == NULL)
	{
		cout << "Sorry tree is emtpy";
		return;
	}
	else {
		tree_node* temp;
		tree_node* parent = NULL;
		tree_node* temp2 = NULL;
		temp = root;
		int found = 0;
		// If found:

		while (1) {
			parent = temp;
			if (temp->data == d)
			{
				found = 1;
				break;
			}
			else temp = temp->left;
		}
		if (found == 0) {
			while (1) {
				parent = temp;
				if (temp->data == d)
				{
					found = 1;
					break;
				}
				temp = temp->right;
			}
		}
		
		if (found == 1 && temp->data == d) {
			// Case 1: leaf
			if ( temp->left == NULL && temp->right == NULL) {
				delete temp;
				parent = NULL;
				cout << "Leaf has been removed having entered value";
				return;

			}

			// Case 2: with one child
			else if ((temp ->left == NULL && temp->right != NULL)||(temp ->left != NULL && temp->right == NULL)) {
				parent = temp;
				if (temp->left == NULL && temp->right != NULL) {
					temp = temp->right;
					parent->data = temp->data;
					delete temp;
					return;
				}
				else if (temp->left != NULL && temp->right == NULL) {
					temp = temp->left;
					parent->data = temp->data;
					delete temp;
					return;
				}
				}

			else if ((temp->left != NULL && temp->right != NULL) ) {
				temp2 = temp->right;
				while (temp2) {
					temp2 = temp2 -> left;
				}
				parent->data = temp2->data;
				delete temp2;
				return;
			}


		}
		// Case 2 : 
		



	}
}

void BinarySearchTree::print_inorder() {
	inorder(root);
}

void BinarySearchTree::inorder(tree_node* p) {
	//cout << "Add your code for inorder traversal" << endl;
	if (p != NULL) {
		if(p->left)inorder(p->left);
		cout << p->data << "\t" ;
		if(p->right)inorder(p->right);
	}
	
}

void BinarySearchTree::print_preorder() {
	preorder(root);
}

void BinarySearchTree::preorder(tree_node* p) {
	//cout << "Add your code for preorder traversal" << endl;
	if (p != NULL) {
		cout<< p->data << "\t";
		if(p->left)preorder(p->left);
		if (p->right)preorder(p->right);
	}
	
}

void BinarySearchTree::print_postorder() {
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p) {
	//cout << "Add your code for postorder traversal" << endl;
	if (p != NULL) {
		if (p->left)postorder(p->left);
		if (p->right)preorder(p->right);
		cout << p->data << "\t";

	}
	
}

int main()
{
	BinarySearchTree b;
	b.welcome();
	// Create menu here to take inputs from the user


}


//My remove function is not working properly, it needs improvement. Anyone's else effort will be appreciated.
