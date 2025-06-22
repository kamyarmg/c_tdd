
# Template of C Project with Modular Static Library and Test Suite

This project is a template of modular C codebase structured to support reusable components via a static library (`lib.a`) and an organized testing framework. It uses a `Makefile` to automate compilation, linking, and testing, with an emphasis on strict compiler warnings and runtime error detection via sanitizers.

## 📁 Project Structure


```
.
├── Makefile
├── src/                # Source files (.c) for main library
├── include/            # Header files (.h)
├── tests/              # Test source files and utils
│   ├── main.c          # Entry point for test execution
│   └── utils.h         # Utility macros and definitions for testing
├── build/              # Compiled object files and test executable (generated)
├── lib/                # Static library output directory (generated)
```

## ⚙️ Build Configuration

### Compiler Flags (`CFLAGS`)

The project is compiled with a strong set of warnings and runtime checks:

- `-Wall -Wextra -Wpedantic`: Enable most common warnings.
- `-Wshadow -Wconversion -Wsign-conversion`: Catch implicit type conversions.
- `-Wformat=2 -Wnull-dereference -Wstrict-overflow=5`: Extra safety.
- `-fsanitize=address,undefined`: Runtime error detection.
- `-std=c11`: C11 standard.
- `-Iinclude -Itests`: Include paths for headers.

### Linker Flags (`LDFLAGS`)

- `-lm`: Links the math library.

## 🛠️ Usage

### Build Everything

```sh
make
````

* Compiles all `.c` files in `src/` into object files.
* Archives object files into `lib/lib.a`.
* Compiles and links test files in `tests/` into `build/_test`.

### Run Tests

```sh
make test
```

Optionally, you can run tests with modes:

```sh
make test TEST_ARGS="all"       # Show all test results
make test TEST_ARGS="failfast"  # Stop at first failed test
```

### Clean Build Artifacts

```sh
make clean
```

Removes the `build/` and `lib/` directories.

## 🧪 Testing Framework

Custom minimal test macros are provided in `tests/utils.h`. Key features:

* Color-coded output (pass/fail).
* `TEST_ASSERT(condition, message)`
* `TEST_ASSERT_DOUBLE_EQUALS(a, b, message)`
* Support for `failfast` and `all` modes.
* Summary report after each test run.

Sample usage:

```c
TEST_ASSERT(x == 5, "x should be 5");
TEST_ASSERT_DOUBLE_EQUALS(result, 3.14, "PI approximation should be close");
```

## ✨ Example

Here's how the test runner behaves:

```sh
$ make test TEST_ARGS="all"
Running Tests (SHOW ALL TESTS)
----------------------------------------
[PASSED]: src/math.c:42 - add(2,3) == 5
[FAILURE]: src/math.c:47 - add(-1,-1) == -1
----------------------------------------
Total tests run: 2
Total tests failed: 1
```

## 📋 Requirements

* GCC (supports C11 and `-fsanitize`)
* GNU Make


---

Feel free to customize this README for your specific project and functionality.