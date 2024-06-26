# Simple Shell

A simple Unix-like shell implementation in C.

## Overview

This project is a minimalistic shell implementation designed to demonstrate fundamental shell functionalities. It focuses on core features such as:

- Executing commands
- Handling command-line arguments
- Interacting with the environment

## Usage

1. Compile the code using a C compiler like GCC:
```bash
gcc -o hsh *.c
```
2. Run the shell:
```bash
./hsh
```
3. Type commands as you would in a standard Unix shell.


## Implemented Features

- Reads user input from the command line.
- Parses commands and arguments using strtok.
- Executes commands using fork, execve, and waitpid.
- Handles errors with appropriate messages.
- Searches for executables in the PATH environment variable.

## Contributors

- [Farhad Asgarzada](https://github.com/ferhadesger)
- [Asmar Jabbarova](https://github.com/asmarjabbarova)

## License

Feel free to customize the README according to the specific details of your project and the preferences of your audience

