#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS //TODO: fix no warnings errors
#include "Identification.h"

namespace ABM
{
	Identification::Identification(const char* fileName) noexcept(false)
	{
		std::ifstream file(fileName, std::ios::binary | std::ios::ate);//Loading fileName in binary mode and setting current character position to end to get size

		if (!file.is_open()) throw std::ios::badbit;

		struct
		{
			unsigned long idToWrite;
			char hashToWrite[65];
		}toRead;

		size_t numberofRecords = file.tellg() / sizeof(toRead); //Gets amount of records by dividing total size by record size
		file.seekg(0);//Sets current character position to start of file

		for (int i = 0; i < numberofRecords; i++)
		{
			file.read((char *)&toRead, sizeof(toRead));//Reads binary data from file and puts it into toRead
			userList.push_back(std::make_tuple(toRead.idToWrite, toRead.hashToWrite));//Pushes data to vector
		}

		file.close();//Finishes operations with file

	}

	void Identification::write() const noexcept
	{
		for (auto i : userList)
			std::cout << std::get<0>(i) << " " << std::get<1>(i) << std::endl;
	}

	bool Identification::operator==(std::tuple<unsigned long, std::string>) const noexcept
	{
		//TODO: Add comparison operator
		return false;
	}



	void User::login(Identification userList, std::tuple<unsigned long, std::string> user) noexcept(false)
	{
		if (userList == user)//If user exists and password is valid save user data and time of login
		{
			userID = std::get<0>(user);
			username = std::get<1>(user);
			ctime(&timeofLogin);
		}
		else throw "Invalid username and/or password";
	}
	User::User(Identification, unsigned long, std::string) noexcept(false)
	{
		//TODO: Implement constructor
	}
}
