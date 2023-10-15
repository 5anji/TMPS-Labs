#pragma once

#include "trailer.h"

#include <fmt/format.h>

// ConcreteComponent: SmallTrailer
class SmallTrailer : public Trailer {
public:
    void attach() const override {
        fmt::println("Attached a Small Trailer");
    }
};
