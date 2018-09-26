#ifndef LINE_EDITOR
#define LINE_EDITOR

#include "LinkedList.h"

class LineEditor
{
private:
	LinkedList document;

public:
	LineEditor();
	void start();
};

#endif