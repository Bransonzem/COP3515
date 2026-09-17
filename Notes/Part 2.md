# Part 2 — Course Grades

Spec: [[../Part 2/Project 1 - Part 2.pdf|Project 1 - Part 2.pdf]]
Code snapshot: [[../Part 2/Project 1 Part 2/main.c|main.c]]
Evidence: [[../Part 2/Project 1 Part 2/Test Evidence, Bugs, and Customer Questions.pdf|Test Evidence, Bugs, and Customer Questions.pdf]]

## Summary

Version bumped to 2.0. Added `courseGrades[5]` array (arrays newly permitted
this week), average/highest/lowest computed via straight-line arithmetic and
individual `if` comparisons — still no loops or functions. Same validation
philosophy as Part 1 applied to each grade (0–100 range, reject letters/
trailing garbage).

## Judgment call

Part 2's worked example omits the `Programmer:` line, but its Acceptance
Criteria requires all Part 1 functionality to keep working. Decision: kept
the line (Acceptance Criteria wins over the example).

## Student Summary placement (fixed 2026-09-09)

Originally the Student Summary printed right after GPA entry, which put the
five grade prompts between the student info and the grade report. Acceptance
Criteria requires student and grade information to be "displayed together,"
and the worked example shows them as one block. Moved the summary block down
so it prints after Course 5 is entered, immediately above Course Grades.
Screenshots were retaken after this change.

## Invalid-input behavior (resolved 2026-09-09)

Invalid input rejects with an error and exits — no retry loop, since loops
are out of scope this week. Confirmed with user: "try again" means re-running
the compiled binary, not an in-program retry. No code change needed.

Back to [[SIMS Project]]
