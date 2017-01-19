#include "stdHeader.h"

void clearScreen() noexcept
{
#ifdef _WIN32 //Check if OS is Windows
	std::system("cls");
#else //Else assume UNIX based OS
	std::system("clear");
#endif
}

int longestStr(std::vector<std::string>& vec) noexcept
{
	int result = 0;
	for (auto i : vec)
		if (i.length() > result) result = i.length();
	return result;
}

int doesUsernameExist(std::fstream & file, std::string& userName) noexcept
{
	char tempUsername[26];
	char tempPassword[65];
	file.seekg(0);
	while (file.read(tempUsername, 26)) //Checking if the username already exists
	{
		if (userName == tempUsername) return file.tellg();
		file.read(tempPassword, 65); //Skips the password and moves on to the next username
	}
	file.clear(); // Clears the EOF flag from the file
	file.seekg(0, std::ios::end); //Moves file cursor to the end

	return -1;
}

std::string maskedInput() noexcept //Masking input, used mostly for password input
{
	std::string input;
	char c = 0;

	while (c != '\r' && c != '\n') //While the character is not end of line or carriage return do
	{
		c = _getch();//Get character from console
		switch (c)
		{
		case KEY_BACKSPACE://If it is backspace go back one character, print an empty one over the old one and go one back again
			if (input.length())//Dont delete * if there are no present
			{
				std::cout << '\b';
				std::cout << ' ';
				std::cout << '\b';
				input.pop_back();//Removes last character form string
			}
			break;
		default:
			if (c>=32 && c<=126)//Chekcs if character is a valid password character
			{
				std::cout << '*';//Mask every input with *
				input += c;//Add the real input to password
			}
			break;
		}
	}

	return input;
}

bool isAlphaNumeric(char c) noexcept
{
	return (c >= 48 && c <= 57)||(c >= 65 && c <= 90)||(c >= 97 && c <= 122);
}



const char * userException::what() const
{
	std::string returner;

	for (auto i : message)
		returner += i + '\n';

	return returner.c_str();
}

std::vector<std::string> userException::list() const
{
	return message;
}

userException::userException(std::initializer_list<std::string> l) : message(l) {}