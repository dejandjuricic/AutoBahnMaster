#pragma once
#include "stdHeader.h"

namespace ABM
{
	class Menu
	{
		std::vector<std::string> menuItems;
		void clearScreen() const noexcept;
	public:
		Menu(std::initializer_list<std::string>) noexcept(false);
		int call();
	};
}