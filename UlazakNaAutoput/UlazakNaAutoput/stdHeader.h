#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <tuple>
#include <string>
#include <initializer_list>
#include <conio.h>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <limits>

//standard functions
void clearScreen() noexcept;
int longestStr(std::vector<std::string>&) noexcept;
int doesUsernameExist(std::fstream&, std::string&) noexcept;
std::string maskedInput() noexcept;
bool isAlphaNumeric(char) noexcept;

//standard values

/*ASCII codes*/
const unsigned char topLeft = 0xC9;
const unsigned char topRight = 0xBB;
const unsigned char bottomRight = 0xBC;
const unsigned char bottomLeft = 0xC8;
const unsigned char vert = 0xBA;
const unsigned char hor = 0xCD;
const unsigned char vertL = 0xCC;
const unsigned char vertR = 0xB9;

/*Keystroke codes*/
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

//standard exceptions
class userException : virtual public std::exception
{
	std::vector<std::string> message;
public:
	virtual const char* what() const override;
	std::vector<std::string> list() const;

	userException(std::initializer_list<std::string>);
};

//Commonly used structs

struct ToWrite
{
	char userName[26];
	char password[65];//Size is one bigger to accomodate string terminator
};