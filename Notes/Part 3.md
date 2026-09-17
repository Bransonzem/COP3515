# Part 3 — Academic Standing

Spec: [[../Part 3/Project 1 - Part 3.pdf|Project 1 - Part 3.pdf]]
Code snapshot: [[../Part 3/Project 1 Part 3/main.c|main.c]]
Evidence: built — `Project 1 Part 3 - Test Evidence.pdf`
Status: **SUBMITTED to Canvas — Thu Sep 17, 2026**

## Deadline — CONFIRMED Thu Sep 17, 2026

Branson confirmed on 2026-09-16 that Part 3 is due **Thursday Sep 17**, the
same day as Part 2.

The spec header says "Due Date: Beginning of Lesson 8," which under the
lesson map previously recorded in this project's `CLAUDE.md` would have been
Thu Sep 24. That map is therefore wrong and has been flagged in `CLAUDE.md`
for correction from Canvas. Do not derive future part deadlines from it until
it is fixed.

## Summary

Version bumps to 3.0. The Registrar wants the program to classify the student
into an academic standing based on GPA, and display it in the Student Summary.
GPA validation must happen before classification; an out-of-range GPA prints an
error and does not produce a standing.

This is an additive part. Nothing from Part 1 or Part 2 has to be rewritten.

### Standing bands

| GPA | Academic Standing |
|---|---|
| 3.50 – 4.00 | Honors |
| 2.00 – 3.49 | Good Standing |
| 1.00 – 1.99 | Academic Probation |
| 0.00 – 0.99 | Academic Suspension |
| < 0.00 or > 4.00 | error, no standing determined |

### What changes in the code

1. `VERSION_NUMBER` → `"3.0"`
2. The GPA range check **already exists** from Part 1 — only its error message
   needs rewording to match the spec's Example 5 exactly.
3. New: `enum AcademicStanding`, an if/else-if cascade to set it, and a
   `switch` to print the label.
4. New: `Academic Standing :` line in the Student Summary, directly under
   `Current GPA`, same column alignment.

### What deliberately does NOT change

- The five unrolled `if` comparisons for highest and five for lowest. Loops
  are still not on this part's permitted list.
- The straight-line average arithmetic. Same reason.
- Validation exits instead of re-prompting. A retry needs a loop.

## Technical constraints

Only features through Lesson 8. Permitted: variables, constants, arrays,
enumerations, user input, formatted output, math operators, `if`, `switch`
(where appropriate), logical operators (`&&`, `||`, `!`).

Out of scope: **functions**, files, menus, multiple students, editing grades,
automatic GPA calculation, degree audits, transcripts, dynamic memory.

Note: the permitted list does not mention loops at all, even though Lesson 6
covered them. Safe read is to keep writing straight-line code like Parts 1
and 2.

## Gotcha: `switch` cannot operate on a float

`switch (currentGPA)` **will not compile.** C requires an integer type in a
switch expression, and `currentGPA` is a `float`.

The spec lists `switch` as permitted "where appropriate," and the appropriate
use is two-stage:

1. Use `if` / `else if` to decide *which* standing applies, and store that
   decision in an `enum` variable (an enum is an integer type).
2. `switch` on **that enum**, not the GPA, to print the label text.

This also answers customer question 10 (represent standing internally as
predefined categories rather than loose text) and keeps the classification
logic separate from the display logic.

## Gotcha: the bands have gaps

The table jumps from 3.49 to 3.50, and from 1.99 to 2.00. A GPA of 3.495 falls
in no band at all. Fix: use a cascade of `>=` thresholds only
(`>= 3.50`, else `>= 2.00`, else `>= 1.00`, else `>= 0.00`) so every valid GPA
lands somewhere. Document this as an assumption.

## Required regression tests

The spec requires these six at minimum, each with input, expected output,
actual output, and pass/fail:

| Test | GPA | Expected Standing |
|---|---|---|
| 1 | 3.95 | Honors |
| 2 | 3.20 | Good Standing |
| 3 | 1.75 | Academic Probation |
| 4 | 0.60 | Academic Suspension |
| 5 | -0.50 | Invalid GPA |
| 6 | 4.25 | Invalid GPA |

Plus proof that Part 1 and Part 2 functionality still works — the three
existing cases: Alice Johnson (avg 91.60), Michael Brown (avg 79.00),
Christopher Williams (avg 100.00).

Note on tests 5 and 6: the program prompts for Student ID and Name *before*
GPA, so those transcripts still need ID and name entered first. The program
then errors and exits before ever asking for course grades. That is correct
behavior, but the screenshots need to show it clearly or a grader may read it
as a crash.

## Assumptions to log in the evidence PDF

Part 3 adds a submission requirement Part 2 did not have: **"any assumptions
you made because the customer requirements were ambiguous."** Three to write up:

1. **Band gaps.** The published bands leave GPAs between 3.49 and 3.50 (and
   between 1.99 and 2.00) unclassified. Implemented as `>=` thresholds so
   every valid GPA in 0.00–4.00 receives a standing. Upper and lower limits
   are treated as inclusive.
