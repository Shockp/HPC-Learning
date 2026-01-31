1. Don't panic! All will become clear in time
2. Don’t use the built-in features exclusively. Many fundamental (built-in) features are usually best used indirectly through libraries, such as the ISO C++ standard library 
3. #include or (preferably) import the libraries needed to simplify programming
4. You don't have to know every detail of C++ to write good programs
5. Foxus on programming techniques, not on language features
6. The ISO C++ standard is the final word on language definition issues
7. "Package" meaningful operations as carefully named functions
8. A function should perfom a single logical operation
9. Keep functions short
10. Use overloading when functions perfom conceptually the same task on different types
11. If a function may have to be evaluated at compile time, declare it constexpr
12. If a function must be evaluated at compile time, declare it consteval
13. If a function may not have side effects, declare it constexpr or consteval
14. Understand how language primitives map to hardware
15. Use digit separators to make large literals readable
16. Avoid complicated expressions
17. Avoid narrowing conversions
18. Minimize the scope of a variable
19. Keep scopes small
20. Avoid "magic constants"; use symbolic constants
21. Prefer immutable data
22. Declare one name (only) per declaration
23. Keep common and local names short; keep uncommon and nonlocal names longer
24. Avoid similar looking names
25. Avoid ALL_CAPS names
26. Prefer the {} initializer syntax for declarations with a named type
27. Use auto to avoid repeating type names
28. Avoid uninitialized variables
29. Don't declare a variable until you have a value to initialize it with
30. When declaring a variable in the condition of an if-statement, prefer the version with the implicit test against 0 or nullptr
31. Prefer range-for loops over for-loops with an explicit loop variable
32. Use unsigned for bit maniputalion only
33. Keep use of pointers simple and straightforward
34. Use nullptr rather than 0 or NULL
35. Don't say in comments what can be clearly stated in code
36. State intent in comments
37. Maintain a consistent identation style