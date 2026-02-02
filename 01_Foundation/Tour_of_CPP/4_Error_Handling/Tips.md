# C++ Tips & Best Practices

## Error Handling Strategy
- **Throw an exception** to indicate that you cannot perform an assigned task.
- **Use exceptions for error handling only.**
- **Expected events:** Failing to open a file or to reach the end of an iteration are expected events and not exceptional.
- **Use error codes** when an immediate caller is expected to handle the error.
- **Throw an exception** for errors expected to percolate up through many function calls.
- **Prefer exceptions:** If in doubt whether to use an exception or an error code, prefer exceptions.
- **Early design:** Develop an error-handling strategy early in a design.

## Exceptions Implementation
- **User-defined types:** Use purpose-designed user-defined types as exceptions (not built-in types).
- **Don't catch everything:** Don't try to catch every exception in every function.
- **Standard hierarchy:** You don't have to use the standard-library exception class hierarchy.
- **RAII:** Prefer RAII to explicit try-blocks.
- **`noexcept`:**
    - If your function may not throw, declare it `noexcept`.
    - Don't apply `noexcept` thoughtlessly.

## Invariants & Assertions
- **Constructors:** Let a constructor establish an invariant, and throw if it cannot.
- **Design around invariants:** Design your error-handling strategy around invariants.
- **Compile-time checks:** What can be checked at compile time is usually best checked at compile time.
- **Assertions:** Use an assertion mechanism to provide a single point of control of the meaning of failure.
- **Concepts:** Concepts are compile-time predicates and therefore often useful in assertions.