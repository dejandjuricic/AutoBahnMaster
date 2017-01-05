#include "Menu.h"
//Codes for keystrokes
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

void ABM::Menu::clearScreen() const noexcept
{
#ifdef _WIN32 //Check if OS is Windows
	std::system("cls");
#else //Else assume UNIX based OS
	std::system("clear");
#endif
}

ABM::Menu::Menu(std::initializer_list<std::string> list) noexcept(false) : menuItems(list) {}

int ABM::Menu::call()
{
	int currPos = 0;//Current position of selected item
	char c;//Keystroke temporary variable
	int numofItems = menuItems.size();//Get number of items

	//ASCII CODES
	char topLeft = 0xC9;
	char topRight = 0xBB;
	char bottomRight = 0xBC;
	char bottomLeft = 0xC8;
	char vert = 0xBA;
	char hor = 0xCD;

	//Finding the length of the longest string
	int longestString = 0;
	for (auto i : menuItems)
		if (i.length() > longestString) longestString = i.length();

	while (true)//Starts the menu loop
	{
		//Printing the first row
		std::cout << topLeft;
		for (int i = 0; i <= longestString + 1; i++)
			std::cout << hor;
		std::cout << topRight << std::endl;

		//Printing the items
		for (int i = 0; i < numofItems; i++)
		{
			std::cout << vert;
			if (i == currPos) std::cout << '>';//Print > on selected item
			else std::cout << ' ';

			//Print the item
			std::cout << menuItems[i];

			//Print remaining spaces
			for (int j = menuItems[i].length(); j < longestString; j++)std::cout << ' ';

			std::cout << ' ' << vert << std::endl;
		}

		//Printing the last row
		std::cout << bottomLeft;
		for (int i = 0; i <= longestString + 1; i++)
			std::cout << hor;
		std::cout << bottomRight << std::endl;

		//Detect Keystroke
		switch ((c = _getch()))
		{
		case KEY_UP:
			currPos = (currPos - 1) % numofItems;
			currPos = currPos < 0 ? numofItems + currPos : currPos;//Clamps currPos between 0 and numofItems
			break;
		case KEY_DOWN:
			currPos = (currPos + 1) % numofItems;
			break;
		case KEY_ENTER:
			clearScreen();
			return currPos;
			break;
		default:
			break;
		}
		clearScreen();
	}
	return 0;
}
