# Topic: *Structural Design Patterns*

## Author: *Gitlan Gabriel, FAF-213*

------

## Objectives

&ensp; &ensp; __1. Study and understand the Structural Design Patterns.__

&ensp; &ensp; __2. As a continuation of the previous laboratory work, think about the functionalities that your system will need to provide to the user.__

&ensp; &ensp; __3. Implement some additional functionalities, or create a new project using structural design patterns.__

## Some Theory

&ensp; &ensp; Structural design patterns are a category of design patterns that focus on the composition of classes and objects to form larger structures and systems. They provide a way to organize objects and classes in a way that is both flexible and efficient, while allowing for the reuse and modification of existing code. Structural design patterns address common problems encountered in the composition of classes and objects, such as how to create new objects that inherit functionality from existing objects, how to create objects that share functionality without duplicating code, or how to define relationships between objects in a flexible and extensible way.

&ensp; &ensp; Some examples of from this category of design patterns are:

* Adapter
* Bridge
* Composite
* Decorator
* Facade
* Flyweight
* Proxy

## Implementation

In this lab I tried to implement Adapter, Bridge, Composite and Decorator design patterns into a single C++ program. The theme is also about trucks and trailers, but the functionality remains very primitive, to maintain the visibility of the patterns. So:

Adapter pattern is implemented inside this class:

```c++
class TruckWithTrailer : public Truck {
public:
    TruckWithTrailer(std::shared_ptr<Truck> truck, std::shared_ptr<Trailer> trailer)
            : truck(std::move(truck))
            , trailer(std::move(trailer)) {}

    void deliver() const override {
        truck->deliver();
        trailer->attach();
        fmt::println("Delivering goods with a Truck and Trailer");
    }

private:
    std::shared_ptr<Truck> truck;
    std::shared_ptr<Trailer> trailer;
};
```

The Bridge pattern I decided to include in this class (very primitively):

```c++
class TruckPlatform {
public:
    virtual void deliver() const = 0;
    virtual ~TruckPlatform() = default;
};

...

// ConcreteImplementor: SmallTruckPlatform
class SmallTruckPlatform : public TruckPlatform {
public:
    void deliver() const override {
        fmt::println("Delivering goods on a Small Truck Platform");
    }
};

...

// ConcreteImplementor: LargeTruckPlatform
class LargeTruckPlatform : public TruckPlatform {
public:
    void deliver() const override {
        fmt::println("Delivering goods on a Large Truck Platform");
    }
};
```

Composite pattern is the following:

```c++
class TruckFleet : public Truck {
public:
    void add_truck(std::shared_ptr<Truck> truck) {
        trucks.push_back(std::move(truck));
    }

    void deliver() const override {
        fmt::println("Delivering goods with a Truck Fleet");
        for (const auto& truck : trucks) {
            truck->deliver();
        }
    }

private:
    std::vector<std::shared_ptr<Truck>> trucks;
};
```

And the final one. Decorator:

```c++
class PremiumTruck : public Truck {
public:
    PremiumTruck(std::shared_ptr<Truck> truck)
            : truck(std::move(truck)) {}

    void deliver() const override {
        truck->deliver();
        fmt::println("Delivering goods with Premium features");
    }

private:
    std::shared_ptr<Truck> truck;
};
```

main():

```c++
int main() {
    // Creating instances of trucks and trailers
    auto smallTruck = std::make_shared<SmallTruck>();
    auto largeTruck = std::make_shared<LargeTruck>();
    auto smallTrailer = std::make_shared<SmallTrailer>();
    auto largeTrailer = std::make_shared<LargeTrailer>();

    // Using Adapter to combine Truck and Trailer
    auto truckWithTrailer = std::make_shared<TruckWithTrailer>(smallTruck, largeTrailer);

    // Using Bridge to provide different Truck platforms
    auto smallTruckPlatform = std::make_shared<SmallTruckPlatform>();
    auto largeTruckPlatform = std::make_shared<LargeTruckPlatform>();
    auto extendedTruck = std::make_shared<ExtendedTruck>(smallTruckPlatform);

    // Using Composite to manage a fleet of trucks
    auto truckFleet = std::make_shared<TruckFleet>();
    truckFleet->add_truck(smallTruck);
    truckFleet->add_truck(largeTruck);

    // Using Decorator to add premium features to a Truck
    auto premiumTruck = std::make_shared<PremiumTruck>(largeTruck);

    // Delivering goods using various trucks and combinations
    smallTruck->deliver();
    largeTruck->deliver();
    smallTrailer->attach();
    largeTrailer->attach();
    truckWithTrailer->deliver();
    smallTruckPlatform->deliver();
    largeTruckPlatform->deliver();
    extendedTruck->deliver();
    truckFleet->deliver();
    premiumTruck->deliver();

    return 0;
}
```

Output:

```txt
Delivering goods with a Small Truck
Delivering goods with a Large Truck
Attached a Small Trailer
Attached a Large Trailer
Delivering goods with a Small Truck
Attached a Large Trailer
Delivering goods with a Truck and Trailer
Delivering goods on a Small Truck Platform
Delivering goods on a Large Truck Platform
Delivering goods on a Small Truck Platform
Delivering goods with an Extended Truck
Delivering goods with a Truck Fleet
Delivering goods with a Small Truck
Delivering goods with a Large Truck
Delivering goods with a Large Truck
Delivering goods with Premium features
```

## Conclusion

1) __Adapter Pattern__:

    __Purpose__: The Adapter pattern is used to make two incompatible interfaces work together.

    __Usage in the Program__: The TruckWithTrailer class acts as an adapter, combining a Truck and a Trailer to work together. It adapts the interface of the truck and trailer to deliver goods as a single unit.

2) __Bridge Pattern__:

    __Purpose__: The Bridge pattern separates the abstraction from its implementation, allowing both to vary independently.

    __Usage in the Program__: The TruckPlatform hierarchy serves as the bridge between the Truck abstraction and the specific truck platform implementations (SmallTruckPlatform and LargeTruckPlatform). It allows different truck platforms to be used with various trucks.

3) __Composite Pattern__:

    __Purpose__: The Composite pattern lets you compose objects into tree structures to represent part-whole hierarchies. It allows clients to treat individual objects and compositions of objects uniformly.

    __Usage in the Program__: The TruckFleet class acts as a composite, managing a collection of Truck objects. It can be used to treat individual trucks and the entire fleet uniformly for delivering goods.

4) __Decorator Pattern__:

    __Purpose__: The Decorator pattern allows behavior to be added to individual objects, either statically or dynamically, without affecting the behavior of other objects from the same class.

    __Usage in the Program__: The PremiumTruck class acts as a decorator, adding premium features to a Truck. It enhances the behavior of a truck without changing the core Truck class.

In summary, these design patterns are used to improve the structure and flexibility of the vehicle management system. The Adapter pattern adapts two different vehicle types to work together, the Bridge pattern separates the abstraction of trucks from their platforms, the Composite pattern manages a collection of trucks as a single unit, and the Decorator pattern adds premium features to vehicles without altering their base functionality. These patterns collectively enhance the program's design and maintainability.
