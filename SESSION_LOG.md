# SIMS Project — Session Log

Precise, dated record of every session's work on this project. This is the
authoritative source of truth for continuity across chats — read this file
(and CHANGELOG.md) in full before doing any new work here, even if memory
already seems to have the context.

Separate from the weekly standalone CCR series (Tampa Fitness/Sunrise
Coffee/Grand Cinema, etc.) — never pull content or context from that series
into this log or vice versa.

---

## 2026-09-08 (continued)

- Added input validation to `main.c`, per user request: "if it ask for a number
  dont let it use letters, and vise versa. Make realistic and logical
  restrictions." Flagged first that full validation both ways isn't equally
  possible under Part 1's constraints: numeric fields can be checked with a
  single `if` (via `scanf`'s return value plus a one-character trailing-garbage
  peek), but rejecting embedded digits in the Student Name field would require
  scanning an arbitrary-length string character by character — a loop or a
  function, both explicitly out of scope this week. User's follow-up ("do
  exactly what the instructions say, but if you can improve the code then do
  it") resolved this: stayed within the no-loops/no-functions constraint.
  Implemented: Student ID rejects non-numeric input, trailing garbage after the
  number (e.g. `"123abc"`), and negative values; Current GPA rejects
  non-numeric input, trailing garbage, and values outside 0.0-4.0 (matches the
  PDF's own example scale); Student Name rejects a blank entry (no loop
  needed — just checks the first character). Digit-rejection in the name field
  is intentionally NOT implemented, and is documented as such in
  `CHANGELOG.md`, since it cannot be done without breaking the stated
  constraint. All error paths print a clear message and exit(1) rather than
  looping to re-prompt (retry would also require a loop). Recompiled clean
  with `-Wall -Wextra` and re-verified: all 3 required test cases still pass,
  plus adversarial tests for every new rejection path (letters in ID/GPA,
  trailing garbage in both, negative ID, blank name, GPA out of range,
  boundary GPA = 0.0) all behaved correctly. Updated the `Part 1/Project 1
  Part 1/main.c` snapshot to match.

## 2026-09-08

- Received the CCR-001 (Project 1 - Part 1) PDF spec: Student Information
  Management System (SIMS), COP 3515, University Registrar's Office.
- Wrote `main.c`: banner (course/software title, version, programmer name,
  welcome message), then prompts for Student ID (int) / Student Name
  (string) / Current GPA (float), then a formatted "Student Summary."
  Permitted features only — no arrays-for-records, functions, loops, or
  file I/O per the PDF's "Out of Scope" list.
- Compiled with `gcc -Wall -Wextra -std=c11` — zero warnings.
- Verified against all 3 PDF-required test cases: Alice Johnson (3.84),
  Michael Brown (2.91), Christopher Williams (4.00) — all passed exactly.
- Bug found: user ran the program in VS Code and prompts printed jumbled
  together instead of in order. Root cause: `stdout` becomes fully
  buffered (not line-buffered) when it isn't a real TTY, so prompt text
  sat in the buffer instead of appearing before `scanf`/`fgets` blocked
  for input. Fix: added `fflush(stdout);` immediately after every prompt
  `printf`. Recompiled and reverified — all 3 test cases still pass.
- Created `CHANGELOG.md` to track future increments of this project.
- Naming correction: the PDF's own internal label for this release is
  "CCR-001," which collides with the unrelated weekly CCR series' naming
  (CCR1 = Tampa Fitness, etc.). Per explicit user instruction — "CCRs and
  my project are entirely separate... My project will have the same
  template and the same info" — renamed this project's increments to
  **"Part N"** everywhere in its own files/comments going forward. Part 1
  = the PDF's "CCR-001."
- Initialized a git repository scoped to this folder only
  (`/Users/bransonzemaitis/Desktop/Advanced Program/Project/`, branch
  `main`), added `.gitignore` (compiled binary `sims`, `.DS_Store`), and
  made the initial commit (`f25e45c`, "Part 1: initial SIMS prototype").
- Established ongoing process: every time this project's code changes,
  update `CHANGELOG.md` (per-Part summary) and this `SESSION_LOG.md`
  (precise dated record), then commit both together.
- Confirmed with user: the file lives at
  `/Users/bransonzemaitis/Desktop/Advanced Program/Project/main.c` (note:
  `Project`, not `Project 1` — an earlier, now-deleted attempt lived at
  the latter path before the real Part 1 PDF was available).
- Created `Part 1/` subfolder and moved `Project 1 - Part 1.pdf` into it.
  `Project 1 - Part 2.pdf` (already present in the project root) left
  unfiled until Part 2 work begins.
- Created `Part 2/` subfolder and moved `Project 1 - Part 2.pdf` into it
  (organizational only — Part 2 requirements have not been read or
  implemented yet).
- Added a minimal title-label file to each part folder (superseded below).
- Built the Part 1 submission evidence PDF per the PDF's "Submission
  Requirements"/"Testing Requirements" sections: captured real terminal
  transcripts for all 3 required test cases by running the compiled
  `sims` binary under a Python `pty` (not simulated/typed-up text),
  rendered each into a dark terminal-style screenshot, and assembled a
  4-page PDF (title + bug writeup, then one screenshot per test case,
  each marked PASS) at
  `Part 1/Project 1 Part 1/Test Evidence and Bugs.pdf`. Bug writeup
  describes the stdout-buffering/fflush fix from earlier this session.
  Scripts used to generate this live only in the session scratchpad, not
  the project repo (not needed for future parts — Part 2's evidence PDF
  will be built fresh from Part 2's own test cases).
- Correction: the ".md label file" request actually meant a **subfolder**
  named `Project 1 Part N`, not a text file. User manually reorganized
  `Part 1/` to: `Part 1/Project 1 - Part 1.pdf` (spec) plus
  `Part 1/Project 1 Part 1/main.c` (finished Part 1 code snapshot),
  removing the earlier `.md` label file and the flat `main.c` copy.
  Mirrored the same structure for `Part 2/`: created
  `Part 2/Project 1 Part 2/main.c` as a copy of the current main.c —
  this is just Part 2's *starting point* to build from, not finished
  Part 2 code. Neither of these `Project 1 Part N/main.c` snapshot
  copies auto-updates when the root `main.c` (the live, cumulative file)
  changes — they must be refreshed manually when a part is finalized.
