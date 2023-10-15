#pragma once
#include "../truck_platforms/truck_platform.h"
#include "truck.h"

#include <fmt/format.h>
#include <memory>

// RefinedAbstraction: ExtendedTruck (Refined Abstraction for extended Truck functionality)
class ExtendedTruck : public Truck {
public:
    ExtendedTruck(std::shared_ptr<TruckPlatform> platform)
            : platform(std::move(platform)) {}

    void deliver() const override {
        platform->deliver();
        fmt::println("Delivering goods with an Extended Truck");
    }

private:
    std::shared_ptr<TruckPlatform> platform;
};
