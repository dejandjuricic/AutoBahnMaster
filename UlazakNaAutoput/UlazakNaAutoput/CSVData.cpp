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

	for (int i = 0; i < data.size(); i++)//Iterates through vector and adds to CSV
	{
		if (i == data.size() - 1)
			file << data[i];
		else
			file << data[i] << ", ";
	}
	file << "\n";//Adds endline character to seperate values

	file.close();
	return ++numofEntries;
}

std::vector<std::string> CSVData::operator[](int index) noexcept(false)
{
	if (index > numofEntries) throw std::out_of_range("Index out of range");
	std::string line;

	file = std::fstream(name);//Opens file
	std::getline(file, line);

	for (int i = 0; i < index ; i++)
		std::getline(file, line);

	std::vector<std::string> result;

	std::istringstream tempStream(line);
	std::string toWrite;

	while (std::getline(tempStream, toWrite, ','))
	{
		tempStream >> std::ws;//Skips any leading whitespace
		result.push_back(toWrite);
	}

	return result;
}

int CSVData::size() const noexcept
{
	return numofEntries;
}
