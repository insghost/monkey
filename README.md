# Monkey Grid problem

## Usage
`make clean && make && make test`
`./monkey 19`

The argument to the monkey binary should be the max absolute value (19)

`make test` diff should be empty, otherwise there's a problem.

This assumes you have `g++` installed, if you don't you should specify the
correct compiler. It also assumes C++ 11 presets to allow the `auto` keyword.