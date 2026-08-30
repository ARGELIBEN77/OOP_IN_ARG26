# Musicians and Instruments — Smart Pointer Ownership

This C++17 learning project makes ownership and object lifetime visible through
a musical application. A musician exclusively owns an instrument, while guest
musicians can participate in several ensembles that share their lifetime.

The project is inspired by the lifecycle-focused musician example in the
[Ariel University smart-pointer materials](https://github.com/cpp-at-ariel/cpp-5786/tree/main/11-smart-pointers)
and develops a new ownership model, class design, demonstration, and exercise
sequence.

## Learning objectives

After completing the project, learners should be able to:

- create exclusively owned objects with `std::make_unique`;
- transfer a `unique_ptr` using `std::move`;
- explain why the source pointer becomes empty after ownership transfer;
- return exclusive ownership from a function;
- create jointly owned objects with `std::make_shared`;
- explain how copying a `shared_ptr` adds an owner;
- predict when musicians and instruments are destroyed;
- choose an ownership model that matches a class relationship.

## Project story

Each `Musician` contains `unique_ptr<Instrument>`. The instrument has one owner
and can be transferred from one musician to another. `releaseInstrument`
returns ownership to the caller, and `receiveInstrument` transfers it into a
new musician.

Each `Ensemble` stores `shared_ptr<Musician>`. A guest musician can participate
in two ensembles at the same time. Both pointers refer to the same musician,
and that musician remains alive while either ensemble remains an owner.

## Quick start

```bash
git clone https://github.com/ARGELIBEN77/OOP_IN_ARG26.git
cd OOP_IN_ARG26/Musicians_and_Instruments_Smart_Pointers
make run
```

Run the tests:

```bash
make test
```

Remove generated executables:

```bash
make clean
```

## What to observe

The first part transfers one guitar through three owners:

1. a local `unique_ptr`;
2. the first musician;
3. the second musician.

At each transfer, the source pointer becomes empty while the same instrument
remains alive.

The second part creates one guest musician and places the same shared pointer
in two ensembles. The demonstration releases the original pointer and shows
that both ensembles can still access the musician and instrument.

## Recommended learning sequence

1. Run the program and predict each ownership change.
2. Trace `Musician::receiveInstrument` and `releaseInstrument`.
3. Draw the owner of the guitar after every `std::move`.
4. Trace the shared guest's owner count.
5. Verify that both ensembles refer to the same `Musician` object.
6. Observe the living-object counters at the end of each scope.
7. Read the tests and complete `EXERCISES.md`.

## Project structure

```text
Musicians_and_Instruments_Smart_Pointers/
├── include/
│   ├── Ensemble.hpp       Shared musician ownership
│   ├── Instrument.hpp     Exclusively owned resource
│   └── Musician.hpp       unique_ptr instrument owner
├── src/
│   ├── Ensemble.cpp
│   ├── Instrument.cpp
│   ├── Musician.cpp
│   └── main.cpp           Ownership and lifetime demonstration
├── tests/
│   └── test_musicians.cpp
├── EXERCISES.md
├── Makefile
└── README.md
```

## Ownership map

| Relationship | C++ representation | Meaning |
|---|---|---|
| Musician to instrument | `unique_ptr<Instrument>` | One musician owns the instrument |
| Ensemble to guest musician | `shared_ptr<Musician>` | Several ensembles keep one musician alive |
| Temporary access | `const Musician&` | Read an existing musician without becoming an owner |

`Musician::getLivingObjectCount()` and
`Instrument::getLivingObjectCount()` make automatic destruction observable in
the demonstration and tests.
