# Student Guide

This repository is a learning companion for students who already know basic
C++ programming and are now learning object-oriented programming.

## Get the repository

```bash
git clone https://github.com/ARGELIBEN77/OOP_IN_ARG26.git
cd OOP_IN_ARG26
```

You can also use GitHub's **Code → Download ZIP** option. A C++17 compiler and
Make are recommended. The commands work in Linux, macOS, and WSL.

## Begin a unit

Open the [course-unit index](Units/README.md), choose your current unit, and
follow this cycle:

1. Read the unit goals so you know what you should be able to explain or do.
2. Study the lecture notes and trace each example before reading its output.
3. Open the related project and follow its recommended file order.
4. Build the demonstration and compare its behavior with your prediction.
5. Run the tests and connect each assertion to a class requirement.
6. Complete the exercises. Re-run the tests after every small change.

## Build a project

Each project has its own `README.md` and `Makefile`. For example:

```bash
cd Song_Class_Fundamentals
make run
make test
```

Use the exact commands shown in that project's README because some projects
provide additional demonstrations.

## Learn from completed code

The project code is deliberately complete so that it can be read, traced, and
modified. Avoid treating it as something to copy without examination.

For each class, ask:

- What state does this object protect?
- What must always remain valid?
- Which operations change the state?
- Who owns every dynamically managed object?
- What should happen when the object is copied, moved, or destroyed?

When you meet an unfamiliar line, predict what would change if it were removed
or rewritten. Then test your prediction in a small experiment.

## Use the exercises

The exercises progress from tracing and explanation to modification and
design. Keep your work in a separate branch so you can compare it with the
starting version:

```bash
git switch -c my-unit-work
```

Commit after each meaningful step. A short message such as
`Complete iterator traversal exercise` makes your progress easy to review.

## Use solutions productively

Some activities include solutions for self-checking. First write and test your
own answer. Then compare these three things:

- the reasoning used to choose the design;
- ownership, lifetime, and error-handling decisions;
- tests or cases that your answer did not consider.

Close the solution and correct your work from memory. A solution is most useful
when it helps you explain a mistake, not when it replaces the attempt.


## If something fails

Read the first compiler error first. Later messages are often consequences of
that error. Check the spelling of file names and confirm that the command is
being run inside the correct project directory.

If the original project tests fail before you change anything, record the
project name, command, compiler version, and complete first error message.
