**README.txt**

# Project Instructions

This project is divided into two exercises:

| Exercise | Related Files |
|:--------|:--------------|
| Exercise 1 (Encryption Algorithms Comparison) | code_practice1.cpp, code_practice1 (executable) |
| Exercise 2 (File Hashing and Timing) | code_practice2.cpp, code_practice2 (executable), input.txt |

Both exercises require OpenSSL and a C++ compiler (g++).

---

# Full Step-by-Step Guide

## Requirements (Common for Both Exercises)

### Ubuntu Linux:
1. Update your package list:
```bash
sudo apt update
```
2. Install necessary development tools and OpenSSL:
```bash
sudo apt install build-essential libssl-dev
```

### Windows:
- Recommended: Use WSL (Windows Subsystem for Linux) and follow Ubuntu steps.
- Alternatively, use MinGW + manually compiled OpenSSL libraries.

---

# Exercise 1: Encryption Algorithms Comparison

## Related Files:
- **code_practice1.cpp** (C++ Source File)
- **code_practice1** (Generated Executable after compilation)

## How to Compile:
```bash
g++ -o code_practice1 code_practice1.cpp -lcrypto
```

## How to Run:
```bash
./code_practice1
```

## Output:
The program will print encryption times for:
- DES
- 3DES
- AES-256

---

# Exercise 2: File Hashing and Timing

## Related Files:
- **code_practice2.cpp** (C++ Source File)
- **code_practice2** (Generated Executable after compilation)
- **input.txt** (Text file to be hashed)

## How to Prepare Input File:
Ensure that `input.txt` is not empty.
Example (if empty):
```bash
echo "Test data for hashing." > input.txt
```

## How to Compile:
```bash
g++ -o code_practice2 code_practice2.cpp -lcrypto
```

## How to Run:
```bash
./code_practice2
```

## Output:
The program will print:
- MD5 hash and time taken
- SHA1 hash and time taken
- SHA256 hash and time taken
- SHA512 hash and time taken

---

# Important Notes:
- Always use `g++` to compile C++ source files (NOT `gcc`).
- Always link OpenSSL with `-lcrypto`.
- If any `undefined reference` errors occur, verify OpenSSL development package (`libssl-dev`) is installed.
- Make sure input.txt has some data before hashing.

---
