# C++ Tips & Best Practices

## General Philosophy
- **Don't panic!** All will become clear in time.
- **Don't use built-in features exclusively.** Many fundamental features are best used indirectly through libraries, such as the ISO C++ standard library.
- **Focus on programming techniques**, not just on language features.
- **You don't have to know every detail** of C++ to write good programs.
- **The ISO C++ standard** is the final word on language definition issues.
- **Understand how language primitives map to hardware.**

## Functions
- **Package meaningful operations** as carefully named functions.
- **Single responsibility:** A function should perform a single logical operation.
- **Keep functions short.**
- **Use overloading** when functions perform conceptually the same task on different types.
- **Compile-time evaluation:**
    - If a function *may* have to be evaluated at compile time, declare it `constexpr`.
    - If a function *must* be evaluated at compile time, declare it `consteval`.
    - If a function may not have side effects, declare it `constexpr` or `consteval`.

## Variables & Types
- **Minimize scope:** Minimize the scope of a variable. Keep scopes small.
- **Avoid "magic constants";** use symbolic constants.
- **Prefer immutable data.**
- **One name per declaration:** Declare one name (only) per declaration.
- **Initialization:**
    - Prefer the `{}` initializer syntax for declarations with a named type.
    - Use `auto` to avoid repeating type names.
    - **Avoid uninitialized variables.** Don't declare a variable until you have a value to initialize it with.
- **Narrowing conversions:** Avoid narrowing conversions.
- **Digit separators:** Use digit separators to make large literals readable.
- **Unsigned types:** Use `unsigned` for bit manipulation only.
- **Pointers:**
    - Keep use of pointers simple and straightforward.
    - Use `nullptr` rather than `0` or `NULL`.

## Code Structure & Control Flow
- **Libraries:** `#include` or (preferably) `import` the libraries needed to simplify programming.
- **Complicated expressions:** Avoid complicated expressions.
- **Conditionals:** When declaring a variable in the condition of an `if`-statement, prefer the version with the implicit test against `0` or `nullptr`.
- **Loops:** Prefer range-for loops over for-loops with an explicit loop variable.

## Naming & Style
- **Name length:** Keep common and local names short; keep uncommon and nonlocal names longer.
- **Distinct names:** Avoid similar looking names.
- **Capitalization:** Avoid `ALL_CAPS` names.
- **Comments:**
    - Don't say in comments what can be clearly stated in code.
    - State intent in comments.
- **Indentation:** Maintain a consistent indentation style.