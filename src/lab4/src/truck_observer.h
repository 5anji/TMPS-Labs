#pragma once
#include "trailer_strategy.h"

#include <fmt/format.h>

// Observer Pattern
class TruckObserver {
public:
    virtual void update(const TrailerStrategy* trailer) const = 0;
    virtual ~TruckObserver() = default;
};

class TruckDriverObserver : public TruckObserver {
public:
    void update(const TrailerStrategy* trailer) const override {
        fmt::print("Truck driver received update: ");
        trailer->transport();
    }
};
