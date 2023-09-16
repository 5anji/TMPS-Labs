#pragma once

#include "trailer.h"
#include "refrigerated_trailer.h"
#include "vehicle.h"

#include <memory>
#include <optional>
#include <string>

class Truck : public Vehicle {
public:
    Truck(const std::string& name, bool has_wiring);
    void start() override;
    void stop() override;

    void attach(std::unique_ptr<Trailer> trailer);
    void attach(std::unique_ptr<RefrigeratedTrailer> trailer);

private:
    std::unique_ptr<Trailer> attached_trailer;
    bool has_wiring;
};
