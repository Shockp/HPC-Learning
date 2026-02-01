1. Prefer well-define user-defined types over built-in types when the built-in types are too low-level
2. Organize related data into structures (structs or classes)
3. Represent the ditinction between an interface and an implementation using a class
4. A struct is simply a class with its members public by default
5. Define constructors to guarantee and simplify initialization of classes
6. Use enumerations to represent sets of named constants
7. Prefer class enums over "plain" enums to minimize surprises
8. Define operations on enumerations for safe and simple use
9. Avoid "naked" unions; rwap them in a class together with a type field
10. Prefer std::variant to "naked" unions