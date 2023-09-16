#include "refrigerated_trailer.h"

#include <fmt/format.h>

RefrigeratedTrailer::RefrigeratedTrailer(const std::string& name)
        : Trailer(name) {}
void RefrigeratedTrailer::start() {
        fmt::println("Refrigerated trailer {} is starting.", name);
}
void RefrigeratedTrailer::stop() {
    if (started)
        fmt::println("Refrigerated trailer {} is stopping.", name);
    started = false;
}
