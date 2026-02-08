# C++ Tips & Best Practices

## Object Lifecycle
- **Essential operations:** Control construction, copy, move, and destruction of objects.
- **Matched set:** Design constructors, assignments, and the destructor as a matched set of operations.
- **Completeness:** Define all essential operations or none.
- **Compiler generation:** If a default constructor, assignment, or destructor is appropriate, let the compiler generate it.
- **Pointer members:** If a class has a pointer member, consider if it needs a user-defined or deleted destructor, copy, and move.
- **User-defined destructor:** If a class has a user-defined destructor, it probably needs user-defined or deleted copy and move.
- **Explicit constructors:** By default, declare single-argument constructors `explicit`.
- **Resource handles:** If a class is a resource handle, it needs a user-defined constructor, a destructor, and non-default copy operations.

## Initialization & Defaults
- **Member initialization:** If a class member has a reasonable default value, provide it as a data member initializer.
- **Copying restrictions:** Redefine or prohibit copying if the default is not appropriate for a type.

## Resource Management
- **Resource safety:** Provide strong resource safety; that is, never leak anything that you think of as a resource.
- **RAII:** Manage all resources—memory and non-memory—using RAII.

## Operators & Conventions
- **Conventional usage:** Overload operators to mimic conventional usage.
- **Operator groups:** If you overload an operator, define all operations that conventionally work together.
- **Comparison operators:** If you define `<=>` for a type as non-default, also define `==`.

## Efficiency & Containers
- **Return by value:** Return containers by value (relying on copy elision and move for efficiency).
- **Copying:** Avoid explicit use of `std::copy()`.
- **Large operands:** For large operands, use `const` reference argument types.
- **Container design:** Follow the standard-library container design.
