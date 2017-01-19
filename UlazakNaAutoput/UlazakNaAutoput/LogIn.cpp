#include "LogIn.h"

ABM::LogIn::LogIn(const char * fileName) noexcept(false)
{
	std::fstream file(fileName,std::ios::in | std::ios::out | std::ios::binary);//Opening file used for comapring usernames and passwords

	if (!file.is_open()) //Checks if the file is open, if it's not, creates a new file
	{
		file.open(fileName, std::ios::out);
	}

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

			int exists = doesUsernameExist(file, userName);

			if ( exists== -1) { throwFlag = 1; } //Checks if the username exists
			else
			{
				file.read(tempPassword, 65);
			}

			std::cout << "Password: ";
			std::string password;

			std::getline(std::cin, password);//Get entire line

			password = sha256(password);//Using sha256 algortihm to hash the password

			if (password != tempPassword) { throwFlag = 1; } //Checks if the passwords match

			if (throwFlag) { throw RegistrationError({"Username and password do not match."}); } 

			flag = false;
			
		}
		catch (RegistrationError& e)
		{
			DialogBox(e.list());
		}
	}

	file.close();
}

