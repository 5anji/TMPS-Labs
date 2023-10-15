# Topic: *Creational Design Patterns*

## Author: *Gitlan Gabriel, FAF-213*

------

## Objectives

&ensp; &ensp; __1. Study and understand the Creational Design Patterns.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp; __3. Use some creational design patterns for object instantiation in a sample project.__

## Some Theory

&ensp; &ensp; Creational design patterns are a category of design patterns that focus on the process of object creation. They provide a way to create objects in a flexible and controlled manner, while decoupling the client code from the specifics of object creation. Creational design patterns address common problems encountered in object creation, such as how to create objects with different initialization parameters, how to create objects based on certain conditions, or how to ensure that only a single instance of an object is created. There are several creational design patterns that have their own strengths and weaknesses. Each of it is best suited for solving specific problems related to object creation. By using creational design patterns, developers can improve the flexibility, maintainability, and scalability of their code.

&ensp; &ensp; Some examples of this kind of design patterns are:

* Singleton
* Builder
* Prototype
* Object Pooling
* Factory Method
* Abstract Factory

## Implementation

In this lab I tried to implement Singleton, Builder, Prototype and Factory design patterns into a single C++ program. The theme is also about trucks and trailers, but the functionality remains very primitive, to maintain the visibility of the patterns. So:

Singleton and Factory patterns are implemented inside this class:

```c++
class TruckFactory {
public:
    TruckFactory() {}
    static std::unique_ptr<TruckFactory> get_instance() {
        if (!instance) {
            instance = std::make_unique<TruckFactory>();
        }
        return std::move(instance);
    }

    std::unique_ptr<Truck> create_truck() {
        return std::make_unique<ConcreteTruck>();
    }

private:
    static std::unique_ptr<TruckFactory> instance;
};

std::unique_ptr<TruckFactory> TruckFactory::instance = nullptr;
```

The Prototype pattern I decided to include in this class (very primitively):

```c++
class ConcreteTruck : public Truck {
public:
    ConcreteTruck() = default;

    void drive() override {
        fmt::println("Concrete Truck is driving.");
    }

    std::unique_ptr<Truck> clone() override {
        return std::make_unique<ConcreteTruck>(*this);
    }
};
```

And finally Builder pattern is the following:

```c++
class Trailer {
public:
    virtual void attach() {
        fmt::println("Trailer is attached.");
    };

    class Builder {
    protected:
        std::string name;

    public:
        Builder(const std::string& n)
                : name(n) {}

        virtual std::unique_ptr<Trailer> build() = 0;
    };
};

...

class ConcreteTrailer : public Trailer {
public:
    class ConcreteBuilder : public Builder {
    public:
        ConcreteBuilder(const std::string& n)
                : Builder(n) {}

        std::unique_ptr<Trailer> build() override {
            auto trailer = std::make_unique<ConcreteTrailer>();
            trailer->name = name;
            return trailer;
        }
    };

    void attach() override {
        fmt::println("Concrete Trailer with name {} is attached.", name);
    }

private:
    std::string name;
};
```

main():

```c++
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
```

## Conclusion

1) __Singleton Pattern__: Ensures that a class has only one instance and provides a global point of access to it. It is useful when exactly one object needs to coordinate actions across the system, like a global configuration or a central point for managing resources.

2) __Factory Pattern__: Defines an interface for creating an object but lets subclasses alter the type of objects that will be created. It is helpful when a class cannot anticipate the type of objects it needs to create or when a class wants to delegate the responsibility of object creation to its subclasses.

3) __Prototype Pattern__: Creates new objects by copying an existing object, known as the prototype. It is useful when the cost of creating an object is more expensive than copying it, or when objects have many shared characteristics and only a few differences.

4) __Builder Pattern__: Separates the construction of a complex object from its representation, allowing the same construction process to create different representations. It is beneficial when an object needs to be constructed with numerous optional components or configurations, making the creation process more flexible and readable.

Each of these creational design patterns addresses different concerns related to object creation and initialization, providing flexibility, maintainability, and reusability in software design. The choice of which pattern to use depends on the specific requirements and constraints of your application.
