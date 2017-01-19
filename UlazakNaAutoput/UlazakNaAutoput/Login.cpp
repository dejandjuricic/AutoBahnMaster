#include "Login.h"

ABM::Login::Login(const char * fileName) noexcept(false)
{
	std::fstream file(fileName,std::ios::out | std::ios::in | std::ios::binary | std::ios::app);//Opening file used for comapring usernames and passwords

	if (!file.is_open()) throw std::ios::badbit;

	bool flag = true; // Flag used for checking if login input is valid

	while (flag)
	{
		try
		{
			int throwFlag = 0;
			char tempPassword[65];

			std::cout << "Username: ";
			std::string userName;
			std::getline(std::cin, userName);//Get entire line

			std::cout << "Password: ";
			std::string password;
			
			//Masking password input
			char c = 0;

			while (c != '\r' && c != '\n') //While the character is not end of line or carriage return do
			{
				c = _getch();//Get character from console
				switch (c)
				{
				case KEY_BACKSPACE://If it is backspace go back one character, print an empty one over the old one and go one back again
					if (password.length())//Dont delete * if there are no present
					{
						std::cout << '\b';
						std::cout << ' ';
						std::cout << '\b';
						password.pop_back();//Removes last character form string
					}
					break;
				default:
					if (isalnum(c))//Chekcs if character is a character
					{
						std::cout << '*';//Mask every input with *
						password += c;//Add the real input to password
					}
					break;
				}
			}

			password = sha256(password);//Using sha256 algortihm to hash the password

			int exists = doesUsernameExist(file, userName);

			if (exists == -1) { throwFlag = 1; } //Checks if the username exists
			else
			{
				file.read(tempPassword, 65);
			}

			if (password != tempPassword) { throwFlag = 1; } //Checks if the passwords match

			if (throwFlag) { throw userException({ "Username and password do not match." }); }

			flag = false;

		}
		catch (userException& e)
		{
			DialogBox(e.list());
		}
	}

	file.close();
}

