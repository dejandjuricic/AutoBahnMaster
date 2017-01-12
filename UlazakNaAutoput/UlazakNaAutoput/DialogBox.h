#pragma once
#include "stdHeader.h"

namespace ABM
{
	class DialogBox
	{
		int longestString;
		void draw(std::vector<std::string>) noexcept;
		void drawLine() const noexcept;
	public:
		DialogBox(std::string) noexcept;
		DialogBox(std::vector<std::string>) noexcept;
	};
}