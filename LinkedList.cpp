
#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}

void LinkedList::search(std::string value)
{
	nodePointer p = head;
	int count = 1;
	bool found = false;
	while (p != NULL)
	{
		if (p->data.find(value) != std::string::npos)
		{
			std::cout << count << " " << p->data << "\n";
			found = true;
		}
		p = p->next;
		count++;
	}

	if (!found)
		std::cout << "not found\n";


}


void LinkedList::addNode(std::string value)
{
	if (value.size() > 80)
	{
		//std::cout << "Text too long. Please keep below 80 characters.";
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
		return;
	}

	nodePointer newNode = new nodeObject;
	newNode->data = value;
	bool check = true;

	if (index == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		nodePointer track = head;

		for (int i = 0; i < index - 1; i++)
		{
			if (track != NULL)
				track = track->next;
			else
			{
				check = false;
				i = index;
			}
		}
		if (track != NULL &&check)
		{
			newNode->next = track->next;
			track->next = newNode;
		}
	}

}
void LinkedList::editNode(int index, std::string value)
{
	if (index < 0)
	{
		return;
	}
	else if (head == NULL)
	{
		return;
	}


	nodePointer p = head;
	for (int i = 0; i < index; i++)
	{
		if (p->next != NULL)
			p = p->next;
		else
		{
			return;
		}
	}

	p->data = value;
}

void LinkedList::deleteNode(int index)
{
	if (head == NULL)
	{
		return;
	}
	if (index < 0)
	{
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
		std::cout << line << " " << p->data << "\n";
		p = p->next;
		line++;
	}


}

