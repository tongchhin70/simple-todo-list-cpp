#include <iostream>
#include <string>
#include <list>
#include <ctime>

class todoItem
{
private:
	int id;
	std::string description;
	bool completed;
public:
	todoItem() : id(0), description(""), completed(false){}
	~todoItem() = default;

	int getId()
	{
		return id;
	}
	std::string getDescription()
	{
		return description;
	}
	bool isCompleted()
	{
		return completed;
	}
	void setCompleted(bool val)
	{
		completed = val;
	}
	bool create(std::string new_description)
	{
		id = rand() % 100 + 1;
		description = new_description;
		return true;
	}
};
int main()
{
	char choice;
	int input_id;
	std::string input_description;
	std::string version = "v0.0.1";
	std::list<todoItem> todoItems;
	std::list<todoItem>::iterator it;

	srand(time(NULL));
	todoItems.clear();

	//todoItem test;
	//test.create("This is a test");
	//todoItems.push_back(test);

	while (1)
	{
		system("cls");

		std::cout << "TO-DO List maker - Version " << version << std::endl;
		std::cout << std::endl << std::endl;


		for (it = todoItems.begin(); it != todoItems.end(); it++)
		{
			std::string completed = it->isCompleted() ? "done" : "not done";
			std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << std::endl;
		}

		if (todoItems.empty())
		{
			std::cout << "add your first item" << std::endl;
			std::cout << std::endl << std::endl;
		}

		std::cout << "A. Add a new TODO" << std::endl;
		std::cout << "B. Complete a TODO" << std::endl;
		std::cout << "C. Quit" << std::endl;
		
		std::cout << "Choice: ";
		std::cin >> choice;

		if (choice == 'C')
		{
			std::cout << "BYE!" << std::endl;
			break;

		}
		else if(choice == 'A')
		{
			std::cout << "Add your new Description: "; 
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, input_description);

			todoItem newitem;
			newitem.create(input_description);
			todoItems.push_back(newitem);
		}
		else if (choice == 'B')
		{
			std::cout << "Enter TODO item ID: ";
			std::cin >> input_id;

			for (it = todoItems.begin(); it != todoItems.end(); it++)
			{
				if (input_id == it->getId())
				{
					it->setCompleted(true);
					break;
				}
			}
		}
	}

	system("pause");

}