#define _CRT_SECURE_NO_WARNINGS
#include "Receipt.h"
time_t* temp;

Receipt::Receipt(unsigned long id, time_t time) noexcept : idofVehicle(id), timeofEntry(time) {}
unsigned long Receipt::getID() const noexcept { return idofVehicle; }
time_t Receipt::getTime() const noexcept { return timeofEntry; }

const char * Receipt::getATime() const noexcept { return ctime(&timeofEntry); }// TODO: fix secure problem (see by removing _CRT)

ABMReceipt::ABMReceipt() noexcept : Receipt(resetID(), time(temp)) {} //Constructor calls resetID because the initializer list must be executed before all else thus giving no way to set lastId to 0
void ABMReceipt::issue() noexcept { ABMReceipt::Receipt(++lastId, time(temp)); }
unsigned long ABMReceipt::resetID() noexcept { return lastId = 0; }
