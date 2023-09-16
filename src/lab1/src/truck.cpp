#include "truck.h"

#include <fmt/format.h>

Truck::Truck(const std::string& name, bool has_wiring)
        : Vehicle(name)
        , has_wiring(has_wiring) {}

void Truck::start() {
    started = true;
    fmt::println("Truck {} is starting{}", name, (attached_trailer != nullptr) ? fmt::format(" with attached trailer {}.", attached_trailer->get_name()) : ".");
}
void Truck::stop() {
    if (started)
        fmt::println("Truck {} is stopping.", name);
    started = false;
}

void Truck::attach(std::unique_ptr<Trailer> trailer) {
    if (!(trailer->is_attached)) {
        attached_trailer = std::make_unique<Trailer>(*trailer);
        attached_trailer->is_attached = true;
    } else {
        fmt::println("Cannot attach because trailer is in use", name);
    }
}

void Truck::attach(std::unique_ptr<RefrigeratedTrailer> trailer) {
    if (!(trailer->is_attached)) {
        if (has_wiring) {
            attached_trailer = std::make_unique<RefrigeratedTrailer>(*trailer);
            attached_trailer->is_attached = true;
        } else {
            fmt::println("{} cannot attach refrigerated trailer without necessary wiring", name);
        }
    } else {
        fmt::println("Cannot attach because trailer is in use", name);
    }
}
