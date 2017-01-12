#include "DialogBox.h"

void ABM::DialogBox::draw(std::vector<std::string> list) noexcept
{
	clearScreen();

	//Printing the first row
	std::cout << topLeft;
	for (int i = 0; i <= longestString + 1; i++)
		std::cout << hor;
	std::cout << topRight << std::endl;

	//Printing the items
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << vert;

		//Print the item
		std::cout << " " << list[i];

		//Print remaining spaces
		for (int j = list[i].length(); j < longestString; j++)std::cout << ' ';

		std::cout << ' ' << vert << std::endl;
	}

	//Printing the divider
	drawLine();

	//Printing Ok!
	std::cout << vert;
	for (int i = 0; i < longestString / 2 - 2; i++)
		std::cout << " ";
	std::cout << "> Ok!";
	for (int i = 0; i < longestString / 2 - 1 + longestString % 2; i++)
		std::cout << " ";
	std::cout << vert << std::endl;


	//Printing the last row
	std::cout << bottomLeft;
	for (int i = 0; i <= longestString + 1; i++)
		std::cout << hor;
	std::cout << bottomRight << std::endl;
}

void ABM::DialogBox::drawLine() const noexcept
{
	std::cout << vertL;
	for (int i = 0; i < longestString + 2; i++)
		std::cout << hor;
	std::cout << vertR << std::endl;
}

ABM::DialogBox::DialogBox(std::string text) noexcept
{
	longestString = text.length();
	std::vector<std::string> temp;
	temp.push_back(text);
	draw(temp);
}


ABM::DialogBox::DialogBox(std::vector<std::string> list) noexcept
{
	longestString = longestStr(list);
	draw(list);
}

