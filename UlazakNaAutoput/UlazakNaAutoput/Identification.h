#pragma once
#include "stdHeader.h"
#include "sha256.h"

namespace ABM
{
	class Identification
	{
		std::vector<std::tuple<unsigned long, std::string>> userList;
	public:
		Identification(const char*) noexcept(false);
		Identification() = delete;
		Identification(const Identification&) = delete;
		Identification(Identification&&) = delete;
		void write()const noexcept;
		bool operator==(std::tuple<unsigned long, std::string>)const noexcept;
	};
}