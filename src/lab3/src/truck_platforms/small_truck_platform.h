#pragma once
#include "truck_platform.h"

#include <fmt/format.h>

// ConcreteImplementor: SmallTruckPlatform
class SmallTruckPlatform : public TruckPlatform {
public:
    void deliver() const override {
        fmt::println("Delivering goods on a Small Truck Platform");
    }
};
