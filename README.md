# Theater

This project is a university assignment at the University of Brasilia, for the Programming Techniques 1 course.

# Installation

## CodeBlocks

CodeBlocks is mandatory for this project. You can open `Theater.cbp` in CodeBlocks and select the target to run.

The project contains domains (base types) and entities for a Theater. Each one of these elements are placed in their folder alongside with their tests.

## CMake

You can use CMake instead. Just run

```
mkdir build
cmake -G "<GENERATOR>" -S ./src -B ./build
cmake --build ./build
```

If you are using Windows, `<GENERATOR>` will be "MinGW Makefiles".

# Running Tests

The tests have been added to `GitHub Actions` for automatic testing. However, you can run the tests manually by compiling the Tests target and running the executable.
