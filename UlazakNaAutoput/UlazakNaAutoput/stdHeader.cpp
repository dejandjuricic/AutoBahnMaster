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

const char* LoginError::what() const
{
	return "Login Error";
}

const char * RegistrationError::what() const
{
	std::string returner;

	for (auto i : message)
		returner += i + '\n';

	return returner.c_str();
}

std::vector<std::string> RegistrationError::list() const
{
	return message;
}

RegistrationError::RegistrationError(std::initializer_list<std::string> l) : message(l) {}