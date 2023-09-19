#include "concrete_trailer.h"
#include "concrete_truck.h"
#include "trailer.h"
#include "truck.h"
#include "truck_factory.h"

#include <fmt/format.h>
#include <memory>

int main() {
    // Singleton
    std::unique_ptr<TruckFactory> factory = TruckFactory::get_instance();

    // Factory
    std::unique_ptr<Truck> truck = factory->create_truck();
    truck->drive();

    // Prototype
    std::unique_ptr<Truck> truck_clone = truck->clone();
    truck_clone->drive();

    // Builder
    std::unique_ptr<Trailer::Builder> builder = std::make_unique<ConcreteTrailer::ConcreteBuilder>("Krone");
    std::unique_ptr<Trailer> trailer = builder->build();
    trailer->attach();

    return 0;
}
