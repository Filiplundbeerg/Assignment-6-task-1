// Assignment 6 task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Header.h"

int main()
{
	Node* n0 = new Node(0);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	DoublyLinkedList list;

	list.Add(n0, 0);
	//list.Add(&n1, 10); //should be a false or -1 (error/invalid) 
	//list.Add(nullptr, 1); //should be a false or -1 (error/invalid) 
	list.Add(n1, 1);
	//list.Remove(3); //should be a false or -1 (error/invalid) 
	list.Add(n2, 2);
	//list.Display_forward();
	list.Add(n3, 1);
	int a = list.Search(n3);
	int bv = list.Search(n2);
	//list.Display_backward();
	list.Display_forward();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
