#pragma once

#include "vehicle.h"

class Trailer : public Vehicle {
public:
    Trailer(const std::string& name);
    void start() override;
    void stop() override;
public:
    bool is_attached = false;
};
