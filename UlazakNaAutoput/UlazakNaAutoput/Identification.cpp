#include "Identification.h"

Identification::Identification(const char* fileName) noexcept(false)
{
	std::streampos size; //Size of file
	char* memblock; //Saves the content of the file into memblock

	std::fstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);//Loading fileName in binary mode and setting the position pointer at the end of the file to obtain file size
	if (!file.is_open()) throw std::ios::badbit;

	size = file.tellg(); //Returns position of current character which is at the end, thus obtaining file size
	memblock = new char[size];//Allocating memory block to hold data from file

	file.seekg(0, std::ios::beg);//Sets the current character poitner ot the beggining
	file.read(memblock, size);//Copies file content into memblock
	file.close();//Finishes operations with file

	

	delete memblock;
}
