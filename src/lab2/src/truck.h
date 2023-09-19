#pragma once

#include <fmt/format.h>
#include <memory>

class Truck {
public:
    virtual void drive() {
        fmt::println("Truck is driving.");
    }

    virtual std::unique_ptr<Truck> clone() = 0;
};
