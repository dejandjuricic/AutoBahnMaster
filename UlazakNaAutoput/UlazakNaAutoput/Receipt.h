#pragma once
#include "stdHeader.h"

class Receipt
{
	unsigned long idofVehicle;
	time_t timeofEntry;
public:
	Receipt(unsigned long, time_t) noexcept;
	unsigned long getID() const noexcept;
	time_t getTime() const noexcept;
	Receipt() = delete;
};