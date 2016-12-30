#include "BinaryDataGen.h"

BinaryDataGen::BinaryDataGen(const char* fileName)
{
	std::cout << "Enter number of users: ";
	int numofUsers;
	std::cin >> numofUsers;

	struct
	{
		unsigned long idToWrite;
		std::string hashToWrite;
	}toWrite;

	std::ofstream file(fileName, std::ios::out | std::ios::binary);//Opening file in input binary mode

	if (!file.is_open()) throw std::ios::badbit;

	for (int i = 0; i < numofUsers; i++)
	{
		std::cout << "User ID (numerical): ";
		std::cin >> toWrite.idToWrite;
		std::cout << "User password: ";
		std::cin >> toWrite.hashToWrite;
		toWrite.hashToWrite = sha256(toWrite.hashToWrite);//Using sha256 algortihm to hash the password
		file.write((char *)&toWrite, sizeof(toWrite));//Writes struct toWrite into data

		file.close();
	}
	
}
