#pragma once

#include "truck.h"

#include <fmt/format.h>

// ConcreteComponent: LargeTruck
class LargeTruck : public Truck {
public:
    void deliver() const override {
        fmt::println("Delivering goods with a Large Truck");
    }
};
