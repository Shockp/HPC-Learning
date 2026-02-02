# C++ Tips & Best Practices

## Interface & Implementation
- **Distinguish between declarations and definitions.** Declarations are used as interfaces, definitions as implementations.
- **Prefer modules over headers** where modules are supported.
- **Header Files:**
    - Use header files to represent interfaces and to emphasize logical structure.
    - `#include` a header in the source file that implements its functions.
    - Avoid non-inline function definitions in headers.

## Namespaces
- **Use namespaces** to express logical structure.
- **Using-directives:**
    - Use using-directives for transition, for foundational libraries (such as `std`), or within a local scope.
    - **Don't put a using-directive in a header file.**

## Function Arguments & Return Values
- **Argument Passing:**
    - Pass "small" values by value and "large" values by reference.
    - Prefer pass-by-const reference over plain pass-by-reference.
- **Return Values:**
    - Return values as function-return values (rather than by out-parameters).
    - **Don't overuse return-type deduction.**
    - **Don't overuse structured binding;** a named return type often gives more readable code.