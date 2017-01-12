#include "Menu.h"

ABM::Menu::Menu(std::initializer_list<std::string> list) noexcept(false) : menuItems(list) {}

int ABM::Menu::call()
{
	int currPos = 0;//Current position of selected item
	char c;//Keystroke temporary variable
	int numofItems = menuItems.size();//Get number of items

	//Finding the length of the longest string
	int longestString = longestStr(menuItems);

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
