# Topic: *SOLID Principles*

## Author: *Gitlan Gabriel, FAF-213*

------

## Objectives

&ensp; &ensp; __1. Study and understand the SOLID Principles.__

&ensp; &ensp; __2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.__

&ensp; &ensp;__3. Create a sample project that respects SOLID Principles.__

## Theory

&ensp; &ensp; SOLID is a set of five object-oriented design principles intended to make software designs more maintainable, flexible, and easy to understand. The acronym stands for Single Responsibility Principle, Open-Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, and Dependency Inversion Principle. Each principle addresses a specific aspect of software design, such as the organization of responsibilities, the handling of dependencies, and the design of interfaces. By following these principles, software developers can create more modular, testable, and reusable code that is easier to modify and extend over time. These principles are widely accepted and adopted in the software development community and can be applied to any object-oriented programming language.

## Implementation

__Single Responsibility Principle (SRP):__ As principle was respacted in each created class, as it must be.

__Open-Closed Principle (OCP):__ Let's take a look into code:

We have:

```c++
class Trailer : public Vehicle {
public:
    Trailer(const std::string& name);
    void start() override;
    void stop() override;
public:
    bool is_attached = false;
};

```

And also:

```c++
class RefrigeratedTrailer : public Trailer {
public:
    RefrigeratedTrailer(const std::string& name);
    void start() override;
    void stop() override;
};
```

That extends functionallity, without changing the base class.

__Liskov Substitution Principle (LSP):__ Both classes described above also respects this principle. They are interchangeble.

__Interface Segregation Principle (ISP):__ As a blueprint for another classes we have:

```c++
class Vehicle {
public:
    Vehicle(const std::string& name);
    virtual void start() = 0;
    virtual void stop() = 0;
    std::string get_name();
    bool is_started();

protected:
    std::string name;
    bool started = false;
};
```

__Dependency Inversion Principle (DIP):__ it is used by injecting constructor into child classes. There is how I used it:

```c++
Trailer::Trailer(const std::string& name)
        : Vehicle(name) {}
        // ^^^ here
void Trailer::start() {
        fmt::println("Trailer {} is starting.", name);
}
void Trailer::stop() {
    if (started)
        fmt::println("Trailer {} is stopping.", name);
    started = false;
}
```

It's called inside initializer list as is suggetested by C++ conventions.

## Conclusion

In conclusion, we've applied the SOLID principles to a C++ program with a theme involving trailers and trucks. By adhering to these principles, we've created a flexible and maintainable codebase where each class has a single responsibility (SRP), the code is open for extension but closed for modification (OCP), derived classes can be used interchangeably with their base classes (LSP), clients are not forced to depend on unnecessary interfaces (ISP), and abstractions are used to promote flexible design (DIP). This example demonstrates how SOLID principles can lead to well-structured and adaptable code in the context of a simple fleet management system.
