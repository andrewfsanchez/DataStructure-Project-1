#ifndef linkedList
#define linkedList

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

class LinkedList
{
private:
	struct nodeObject {
		std::string data;
		nodeObject *next;
	};
	typedef struct nodeObject * nodePointer;
	nodePointer head;
	nodePointer tail;

public:
	LinkedList();
	void search(std::string value);
	void addNode(std::string value);
	void addNode(int index, std::string value);
	void editNode(int index, std::string value);
	void deleteNode(int index);
	void printList();
};


#endif
