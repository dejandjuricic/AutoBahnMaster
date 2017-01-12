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
