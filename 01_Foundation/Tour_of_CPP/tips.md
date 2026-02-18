# C++ Tips & Best Practices

## 1. The Basics

### General Philosophy
- **Don't panic!** All will become clear in time.
- **Don't use built-in features exclusively.** Many fundamental features are best used indirectly through libraries, such as the ISO C++ standard library.
- **Focus on programming techniques**, not just on language features.
- **You don't have to know every detail** of C++ to write good programs.
- **The ISO C++ standard** is the final word on language definition issues.
- **Understand how language primitives map to hardware.**

### Functions
- **Package meaningful operations** as carefully named functions.
- **Single responsibility:** A function should perform a single logical operation.
- **Keep functions short.**
- **Use overloading** when functions perform conceptually the same task on different types.
- **Compile-time evaluation:**
    - If a function *may* have to be evaluated at compile time, declare it `constexpr`.
    - If a function *must* be evaluated at compile time, declare it `consteval`.
    - If a function may not have side effects, declare it `constexpr` or `consteval`.

### Variables & Types
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

### Code Structure & Control Flow
- **Libraries:** `#include` or (preferably) `import` the libraries needed to simplify programming.
- **Complicated expressions:** Avoid complicated expressions.
- **Conditionals:** When declaring a variable in the condition of an `if`-statement, prefer the version with the implicit test against `0` or `nullptr`.
- **Loops:** Prefer range-for loops over for-loops with an explicit loop variable.

### Naming & Style
- **Name length:** Keep common and local names short; keep uncommon and nonlocal names longer.
- **Distinct names:** Avoid similar looking names.
- **Capitalization:** Avoid `ALL_CAPS` names.
- **Comments:**
    - Don't say in comments what can be clearly stated in code.
    - State intent in comments.
- **Indentation:** Maintain a consistent indentation style.

## 2. User Defined Types

### General Philosophy
- **Prefer well-defined user-defined types** over built-in types when the built-in types are too low-level.
- **Organize related data** into structures (structs or classes).

### Classes & Structs
- **Interface vs. Implementation:** Represent the distinction between an interface and an implementation using a class.
- **Structs:** A struct is simply a class with its members public by default.
- **Constructors:** Define constructors to guarantee and simplify initialization of classes.

### Enumerations
- **Use enumerations** to represent sets of named constants.
- **Prefer class enums** over "plain" enums to minimize surprises.
- **Define operations** on enumerations for safe and simple use.

### Unions & Variants
- **Avoid "naked" unions;** wrap them in a class together with a type field.
- **Prefer `std::variant`** to "naked" unions.

## 3. Modularity

### Interface & Implementation
- **Distinguish between declarations and definitions.** Declarations are used as interfaces, definitions as implementations.
- **Prefer modules over headers** where modules are supported.
- **Header Files:**
    - Use header files to represent interfaces and to emphasize logical structure.
    - `#include` a header in the source file that implements its functions.
    - Avoid non-inline function definitions in headers.

### Namespaces
- **Use namespaces** to express logical structure.
- **Using-directives:**
    - Use using-directives for transition, for foundational libraries (such as `std`), or within a local scope.
    - **Don't put a using-directive in a header file.**

### Function Arguments & Return Values
- **Argument Passing:**
    - Pass "small" values by value and "large" values by reference.
    - Prefer pass-by-const reference over plain pass-by-reference.
- **Return Values:**
    - Return values as function-return values (rather than by out-parameters).
    - **Don't overuse return-type deduction.**
    - **Don't overuse structured binding;** a named return type often gives more readable code.

## 4. Error Handling

### Error Handling Strategy
- **Throw an exception** to indicate that you cannot perform an assigned task.
- **Use exceptions for error handling only.**
- **Expected events:** Failing to open a file or to reach the end of an iteration are expected events and not exceptional.
- **Use error codes** when an immediate caller is expected to handle the error.
- **Throw an exception** for errors expected to percolate up through many function calls.
- **Prefer exceptions:** If in doubt whether to use an exception or an error code, prefer exceptions.
- **Early design:** Develop an error-handling strategy early in a design.

### Exceptions Implementation
- **User-defined types:** Use purpose-designed user-defined types as exceptions (not built-in types).
- **Don't catch everything:** Don't try to catch every exception in every function.
- **Standard hierarchy:** You don't have to use the standard-library exception class hierarchy.
- **RAII:** Prefer RAII to explicit try-blocks.
- **`noexcept`:**
    - If your function may not throw, declare it `noexcept`.
    - Don't apply `noexcept` thoughtlessly.

### Invariants & Assertions
- **Constructors:** Let a constructor establish an invariant, and throw if it cannot.
- **Design around invariants:** Design your error-handling strategy around invariants.
- **Compile-time checks:** What can be checked at compile time is usually best checked at compile time.
- **Assertions:** Use an assertion mechanism to provide a single point of control of the meaning of failure.
- **Concepts:** Concepts are compile-time predicates and therefore often useful in assertions.

## 5. Classes

### Concrete Types
- **Express ideas directly in code.**
- **Concrete types:** A concrete type is the simplest kind of class. Where applicable, prefer a concrete type over more complicated classes and over plain data structures.
- **Simple concepts:** Use concrete classes to represent simple concepts.
- **Performance:** Prefer concrete classes over class hierarchies for performance-critical components.
- **Constructors:** Define constructors to handle initialization of objects.
- **Containers:** If a class is a container, give it an initializer-list constructor.

