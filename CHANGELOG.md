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

**Input validation added (still Part 1, refinement):** Student ID and Current GPA
are now rejected (clear error message, program exits) if they contain letters or
trailing garbage (e.g. `"abc"`, `"123abc"`), if Student ID is negative, or if GPA
falls outside 0.0–4.0. Student Name is rejected if left blank. All checks use a
single `if` per condition — no loops or functions, since Part 1's spec explicitly
puts both out of scope this week. Rejecting digits embedded in the Student Name
(e.g. `"Al1ce"`) would require scanning an arbitrary-length string character by
character, which needs a loop or function — not possible within this week's
constraints, so that specific check is intentionally not implemented. Re-verified
all three required test cases still pass after adding these checks.

## Part 2 (2026-09-09) — Course grades, average/highest/lowest

**Requirements:** Continue all Part 1 functionality. Add five course grades
(0–100 each), store them, calculate and display Average Grade (2 decimals),
Highest Grade, and Lowest Grade, alongside the existing Student Summary.
Single student only. Newly permitted this week: arrays, enumerations,
selection statements. Still out of scope: functions, loops, files, multiple
students, menus, searching, editing grades, letter grades, academic standing,
dynamic memory.

**Implementation:** [main.c](main.c) — version bumped to 2.0. `courseGrades[5]`
array (size named via `enum { NUM_COURSES = 5 }`, a newly-permitted feature).
Average/highest/lowest computed with straight-line arithmetic and five
individual `if` comparisons each — no loop or function, since both remain out
of scope. Each of the 5 grades gets the same validation treatment as Part 1's
numeric fields: reject non-numeric input, trailing garbage, and out-of-range
values (0–100), printing a clear error and exiting rather than re-prompting.

**Judgment call, flagged and resolved with user:** Part 2's own worked example
output omits the `Programmer:` line, but Part 2's Acceptance Criteria requires
"all functionality from CCR-001" (Part 1) to keep working, which included that
line. User decided: keep it, since the Acceptance Criteria is the binding
requirement and the example most likely just carried an omission forward from
editing the template.

**Answers to the PDF's "Questions for the Customer"** (required in this
part's submission PDF): grades are whole numbers 0–100 (every worked example
uses whole numbers); no fractional grades; invalid grades print an error and
exit rather than re-prompt, matching Part 1's approach (loops aren't available
for a retry); courses have no names, only grades (the examples only ever
label them "Course 1"–"Course 5"); average is rounded to 2 decimal places
(matches 91.60/79.00/100.00 in the examples); a tied highest or lowest grade
is simply displayed once, since the Acceptance Criteria asks only for the
grade value, not which course earned it, and identifying the matching course
would effectively be a "searching" feature — explicitly out of scope; more
than five courses is not addressed this week (fixed at five per this week's
spec) and would need a future CCR.

**Tests:** All three required regression cases pass exactly — Alice Johnson
(avg 91.60, high 100, low 84), Michael Brown (avg 79.00, high 91, low 68),
Christopher Williams (avg 100.00, high 100, low 100). Compiles clean with
`-Wall -Wextra`. Adversarially tested: letters/trailing garbage/out-of-range
on a course grade, and boundary grades of exactly 0 and 100 (avg computed
correctly as 50.00). Re-confirmed Part 1's own invalid-input rejections
(bad ID, blank name) still work unchanged.
