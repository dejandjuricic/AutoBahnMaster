#pragma once
#include "stdHeader.h"

class CSVData //Comma seperated values data for database
{
	std::fstream file;
	std::string name;
	unsigned long numofEntries;
public:
	CSVData(const char*) noexcept(false);
	unsigned long addEntry(std::vector<std::string>) noexcept(false);
	
};