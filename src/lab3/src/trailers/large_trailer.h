#pragma once

#include "trailer.h"

#include <fmt/format.h>

// ConcreteComponent: LargeTrailer
class LargeTrailer : public Trailer {
public:
    void attach() const override {
        fmt::println("Attached a Large Trailer");
    }
};
