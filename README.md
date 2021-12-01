# Advent of Code 2021

https://adventofcode.com/2021

### Compile

- compile the solution for each part using Make, e.g.:

  `cd day1`

  `make part1`

- some of the solutions use C++11 features:

  `export CXXFLAGS=-std=c++11`

### Run

- all the solutions take their input from stdin
- easiest way to run is by redirecting from a file:

  `./part1 < input.txt`

### Scaffold a new day

- run the scaffolding script:

  `./new <day-number>`, e.g. `./new 12` for day 12

- the script will create the directory and a simple boilerplate c++ program for each day
