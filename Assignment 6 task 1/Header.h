#pragma once
#include <iostream>

class Node
{
private:
	int posNode;
	int data;
public:
	Node* nextNode;
	Node* prevNode;
	int getPos();
	int getData();
	void setPos(int p);
	void setData(int dat);
	Node(int p);
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* foot;
public:
	int length = 0;
	bool Add(Node* data, int pos);
	bool Remove(int pos);
	bool Replace(Node* oldN, Node* newN);
	int Search(Node* data);
	Node* NodeAt(int pos);
	void Display_forward();
	void Display_backward();
	int size();
};