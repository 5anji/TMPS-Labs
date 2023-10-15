#pragma once
#include "truck.h"

#include <fmt/format.h>
#include <memory>

// Decorator: PremiumTruck (Decorator for adding premium features to a Truck)
class PremiumTruck : public Truck {
public:
    PremiumTruck(std::shared_ptr<Truck> truck)
            : truck(std::move(truck)) {}

    void deliver() const override {
        truck->deliver();
        fmt::println("Delivering goods with Premium features");
    }

private:
    std::shared_ptr<Truck> truck;
};
