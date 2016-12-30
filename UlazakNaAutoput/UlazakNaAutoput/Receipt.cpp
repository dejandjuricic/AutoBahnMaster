#include "Receipt.h"

Receipt::Receipt(unsigned long id, time_t time) noexcept : idofVehicle(id), timeofEntry(time) {}
unsigned long Receipt::getID() const noexcept { return idofVehicle; }
time_t Receipt::getTime() const noexcept { return timeofEntry; }