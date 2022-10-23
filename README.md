# libcsv
CSV file static library in C++

## Demo
Visit [test.cpp](tests/test.cpp) for demo code.
Run `make test` to verify demo.

## Usage

#### Build
- use `make` to build.
- copy everything from `lib/` to your required destination.
- files you copy from `lib/` includes
  - `libcsv.hpp` c++ header file
  - `libcsv.a` static library

#### Compilation syntax
The following syntax works for `g++` and `clang++`.
```bash
c++ -Wall <source-files> -L<lib-directory> -lcsv -o <output-file>
```
Here `lib-directory` is the path to the directory where you copy `libcsv.a` to.

Here `c++` command is your default C++ compiler command.
