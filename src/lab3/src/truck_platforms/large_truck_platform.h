#pragma once

#include "truck_platform.h"

#include <fmt/format.h>

// ConcreteImplementor: LargeTruckPlatform
class LargeTruckPlatform : public TruckPlatform {
public:
    void deliver() const override {
        fmt::println("Delivering goods on a Large Truck Platform");
    }
};
