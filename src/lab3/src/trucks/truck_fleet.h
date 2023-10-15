#pragma once
#include "truck.h"

#include <fmt/format.h>
#include <memory>
#include <vector>

// Composite: TruckFleet (Composite for managing a fleet of trucks)
class TruckFleet : public Truck {
public:
    void add_truck(std::shared_ptr<Truck> truck) {
        trucks.push_back(std::move(truck));
    }

    void deliver() const override {
        fmt::println("Delivering goods with a Truck Fleet");
        for (const auto& truck : trucks) {
            truck->deliver();
        }
    }

private:
    std::vector<std::shared_ptr<Truck>> trucks;
};
