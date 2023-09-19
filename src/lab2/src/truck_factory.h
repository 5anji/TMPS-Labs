#pragma once

#include "concrete_truck.h"
#include "truck.h"

#include <fmt/format.h>
#include <memory>

class TruckFactory {
public:
    TruckFactory() {}
    static std::unique_ptr<TruckFactory> get_instance() {
        if (!instance) {
            instance = std::make_unique<TruckFactory>();
        }
        return std::move(instance);
    }

    std::unique_ptr<Truck> create_truck() {
        return std::make_unique<ConcreteTruck>();
    }

private:
    static std::unique_ptr<TruckFactory> instance;
};

std::unique_ptr<TruckFactory> TruckFactory::instance = nullptr;
