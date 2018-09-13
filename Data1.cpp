// Data1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.cpp"


int main()
{
	LinkedList document;

	bool t = true;
	
	while (t)
	{
		std::cout << "Commands (do not include brackets):\ninsertEnd [\"string to insert\"]\ninsert [line to insert into] [\"string to insert\"]\ndelete [line to delete]\nedit [line to insert into] [\"string to insert\"]\nprint\nsearch [\"string to search for\"]\nquit\n\n";
		std::string input = "";
		std::getline(std::cin, input);


		std::string temp = input.substr(0, input.find(" "));

		if (temp.compare("insertEnd") == 0)
		{
			temp = input.substr(input.find(" ")+1);

			document.addNode(temp);
			std::cout << "\n";
		}
		else if (temp.compare("insert")==0)
		{
			temp = input.substr(input.find(" ") + 1);
			std::string temp2 = temp.substr(0, temp.find(" "));
			int index = std::stoi(temp2);            //converts string to int.

			temp = temp.substr(temp.find(" ") + 1);

			document.addNode(index - 1, temp);
			std::cout << "\n";
		}

		else if (temp.compare("edit") == 0)
		{
			temp = input.substr(input.find(" ") + 1);
			std::string temp2 = temp.substr(0, temp.find(" "));
			int index = std::stoi(temp2);            //converts string to int.

			temp = temp.substr(temp.find(" ") + 1);

			document.editNode(index - 1, temp);
			std::cout << "\n";
		}
		else if (temp.compare("print") == 0)
		{
			std::cout << "\n";
			document.printList();

		}
		else if (temp.compare("search") == 0) 
		{
			temp = input.substr(input.find(" ")+1);

			std::cout << "\n";
			document.search(temp);

		}
		else if (temp.compare("delete")==0)
		{
			temp = input.substr(input.find(" ") + 1);
			int index = std::stoi(temp);            //converts string to int.
			document.deleteNode(index-1);
			std::cout << "\n";
		}

		else if (temp.compare("quit") == 0)
		{
			t = false;
		}
		else
			std::cout << "Invalid command.\n\n";

	}



    return 0;
}

