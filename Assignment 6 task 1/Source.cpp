#include "Header.h"

int Node::getData()
{
	return this->data;
}

void Node::setData(int p)
{
	this->data = p;
}

Node::Node(int p)
{
	this->data = p;
	this->nextNode = nullptr;
	this->prevNode = nullptr;
}

bool DoublyLinkedList::Add(Node* insert, int pos)
{
	if (insert == nullptr)
		return false;
	else if (pos > this->length)
		return false;
	else
	{
		this->length += 1;
		if (pos == 0 && length == 1)
		{
			head = insert;
			insert->nextNode = NodeAt(pos+1);
			insert->prevNode = nullptr;
		}
		else if (pos == length-1 )
		{ 
			foot = insert;
			insert->nextNode = nullptr;
			insert->prevNode = NodeAt(pos - 1);
			insert->prevNode->nextNode = insert;
		}
		else
		{
			insert->nextNode = NodeAt(pos);
			insert->nextNode->prevNode = insert;
			insert->prevNode = NodeAt(pos - 1);			
			insert->prevNode->nextNode = insert;
		}
		return true;
	}
}

bool DoublyLinkedList::Remove(int pos)
{
	if (pos > length)
		return false;
	else if (pos < 0)
		return false;
	else if (pos == length-1)
	{
		NodeAt(pos - 1)->nextNode = nullptr;
		foot = NodeAt(pos - 1);
		delete NodeAt(pos);
		return true;
	}
	else if (pos == 0)
	{
		NodeAt(pos + 1)->prevNode = nullptr;
		head = NodeAt(pos + 1);
		delete NodeAt(pos);
		return true;
	}
	else
	{
		Node* a = NodeAt(pos + 1);
		a->prevNode = NodeAt(pos - 1);
		NodeAt(pos - 1)->nextNode = NodeAt(pos + 1);
		delete NodeAt(pos);
		return true;
	}
}
bool DoublyLinkedList::Replace(Node* oldN, Node* newN)
{
	if (oldN == nullptr && newN == nullptr)
	{
		std::cout << "Argument 2 and argument 1 are nullpointers.";
		return false;
	}
	else if (oldN == nullptr)
	{
		std::cout << "Argument 2 is a nullpointer.";
		return false;
	}
	else if (newN == nullptr)
	{
		std::cout << "Argument 1 is a nullpointer.";
		return false;
	}
	if (this->Search(oldN) == -1)
	{
		std::cout << "Old node is not in list.";
		return false;
	}
	else
	{
		newN->nextNode = oldN->nextNode;
		newN->prevNode = oldN->prevNode;
		newN->prevNode->nextNode = newN;
		return true;
	}
}
int DoublyLinkedList::Search(Node* data)
{
	if (data != nullptr) 
	{
		int count = 0;
		Node* currentNode = head;
		do
		{
			if (currentNode == data)
				return count;
			count++;
			currentNode = currentNode->nextNode;
		} while ((currentNode != nullptr));
		return -1;
	}
	else
		return -1;
}
Node* DoublyLinkedList::NodeAt(int pos)
{
	if (pos > length)
	{
		return nullptr;
	}
	else if (pos < 0)
	{
		return nullptr;
	}
	else
	{
		Node* currentNode = head;
		int count = 0;
		do
		{
			if (count == pos)
				return currentNode;
			count++;
			currentNode = currentNode->nextNode;
		} while ((currentNode != nullptr));
		
		
	return currentNode;
	}
}
void DoublyLinkedList::Display_forward()
{
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		std::cout << currentNode->getData();
		currentNode = currentNode->nextNode;
	}
	delete currentNode;
}
void DoublyLinkedList::Display_backward()
{
	Node* currentNode = foot;
	while (currentNode != nullptr)
	{
		std::cout << currentNode->getData();
		currentNode = currentNode->prevNode;
	}
}
int DoublyLinkedList::size()
{
	return length;
}
