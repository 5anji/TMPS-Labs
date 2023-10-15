#pragma once

#include "trailers/trailer.h"
#include "trucks/truck.h"

#include <fmt/format.h>
#include <memory>

// Adapter: TruckWithTrailer (Adapter for combining Truck and Trailer)
class TruckWithTrailer : public Truck {
public:
    TruckWithTrailer(std::shared_ptr<Truck> truck, std::shared_ptr<Trailer> trailer)
            : truck(std::move(truck))
            , trailer(std::move(trailer)) {}

    void deliver() const override {
        truck->deliver();
        trailer->attach();
        fmt::println("Delivering goods with a Truck and Trailer");
    }

private:
    std::shared_ptr<Truck> truck;
    std::shared_ptr<Trailer> trailer;
};
