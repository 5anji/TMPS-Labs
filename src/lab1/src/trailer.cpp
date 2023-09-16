#include "trailer.h"

#include <fmt/format.h>

Trailer::Trailer(const std::string& name)
        : Vehicle(name) {}

void Trailer::start() {
        fmt::println("Trailer {} is starting.", name);
}
void Trailer::stop() {
    if (started)
        fmt::println("Trailer {} is stopping.", name);
    started = false;
}
