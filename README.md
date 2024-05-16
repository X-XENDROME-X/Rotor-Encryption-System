# Rotor-Encryption-System
This C++ project implements a rotor machine encryption system capable of encrypting and decrypting files. It includes a Makefile for easy compilation and provides a command-line interface for various operations.

The project consists of the following files:

- **Makefile**: Used to compile the C++ program named "rotorMachine" from source code files "rotorMachine.cpp" and "Main.cpp". It specifies compiler settings and rules for building the executable and cleaning up generated files.

- **Main.cpp**: Behaves as a command-line interface for the rotor machine, initializing rotor configurations, and encrypting or decrypting files based on user input.

- **rotorMachine.cpp**: Contains the code for rotor machine encryption, providing file input/output functions, rotor manipulation, and encryption/decryption functionality.

- **rotorMachine.h**: Header file providing function declarations for initializing, configuring, and using rotors to encrypt and decrypt files.

## Usage

1. To build the rotorMachine executable:
   ```bash
   make
   ```
2. Initialize Rotor Machine
   ```bash
   ./rotorMachine -i <config_file>
   ```
3. To encrypt a file with a specified rotor configuration
   ```bash
   ./rotorMachine -e <input_file> <output_file> -r <rotor_position_1> <rotor_position_2> -i <config_file>
   ```
4. To decrypt a file with a specified rotor configuration
   ```bash
   ./rotorMachine -d <input_file> <output_file> -r <rotor_position_1> <rotor_position_2> -i <config_file>
   ```
