# SIMS Project — Session Log

Precise, dated record of every session's work on this project. This is the
authoritative source of truth for continuity across chats — read this file
(and CHANGELOG.md) in full before doing any new work here, even if memory
already seems to have the context.

Separate from the weekly standalone CCR series (Tampa Fitness/Sunrise
Coffee/Grand Cinema, etc.) — never pull content or context from that series
into this log or vice versa.

---

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
