# C++ Tips & Best Practices

## Concrete Types
- **Express ideas directly in code.**
- **Concrete types:** A concrete type is the simplest kind of class. Where applicable, prefer a concrete type over more complicated classes and over plain data structures.
- **Simple concepts:** Use concrete classes to represent simple concepts.
- **Performance:** Prefer concrete classes over class hierarchies for performance-critical components.
- **Constructors:** Define constructors to handle initialization of objects.
- **Containers:** If a class is a container, give it an initializer-list constructor.

## Class Design & Operators
- **Member functions:** Make a function a member only if it needs direct access to the representation of a class.
- **Operators:** Define operators primarily to mimic conventional usage.
- **Symmetric operators:** Use nonmember functions for symmetric operators.
- **Const correctness:** Declare a member function that does not modify the state of its object `const`.

## Resource Management
- **Destructors:** If a constructor acquires a resource, its class needs a destructor to release the source.
- **Scoping:** Avoid "naked" `new` and `delete` operations.
- **RAII:** Use resource handles and RAII to manage resources.
- **Smart pointers:** Use `unique_ptr` or `shared_ptr` to avoid forgetting to delete objects created using `new`.

## Abstract Types & Hierarchy
- **Abstract classes:** Use abstract classes as interfaces when complete separation of interface and implementation is needed.
- **Polymorphism:** Access polymorphic objects through pointers and references.
- **Constructors:** An abstract class typically doesn't need a constructor.
- **Class hierarchies:** Use class hierarchies to represent concepts with inherent hierarchical structure.
- **Virtual destructors:** A class with a virtual function should have a virtual destructor.
- **Overriding:** Use `override` to make overriding explicit in large class hierarchies.
- **Inheritance:** When designing a class hierarchy, distinguish between implementation inheritance and interface inheritance.

## Casting & Type Safety
- **Dynamic casting:** Use `dynamic_cast` where class hierarchy navigation is unavoidable.
- **References:** Use `dynamic_cast` to a reference type when failure to find the required class is considered a failure.
- **Pointers:** Use `dynamic_cast` to a pointer type when failure to find the required class is considered a valid alternative.