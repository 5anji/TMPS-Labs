#pragma once

#include "truck.h"

#include <fmt/format.h>
#include <memory>

class ConcreteTruck : public Truck {
public:
    ConcreteTruck() = default;

    void drive() override {
        fmt::println("Concrete Truck is driving.");
    }

    std::unique_ptr<Truck> clone() override {
        return std::make_unique<ConcreteTruck>(*this);
    }
};
