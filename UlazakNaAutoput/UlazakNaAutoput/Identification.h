#pragma once
#include "stdHeader.h"
#include "sha256.h"

class Identification
{
	std::vector<std::tuple<unsigned long, std::string>> userList;
public:
	Identification(const char*) noexcept(false);
	Identification() = delete;
	Identification(const Identification&) = delete;
	Identification(Identification&&) = delete;
};