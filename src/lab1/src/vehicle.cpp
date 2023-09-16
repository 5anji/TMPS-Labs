#include "vehicle.h"

Vehicle::Vehicle(const std::string& name)
        : name(name) {}

std::string Vehicle::get_name() {
    return name;
}

bool Vehicle::is_started() {
    return started;
}
