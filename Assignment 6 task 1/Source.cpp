#include "Header.h"

int Node::getPos()
{
	return this->posNode;
}


int Node::getData()
{
	return this->data;
}

void Node::setPos(int p)
{
	this->posNode = p;
}

void Node::setData(int p)
{
	this->data = p;
}

Node::Node(int p)
{
	this->posNode = p;
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
		insert->setPos(pos);
		insert->setData(pos);
		if (insert->getPos() == 0 && length == 1)
		{
			head = insert;
			insert->nextNode = nullptr;
			insert->prevNode = nullptr;
		}
		else if (insert->getPos() == length-1 )
		{ 
			foot = insert;
			insert->nextNode = nullptr;
			insert->prevNode = NodeAt(pos - 1);
		}
		else
		{
			insert->nextNode = NodeAt(pos + 1);
			insert->prevNode = NodeAt(pos - 1);			
			NodeAt(pos + 1)->prevNode = insert;
			NodeAt(pos - 1)->nextNode = insert;

		}

		/*
		insert->setPos(pos);
		if (insert->getPos() == 0)
		{
			insert->prevNode = nullptr;
			head = insert;
			if (length > pos + 1)
			this->NodeAt(pos + 1)->prevNode = head;
		}
		else
		{
			insert->prevNode = this->NodeAt(pos - 1);
			insert->nextNode = this->NodeAt(pos + 1);
			if(length>pos+1)
				this->NodeAt(pos + 1)->prevNode = insert;
			if(0<=pos)
				this->NodeAt(pos - 1)->nextNode = insert;
		}


		if (insert->getPos() == length-1)
		{
			insert->nextNode = nullptr;
			foot = insert;
			if(length>1)
				this->NodeAt(pos - 1)->nextNode = insert;
		}
		else
			insert->nextNode = this->NodeAt(pos + 1);*/
		return true;
	}
}

bool DoublyLinkedList::Remove(int pos)
{
	return true;
}
bool DoublyLinkedList::Replace(Node* oldN, Node* newN)
{
	return true;
}
int DoublyLinkedList::Search(Node* data)
{
	return data->getPos();
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
		do
		{
			if (currentNode->getPos() == pos || currentNode == head && length == 2)
			{
				return currentNode;
			}
			currentNode = currentNode->nextNode;
		} while ((currentNode != nullptr))  /*(currentNode->getPos() == pos - 1))*/;
		
		
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
