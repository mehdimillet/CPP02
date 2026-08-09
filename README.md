# CPP Module 02 — Ad-hoc Polymorphism & Operator Overloading

![C++](https://img.shields.io/badge/C%2B%2B-98-00599C?style=flat&logo=cplusplus&logoColor=white)
![42](https://img.shields.io/badge/42-School-000000?style=flat)
![Status](https://img.shields.io/badge/status-complete-success?style=flat)

> Part of the 42 School C++ Piscine. Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form — built around a custom fixed-point number type.

---

## Overview

This module builds a `Fixed` class: a **fixed-point number** type that C++ lacks natively. Across the exercises it grows from a bare value holder into a fully-featured arithmetic type with comparison, arithmetic, and increment operators — all through **operator overloading**. It also introduces the **Orthodox Canonical Form**, mandatory for every class from here on.

All code compiles under the C++98 standard with no external libraries.

---

## Concepts Covered

| Concept | Description |
|---------|-------------|
| Orthodox Canonical Form | Default ctor, copy ctor, copy assignment, destructor |
| Fixed-point numbers | Storing decimals inside an integer (×256) |
| Operator overloading | Comparison, arithmetic, and increment operators |
| `std::ostream` overload | Making a custom type printable with `<<` |
| Pre vs post increment | Distinguished by a dummy `int` parameter |
| `static` member functions | `min` / `max` called without an instance |
| `const` attributes | Immutable members initialized via init lists |
| Initialization lists | Required for references and `const` members |

---

## Exercises

### ex00 — My First Class in Orthodox Canonical Form

The `Fixed` class in its simplest form: an integer raw value, a static constant number of fractional bits (8), and the four canonical functions. It can only represent `0` for now, but it establishes the OCF that every later class must follow.

Focus: the Orthodox Canonical Form, `getRawBits`/`setRawBits`.

### ex01 — Towards a more useful fixed-point number class

The class becomes useful. New constructors convert from `int` and `float`, and `toInt()`/`toFloat()` convert back. An overloaded `<<` operator makes a `Fixed` printable as a floating-point value.

Focus: conversion between representations, overloading `operator<<`, `roundf`.

### ex02 — Now we're talking

The class becomes a full arithmetic type by overloading:

- The **6 comparison operators**: `>`, `<`, `>=`, `<=`, `==`, `!=`
- The **4 arithmetic operators**: `+`, `-`, `*`, `/`
- The **4 increment/decrement operators**: pre- and post- `++`/`--`

Plus four `static` `min`/`max` functions (const and non-const overloads). Fixed-point multiplication and division require rescaling by the fractional factor — a subtle but essential detail.

Focus: full operator overloading, static member functions, the ×256 scaling trap.

### ex03 — BSP *(bonus)*

A practical use of the `Fixed` class: a `Point` class with `const` coordinates, and a `bsp()` function that determines whether a point lies **inside a triangle** using signed triangle areas. Points on an edge or vertex count as outside.

Focus: `const` attributes, initialization lists, applying the completed `Fixed` class.

---

## Build & Run

Each exercise is self-contained in its own directory.

```bash
cd ex02
make
./fixed           # executable name may differ per exercise
```

For ex03:

```bash
cd ex03
make
./bsp 0 0 10 0 0 10 2 2       # triangle (0,0)(10,0)(0,10), point (2,2)
```

Available Makefile rules:

```bash
make        # compile
make clean  # remove object files
make fclean # remove object files and executable
make re     # rebuild from scratch
```

### Compilation flags

```
c++ -Wall -Wextra -Werror -std=c++98
```

---

## Key Takeaways

- The **Orthodox Canonical Form** guards against subtle copy bugs; the difference between the copy constructor (object being created) and the assignment operator (object already exists) is the classic point of confusion.
- A **fixed-point** value is just an integer scaled by a power of two — multiplication and division must rescale to stay correct.
- **Pre-increment** returns a reference to the object; **post-increment** must save and return the previous value, which is why it takes a dummy `int` and returns a copy.

---

## Author

**memillet** — 42 School