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
			std::string password = maskedInput();
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

