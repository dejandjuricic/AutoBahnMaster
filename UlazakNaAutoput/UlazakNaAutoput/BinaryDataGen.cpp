#include "BinaryDataGen.h"

namespace ABM
{
	BinaryDataGen::BinaryDataGen(const char* fileName) noexcept(false)
	{
		struct
		{
			char userName[26];
			char password[65];//Size is one bigger to accomodate string terminator
		}toWrite;

		std::ofstream file(fileName, std::ios::out | std::ios::binary | std::ios::app);//Opening file append, binary mode

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

				std::cout << "Password: ";
				std::string password;

				std::getline(std::cin, password);//Get entire line

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