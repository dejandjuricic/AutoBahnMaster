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
					throw userException({ "Username too long." ,"Username must be between 6 and 25 characters." });
				if (userName.length() < 6)
					throw userException({ "Username too short.", "Username must be between 6 and 25 characters." });

				for (auto i : userName)//Cheking string for invalid characters
				{
					if ((!isAlphaNumeric(i)&& i!='.') || i == ' ')//Characters is not alfanumeric etc.
						throw userException({ "Invalid character in username", "Only dots and alphanumeric characters are allowed." });
				}

				if (doesUsernameExist(file, userName) != -1) throw userException({ "Username already exists, try using another one." });
				
				std::cout << "Password: ";
				std::string password = maskedInput();

				if (password.length() < 6) throw userException({ "Password too short.", "Password must have more than 6 characters." });

				password = sha256(password);//Using sha256 algortihm to hash the password

				strncpy_s(toWrite.userName, userName.c_str(), _TRUNCATE);
				strncpy_s(toWrite.password, password.c_str(), _TRUNCATE);

				file.write((char *)&toWrite, sizeof(toWrite));//Writes struct toWrite into data
				flag = false;
			}
			catch (userException& e)
			{
				DialogBox(e.list());
			}
		}

		file.close();
	}
}