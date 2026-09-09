# SIMS (Student Information Management System) — Changelog

Cumulative Project 1 for COP 3515. Each entry is one Part, building directly on
the previous week's `main.c`. This log is specific to this project only —
unrelated to the separate weekly standalone CCR series (Tampa Fitness, Sunrise
Coffee, Grand Cinema, etc.), which uses the word "CCR" for a different, unrelated
numbering scheme. Do not cross-reference content between the two.

## Part 1 (2026-09-08) — Initial prototype

**Requirements:** Display course/software title, version, programmer name, and a
welcome banner. Prompt for Student ID (int), Student Name (string), Current GPA
(float). Display a formatted "Student Summary." Single student only — no arrays,
functions, loops, or file I/O per this week's constraints.

**Implementation:** [main.c](main.c) — banner via `#define` constants, `scanf`/`fgets`
for input, `%.2f` formatting for GPA.

**Bug fixed:** Prompts appeared jumbled together when run in VS Code (e.g. via the
Code Runner extension) instead of a real terminal — caused by `stdout` switching to
full buffering when it isn't a TTY, so prompt text sat in the buffer instead of
printing before `scanf`/`fgets` blocked for input. Fixed by adding `fflush(stdout);`
immediately after each prompt `printf`.

**Tests:** All three PDF-required cases pass exactly (Alice Johnson 3.84 / Michael
Brown 2.91 / Christopher Williams 4.00). Compiles clean with `-Wall -Wextra`.
