#pragma once

#include "trailer.h"

class RefrigeratedTrailer : public Trailer {
public:
    RefrigeratedTrailer(const std::string& name);
    void start() override;
    void stop() override;
};
