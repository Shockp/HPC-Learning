# C++ Tips & Best Practices

## General Philosophy
- **Prefer well-defined user-defined types** over built-in types when the built-in types are too low-level.
- **Organize related data** into structures (structs or classes).

## Classes & Structs
- **Interface vs. Implementation:** Represent the distinction between an interface and an implementation using a class.
- **Structs:** A struct is simply a class with its members public by default.
- **Constructors:** Define constructors to guarantee and simplify initialization of classes.

## Enumerations
- **Use enumerations** to represent sets of named constants.
- **Prefer class enums** over "plain" enums to minimize surprises.
- **Define operations** on enumerations for safe and simple use.

## Unions & Variants
- **Avoid "naked" unions;** wrap them in a class together with a type field.
- **Prefer `std::variant`** to "naked" unions.