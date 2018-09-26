#include "stdafx.h"
#include "LineEditor.h"

LineEditor::LineEditor()
{
	LinkedList document;
}

void LineEditor::start() {
	bool t = true;

	while (t)
	{

		std::string input = "";
		getline(std::cin, input);


		std::string temp = input.substr(0, input.find(" "));

		if (temp.compare("insertEnd") == 0)
		{
			int start = input.find("\"") + 1;
			int length = input.rfind("\"") - 1 - input.find("\"");

			temp = input.substr(start, length);


			document.addNode(temp);
		}
		else if (temp.compare("insert") == 0)
		{
			temp = input.substr(input.find(" ") + 1);
			std::string temp2 = temp.substr(0, temp.find(" "));
			int index = stoi(temp2);            //converts string to int.

			int start = input.find("\"") + 1;
			int length = input.rfind("\"") - 1 - input.find("\"");

			temp = input.substr(start, length);


			document.addNode(index - 1, temp);

		}

		else if (temp.compare("edit") == 0)
		{
			temp = input.substr(input.find(" ") + 1);
			std::string temp2 = temp.substr(0, temp.find(" "));
			int index = stoi(temp2);            //converts string to int.

			int start = input.find("\"") + 1;
			int length = input.rfind("\"") - 1 - input.find("\"");

			temp = input.substr(start, length);

			document.editNode(index - 1, temp);

		}
		else if (temp.compare("print") == 0)
		{
			document.printList();

		}
		else if (temp.compare("search") == 0)
		{
			int start = input.find("\"") + 1;
			int length = input.rfind("\"") - 1 - input.find("\"");

			temp = input.substr(start, length);

			document.search(temp);

		}
		else if (temp.compare("delete") == 0)
		{
			temp = input.substr(input.find(" ") + 1);
			int index = stoi(temp);            //converts string to int.
			document.deleteNode(index - 1);
		}

		else if (temp.compare("quit") == 0)
		{
			t = false;
		}
		else
			std::cout << "Invalid command.\n\n";

	}
}