2. **Kept the `Programmer:` line and the `Welcome to SIMS` banner.** Part 3's
   worked example omits both, but the Acceptance Criteria still requires all
   CCR-001 functionality to keep working, and CCR-001 required a welcome
   banner. Same judgment call made for Part 2 — Acceptance Criteria wins over
   the example.
3. **Invalid GPA exits rather than re-prompting.** Customer questions 3 and 4
   ask whether processing should continue or the user should re-enter. A retry
   requires a loop, which is not on this part's permitted list. Kept the
   Part 1 / Part 2 behavior: print the error, exit. "Try again" means re-running
   the binary.

## Build order

| # | Step | Est. |
|---|---|---|
| 1 | Confirm Canvas due date. Replace stale root `main.c` with the Part 2 snapshot. | 10 min |
| 2 | Answer the Questions for the Customer (spec says before coding). | 25 min |
| 3 | Version bump + reword GPA error to match Example 5. Compile. | 10 min |
| 4 | Write the classification: enum + if/else-if cascade + switch. | 40 min |
| 5 | Add the `Academic Standing :` line to the Student Summary. | 10 min |
| 6 | Regression test all 6 GPA cases + the 3 Part 2 cases. `-Wall -Wextra` clean. | 50 min |
| 7 | Build the evidence PDF: screenshots, bugs, customer answers, assumptions. | 50 min |
| 8 | Update `CHANGELOG.md` + `SESSION_LOG.md`, snapshot `main.c`, build ZIP, commit. | 20 min |

Step 4 is the only real learning. Steps 3 and 5 are typing.

## Stale main.c (fixed 2026-09-16)

The root `main.c` and the Part 2 snapshot had drifted. Both were 178 lines but
differed: the root copy still printed the Student Summary *before* the course
grade prompts, while the snapshot had the Part 2 fix that moved it below. The
snapshot was 20 hours newer and was the correct one.

Copied the Part 2 snapshot over the root `main.c` before starting Part 3, so
the Part 2 formatting fix carries forward instead of silently regressing.

**Process note:** the root `main.c` is supposed to be the live canonical file
and the snapshot a frozen copy. It drifted the other way this time. Worth
checking both before starting any future part.

## Verify before submitting

The evidence PDF has my name on it and says "I" throughout. Claude drafted it
from the actual program behaviour, but I am the one submitting it, so these
need my own eyes before it goes to Canvas:

1. **Read the whole evidence PDF.** Especially the twelve customer answers —
   they are written in my voice and several are judgment calls I should agree
   with, not just inherit.
2. **The bug write-up is mine to stand behind.** Two bugs are documented: the
   GPA display/classification mismatch, and the stale `main.c`. Both really
   happened. Make sure I can explain the `gpaRounded` fix out loud, since the
   CCR's AI policy says I am responsible for understanding all submitted code.
3. **Decide whether the rendered terminal images are acceptable, or re-run for
   real screenshots.** The images are built from the real captured output of
   the compiled program, styled to match my Part 1 screenshots (same colours,
   same pitch, same width). They are renderings, not screen captures. Where
   they still differ from Part 1:
   - Terminal font is DejaVu Sans Mono, not the Consolas/Cascadia my real
     terminal uses. Close, not identical letterforms.
   - Mine are cropped to the terminal window; these show each run in full, so
     they are taller.
   - Mine are 96 dpi screen grabs with that slight softness; these are cleanly
     rendered and look sharper than a real screenshot.
   - Headings use Carlito, which is metric-compatible with Calibri but has no
     Light weight, so the big headings are a touch heavier than Part 1's.

   If the professor wants literal screen captures, re-run the nine tests in
   PowerShell myself and swap the images in.
4. **Confirm the `3.495` behaviour is what I want.** With the rounding fix it
   now displays 3.50 and classifies Honors. That is self-consistent, but it is
   a decision, and it is written up in the assumptions section.
5. ~~Check the ZIP structure against what Canvas expects.~~ **SETTLED
   2026-09-16.** Part 1 scored **100%** using the same `Project 1 Part N/`
   wrapper folder, so the structure is confirmed acceptable to the professor
   and is the convention going forward. The old "flat, no subfolders" line in
   `CLAUDE.md` was wrong and has been corrected. Nothing to do.
6. **Drag `_TRASH ME - superseded Part 3 files/` to the Trash.** Both leftovers
   were moved there and are out of `Part 3/` now, so they can't be confused
   with the real deliverable. Claude could not put them in the Trash directly
   (no delete permission in the sandbox, and the Mac's Trash isn't reachable
   from it), so they were moved to that folder instead. Contents:
   - `zibS99Fv` — stray temp archive from a failed zip command. Contains an
     OLD copy of the evidence PDF, so don't open it by mistake.
   - `Test Evidence, Bugs, Customer Questions and Assumptions.pdf` — the
     superseded Part-2-styled draft. The real one is
     `Project 1 Part 3 - Test Evidence.pdf`.
7. **Commit to git.** Not done — left for me.

## Submission format

Single ZIP: `main.c` plus any additional source files. Separate PDF containing
screenshots of all required regression tests, bugs discovered, how each bug was
corrected, answers to the Questions for the Customer, and the assumptions
write-up.

Back to [[SIMS Project]]
