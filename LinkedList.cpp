
#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

void LinkedList::search(std::string value)
{
	nodePointer p= head;
	int count = 1;
	while (p != NULL)
	{
		if (p->data.find(value)!=value.npos)
		{
			std::cout <<count<< " "<< p->data<<"\n";
			return;
		}
		p = p->next;
		count++;
	}

	std::cout << "not found\n";

	
}


void LinkedList::addNode(std::string value)
{
	if (value.size() > 80)
	{
		std::cout << "Text too long. Please keep below 80 characters.";
		return;
	}

	nodePointer newTail = new nodeObject;
	newTail->data = value;
	newTail->next = NULL;

	if (head != NULL) //if LinkedList has element(s).
	{
		tail->next = newTail;
		tail = newTail;
	}
	else //if LinkedList is empty
	{
		tail = newTail;
		head = newTail;
	}
}

void LinkedList::addNode(int index, std::string value)
{
	if (value.size() > 80)
	{
		std::cout << "Text too long. Please keep below 80 characters.";
		return;
	}

	nodePointer newNode = new nodeObject;
	newNode->data = value;

	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else 
	{
		nodePointer track = head;

		for (int i = 0; i < index-1; i++)
		{
			if (track->next != NULL)
				track = track->next;
			else
				i = index;
		}

		newNode->next = track->next;
		track->next = newNode;
	}

}
void LinkedList::editNode(int index, std::string value)
{
	if (index < 0)
	{
		std::cout << "Invalid line.\n";
		return;
	}
	else if(head==NULL)
	{
		std::cout << "No lines to edit.\n";
		return;
	}


	nodePointer p = head;
	for (int i = 0; i < index; i++)
	{
		if (p->next != NULL)
			p = p->next;
		else
		{
			std::cout << "You have to add this line before being able to edit it.\n";
			return;
		}
	}

	p->data = value;
}

void LinkedList::deleteNode(int index)
{
	if (head == NULL)
	{
		std::cout << "No lines to delete\n";
		return;
	}
	if (index < 0)
	{
		std::cout << "Invalind line\n";
		return;
		
	}
	if (index == 0)
	{
		nodePointer p = head->next;
		delete head;
		head = p;
	}
	else 
	{
		nodePointer p;
		nodePointer q;
		p = head;
		q = head;

		for (int i = 0; i < index; i++)
		{
			if (q->next != NULL)
			{
				p = q;
				q = q->next;
			}
			else
			{
				return;
			}
		}

		p->next = q->next;
		delete q; //Valgrind on ubuntu
	

	}

}

void LinkedList::printList()
{
	nodePointer p = head;
	int line = 1;
	while (p != NULL)
	{
		std::cout << line<< " "<<p->data << "\n";
		p = p->next;
		line++;
	}
	std::cout << "\n";

}
