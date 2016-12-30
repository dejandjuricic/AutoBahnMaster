#include "BinaryDataGen.h"

BinaryDataGen::BinaryDataGen(const char* fileName) noexcept(false)
{
	std::cout << "Enter number of users: ";
	int numofUsers;
	std::cin >> numofUsers;

	struct
	{
		unsigned long idToWrite;
		char hashToWrite[65];//Size is one bigger to accomodate string terminator
	}toWrite;

	std::ofstream file(fileName, std::ios::out | std::ios::binary);//Opening file in input binary mode

	if (!file.is_open()) throw std::ios::badbit;

	for (int i = 0; i < numofUsers; i++)
	{
		std::cout << "User ID (numerical): ";
		std::cin >> toWrite.idToWrite;
		std::cout << "User password: ";
		std::cin >> toWrite.hashToWrite;
		strncpy_s(toWrite.hashToWrite, sha256(toWrite.hashToWrite).c_str(), _TRUNCATE);//Using sha256 algortihm to hash the password
		file.write((char *)&toWrite, sizeof(toWrite));//Writes struct toWrite into data
	}

	file.close();
}
