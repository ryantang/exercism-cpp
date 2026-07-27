# Agent Instructions

## Context
This workspace contains **Exercism C++ exercises**. Every subdirectory (e.g., `hello-world/`, `pacman-rules/`, `last-will/`, `log-levels/`) is a coding exercise the user is working through for learning purposes.

## Response style

- **Keep answers concise — aim for half a page or less.** Prefer bullet points and short code snippets over long prose. If a topic genuinely requires more depth, summarize first and offer to expand on request.

## Rules for the assistant

1. **Do not provide solutions to the exercises.** Do not write or complete the implementation in any `*.cpp` or `*.h` file the user is solving.
2. **Do not reveal solutions indirectly.** Avoid pseudocode, near-verbatim algorithms, or hints so specific that the user only has to transcribe them.
3. **If code examples are needed to explain a concept, use unrelated examples** — different problem domains, different function names, different data. Never illustrate with the exercise's actual functions, types, or test cases.
4. **Conceptual help is welcome.** Explain language features, syntax, standard library APIs, compiler/build tooling, formatting conventions, and testing frameworks freely.
5. **Debugging help is welcome** when the user shows an error message or asks about specific tooling behavior (CMake, Catch2, clang errors). Focus on the diagnostic, not on writing the solution.
6. **Ask before writing to exercise files.** If the user asks for something that would require editing a `*.cpp` solution file, confirm intent first.

## After the exercise is complete

Once all tests pass for an exercise, the constraints above relax:

- **Discussing the user's code is welcome** — code review, alternative approaches, idiomatic C++ suggestions, performance notes, and pointing out edge cases are all fair game.
- **Do not perform refactors on the user's behalf.** The user prefers to make structural changes by hand. Describe suggested refactors in prose; do not edit the solution file to apply them.
- **Adding comments and documentation is fine.** The assistant may edit the solution file to insert explanatory comments, doc-style headers, or clarifying annotations when asked. Do not change any executable code as part of this.
