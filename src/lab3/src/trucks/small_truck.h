#pragma once

#include "truck.h"

#include <fmt/format.h>

// ConcreteComponent: SmallTruck
class SmallTruck : public Truck {
public:
    void deliver() const override {
        fmt::println("Delivering goods with a Small Truck");
    }
};
