# Part 1 — Initial Prototype

Spec: [[../Part 1/Project 1 - Part 1.pdf|Project 1 - Part 1.pdf]]
Code snapshot: [[../Part 1/Project 1 Part 1/main.c|main.c]]
Evidence: [[../Part 1/Project 1 Part 1/Test Evidence and Bugs.pdf|Test Evidence and Bugs.pdf]]

## Summary

Banner (title/version/programmer/welcome), Student ID/Name/GPA entry,
formatted Student Summary. No arrays, functions, loops, or file I/O this week.

## Bug fixed

Prompts appeared jumbled when run outside a real terminal (e.g. VS Code's
Code Runner) — `stdout` becomes fully buffered when it isn't a TTY. Fixed
with `fflush(stdout);` after each prompt.

## Input validation added

Student ID / Current GPA reject letters, trailing garbage, and
out-of-range/negative values. Student Name rejects a blank entry. All via
single `if` checks — no loops or functions available yet.

Back to [[SIMS Project]]
