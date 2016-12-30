#pragma once
#include "stdHeader.h"

class Receipt
{
protected:
	long idofVehicle;
	time_t timeofEntry;
public:
	Receipt(unsigned long, time_t) noexcept;
	unsigned long getID() const noexcept;
	time_t getTime() const noexcept;
	const char* getATime()const noexcept;
	Receipt() = delete;
};

class ABMReceipt : public Receipt
{
	long lastId;
public:
	ABMReceipt() noexcept;
	ABMReceipt(const ABMReceipt&) = delete;
	ABMReceipt(ABMReceipt&&) = delete;
	void issue() noexcept;
	unsigned long resetID() noexcept;
};