### Class Design & Operators
- **Member functions:** Make a function a member only if it needs direct access to the representation of a class.
- **Operators:** Define operators primarily to mimic conventional usage.
- **Symmetric operators:** Use nonmember functions for symmetric operators.
- **Const correctness:** Declare a member function that does not modify the state of its object `const`.

### Resource Management
- **Destructors:** If a constructor acquires a resource, its class needs a destructor to release the source.
- **Scoping:** Avoid "naked" `new` and `delete` operations.
- **RAII:** Use resource handles and RAII to manage resources.
- **Smart pointers:** Use `unique_ptr` or `shared_ptr` to avoid forgetting to delete objects created using `new`.

### Abstract Types & Hierarchy
- **Abstract classes:** Use abstract classes as interfaces when complete separation of interface and implementation is needed.
- **Polymorphism:** Access polymorphic objects through pointers and references.
- **Constructors:** An abstract class typically doesn't need a constructor.
- **Class hierarchies:** Use class hierarchies to represent concepts with inherent hierarchical structure.
- **Virtual destructors:** A class with a virtual function should have a virtual destructor.
- **Overriding:** Use `override` to make overriding explicit in large class hierarchies.
- **Inheritance:** When designing a class hierarchy, distinguish between implementation inheritance and interface inheritance.

### Casting & Type Safety
- **Dynamic casting:** Use `dynamic_cast` where class hierarchy navigation is unavoidable.
- **References:** Use `dynamic_cast` to a reference type when failure to find the required class is considered a failure.
- **Pointers:** Use `dynamic_cast` to a pointer type when failure to find the required class is considered a valid alternative.

## 6. Essential Operations

### Object Lifecycle
- **Essential operations:** Control construction, copy, move, and destruction of objects.
- **Matched set:** Design constructors, assignments, and the destructor as a matched set of operations.
- **Completeness:** Define all essential operations or none.
- **Compiler generation:** If a default constructor, assignment, or destructor is appropriate, let the compiler generate it.
- **Pointer members:** If a class has a pointer member, consider if it needs a user-defined or deleted destructor, copy, and move.
- **User-defined destructor:** If a class has a user-defined destructor, it probably needs user-defined or deleted copy and move.
- **Explicit constructors:** By default, declare single-argument constructors `explicit`.
- **Resource handles:** If a class is a resource handle, it needs a user-defined constructor, a destructor, and non-default copy operations.

### Initialization & Defaults
- **Member initialization:** If a class member has a reasonable default value, provide it as a data member initializer.
- **Copying restrictions:** Redefine or prohibit copying if the default is not appropriate for a type.

### Resource Management
- **Resource safety:** Provide strong resource safety; that is, never leak anything that you think of as a resource.
- **RAII:** Manage all resources—memory and non-memory—using RAII.

### Operators & Conventions
- **Conventional usage:** Overload operators to mimic conventional usage.
- **Operator groups:** If you overload an operator, define all operations that conventionally work together.
- **Comparison operators:** If you define `<=>` for a type as non-default, also define `==`.

### Efficiency & Containers
- **Return by value:** Return containers by value (relying on copy elision and move for efficiency).
- **Copying:** Avoid explicit use of `std::copy()`.
- **Large operands:** For large operands, use `const` reference argument types.
- **Container design:** Follow the standard-library container design.

## 7. Templates

### General
- **Algorithms:** Use templates to express algorithms that apply to many argument types.
- **Containers:** Use templates to express containers.
- **Abstraction:** Use templates to raise the level of abstraction of code.
- **Type safety:** Templates are type safe, but for unconstrained templates checking happens too late.
- **Deduction:** Let constructors or function templates deduce class template argument types.

### Function Objects & Lambdas
- **Function objects:** Use function objects as arguments to algorithms.
- **Lambdas:** Use lambda if you need a simple function object in one place only.
- **Virtual functions:** A virtual function member cannot be a template member function.

### Advanced Mechanisms
- **RAII:** Use `finally()` to provide RAII for types without destructors that require "cleanup operation".
- **Aliases:** Use template aliases to simplify notation and hide implementation details.
- **Compile-time selection:** Use `if constexpr` to provide alternative implementations without run-time overhead.

## 8. Concepts & Generic Programming

### General
- **Compile-time programming:** Templates provide a general mechanism for compile-time programming.
- **Initial implementation:** When designing a template, use a concrete version for initial implementation, debugging, and measurement.
- **Containers & Ranges:** Use templates to express containers and ranges.
- **Variadics:** Use variadic templates when you need a function that takes a variable number of arguments of a variety of types.
- **Lambdas:** Use a lambda if you need a simple function object in one place only.
- **Duck-typing:** Unconstrained templates offer compile-time "duck-typing".

### Concepts Design
- **Concept requirements:** When designing a template, carefully consider the concepts (requirements) assumed for its template arguments.
- **Design tool:** Use concepts as a design tool.
- **Explicit concepts:** Specify concepts for all template arguments.
- **Named concepts:** Whenever possible use named concepts (e.g., standard-library concepts).
- **Meaningful semantics:** Avoid "concepts" without meaningful semantics.
- **Operations:** Require a complete set of operations for a concept.
- **Complex requirements:** Avoid `requires requires`.
- **Auto:** `auto` is the least constrained concept.

### Code Organization
- **Header definitions:** When using header files, `#include` template definitions (not just declarations) in every translation unit that uses them.
- **Scope:** To use a template, make sure its definition (not just its declaration) is in scope.