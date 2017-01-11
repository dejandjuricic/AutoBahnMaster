#include "CSVData.h"

CSVData::CSVData(const char * fileName) noexcept(false) : name(fileName), numofEntries(-1)
{
	file = std::fstream(fileName); //Sets file to output mode

	if (!file.is_open()) throw std::ios::badbit;
	std::string temp;//Temporary string for getline

	while (file.good())//Gets the amount of entries in CSV file
	{
		std::getline(file, temp);
		numofEntries++;
	}

	file.close();
}

unsigned long CSVData::addEntry(std::vector<std::string> data) noexcept(false)
{
	file = std::fstream(name, std::ios::app);//Opens file in append mode

	for (auto i : data)//Iterates through vector and adds to CSV
	{
		file << i << ", ";
	}
	file << "\n";//Adds endline character to seperate values

	file.close();
	return ++numofEntries;
}
