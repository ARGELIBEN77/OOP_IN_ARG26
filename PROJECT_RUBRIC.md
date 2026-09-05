# Project Assessment Rubric

Use this rubric to review your project before submission. An instructor may
adjust the weights for a particular assignment.

| Area | Points | Evidence of successful work |
|---|---:|---|
| Correct behavior | 30 | Required operations work for normal, boundary, and invalid inputs |
| Class design | 20 | Responsibilities, interfaces, invariants, and relationships are clear |
| C++ semantics | 20 | Copying, moving, ownership, polymorphism, exceptions, or templates are used correctly where relevant |
| Tests | 15 | Tests cover requirements, edge cases, and at least one failure path |
| Code clarity | 10 | Names are meaningful, functions are focused, and comments explain non-obvious decisions |
| Build and repository use | 5 | The project builds without warnings and commits show meaningful progress |

## Before submitting

- Run `make test` from the project directory.
- Read the first compiler warning or error and correct its cause.
- Check construction, copying, moving, and destruction when the project uses
  owned resources.
- Explain every ownership relationship and every virtual operation.
- Remove temporary debugging output unless it is part of the demonstration.
- Confirm that comments explain why, rather than repeat what the code says.

## Interpreting feedback

Do not correct only the line named in the feedback. Identify the violated
class invariant, ownership rule, interface decision, or language rule, and
check the rest of the project for the same issue.

