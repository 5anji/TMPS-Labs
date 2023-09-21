#pragma once

#include "vehicle.h"

#include <fmt/format.h>
#include <vector>

class FleetManager {
public:
    FleetManager() {}

    void add_vehicle(Vehicle* vehicle) {
        fleet.push_back(vehicle);
    }

    void operate_fleet() {
        for (const auto& vehicle : fleet) {
            vehicle->start();
        }
        fmt::println("");
        for (const auto& vehicle : fleet) {
            vehicle->stop();
        }
    }

private:
    std::vector<Vehicle*> fleet;
};
