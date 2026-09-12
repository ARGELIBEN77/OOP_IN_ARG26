# Unit 4 — Object Lifetime Exercises

Complete each prediction before compiling. After running the code, explain any
difference between your prediction and the observed output.

## 1. One scope

```cpp
class Marker {
    std::string name;
public:
    explicit Marker(std::string name) : name(std::move(name)) {
        std::cout << "construct " << this->name << '\n';
    }
    ~Marker() { std::cout << "destroy " << name << '\n'; }
};

int main() {
    Marker first("first");
    Marker second("second");
}
```

Write the exact output and state the rule that determines destruction order.

## 2. Nested scope

Add a nested block containing `Marker inner("inner");` between the two outer
declarations. Predict when `inner` is destroyed and explain why execution then
continues in the outer scope.

## 3. Function lifetime

Write a function that creates two local `Marker` objects. Call it between two
markers created in `main`. Trace construction and destruction across the
function call.

## 4. Composition

```cpp
class Engine {
public:
    Engine()  { std::cout << "engine starts\n"; }
    ~Engine() { std::cout << "engine stops\n"; }
};

class Car {
    Engine engine;
public:
    Car()  { std::cout << "car ready\n"; }
    ~Car() { std::cout << "car leaves\n"; }
};
```

Create one `Car`. Predict the four output lines. Explain why the member is
constructed before the `Car` constructor body and destroyed after the `Car`
destructor body.

## 5. Automatic and dynamic lifetime

Create one automatic `Marker` and one with `new`. Identify the lifetime of each.
Add the necessary `delete`, then explain what is lost if it is omitted.

## 6. Early return

Create a local `Marker` inside a function that returns early. Verify that the
destructor still runs. Explain how this behavior supports reliable cleanup.

## 7. RAII

Design a small `IntArray` class that owns a dynamically allocated array.
Allocate in the constructor and release in the destructor. Then answer:

1. Which object controls the array's lifetime?
2. Why should client code not call `delete[]` directly?
3. What additional operations become necessary if `IntArray` is copied?

## 8. Find the lifetime error

```cpp
Marker* makeMarker() {
    Marker local("temporary");
    return &local;
}
```

Explain why the returned pointer is invalid. Rewrite the design in two safe
ways: one returning an object by value and one returning `std::unique_ptr`.

## Completion check

You are ready to continue when you can trace nested and composed objects,
distinguish scope from allocation, and explain RAII without relying on a run.
