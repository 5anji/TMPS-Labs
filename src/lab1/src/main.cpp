#include "fleet.h"
#include "refrigerated_trailer.h"
#include "trailer.h"
#include "truck.h"
#include "vehicle.h"

#include <fmt/format.h>
#include <iostream>
#include <string>

/// @brief
/// Single Responsibility Principle (SRP): Each class should have a single responsibility.
///     In this case, Trailer and Truck have separate responsibilities.

/// Open-Closed Principle (OCP): Software entities (classes, modules, functions) should be open for extension but closed for modification.
///     We can add new types of trailers without modifying the existing code.

/// Liskov Substitution Principle (LSP): Subtypes must be substitutable for their base types.
///     RefrigeratedTrailer can be used interchangeably with Trailer.

/// Interface Segregation Principle (ISP): Clients should not be forced to depend on interfaces they do not use.
///     In this example, we don't need an interface because the base class Vehicle provides a common interface.

/// Dependency Inversion Principle (DIP): High-level modules should not depend on low-level modules. Both should depend on abstractions.
/// Abstractions should not depend on details. Details should depend on abstractions.
///     We are not explicitly using dependency injection here, but the base class abstraction allows for future flexibility.

int main() {
    FleetManager fleet_manager;

    Truck kamaz("KAMAZ 4310", false);
    Trailer trailer1("Sovetskii");
    // kamaz.attach(std::make_unique<Trailer>(trailer1));

    Truck scania("Scania R500", true);
    RefrigeratedTrailer trailer2("Krone Coldline");
    scania.attach(std::make_unique<RefrigeratedTrailer>(trailer2));
    kamaz.attach(std::make_unique<RefrigeratedTrailer>(trailer2));

    fleet_manager.add_vehicle(&kamaz);
    fleet_manager.add_vehicle(&trailer1);
    fleet_manager.add_vehicle(&scania);
    fleet_manager.add_vehicle(&trailer2);

    fleet_manager.operate_fleet();
    return 0;
}
