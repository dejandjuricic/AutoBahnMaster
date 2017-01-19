#include "BinaryDataGen.h"

namespace ABM
{
	BinaryDataGen::BinaryDataGen(const char* fileName) noexcept(false)
	{
		struct ToWrite
		{
			char userName[26];
			char password[65];//Size is one bigger to accomodate string terminator
		}toWrite;

		std::fstream file(fileName,std::ios::in | std::ios::out | std::ios::binary );//Opening file in binary mode

		if (!file.is_open()) throw std::ios::badbit;

		bool flag = true;
		while (flag)
		{
			try
			{
				std::cout << "Username: ";
				std::string userName;

				std::getline(std::cin, userName);//Get entire line

				//Checking for input errors
				if (userName.length() > 25)
					throw RegistrationError({ "Username too long." ,"Username must be between 6 and 25 characters." });
				if (userName.length() < 6)
					throw RegistrationError({ "Username too short.", "Username must be between 6 and 25 characters." });

				for (auto i : userName)//Cheking string for invalid characters
				{
					if (!(isalnum(i) || i == '.') && i == ' ')//Characters is not alfanumeric etc.
						throw RegistrationError({ "Invalid character in username", "Only dots and alphanumeric characters are allowed." });
				}

				if (doesUsernameExist(file, userName) != -1) throw RegistrationError({ "Username already exists, try using another one." });
				
				std::cout << "Password: ";
				std::string password;

				//Masking password input
				char c = 0;

				while (c != '\r' && c!= '\n') //While the character is not end of line or carriage return do
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

				if (password.length() < 6)
					throw RegistrationError({ "Password too short.", "Password must have more than 6 characters." });

				password = sha256(password);//Using sha256 algortihm to hash the password

				strncpy_s(toWrite.userName, userName.c_str(), _TRUNCATE);
				strncpy_s(toWrite.password, password.c_str(), _TRUNCATE);

				file.write((char *)&toWrite, sizeof(toWrite));//Writes struct toWrite into data
				flag = false;
			}
			catch (RegistrationError& e)
			{
				DialogBox(e.list());
			}
		}

		file.close();
	}
}