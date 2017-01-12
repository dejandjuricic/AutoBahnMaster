#pragma once
#include "stdHeader.h"

namespace ABM
{
	class Menu
	{
		std::vector<std::string> menuItems;
	public:
		Menu(std::initializer_list<std::string>) noexcept(false);
		int call();
	};
}