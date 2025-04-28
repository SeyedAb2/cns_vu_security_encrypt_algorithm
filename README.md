**# Project Instructions**

## Exercises

| Exercise | Related Files |
|:--------|:--------------|
| **Exercise 1:** Encryption Algorithms Comparison | `code_practice1.cpp`, `code_practice1` (executable) |
| **Exercise 2:** File Hashing and Timing | `code_practice2.cpp`, `code_practice2` (executable), `input.txt` |

Both exercises require **OpenSSL** and a **C++ compiler (g++)**.

---

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
- **Recommended:** Use **WSL** (Windows Subsystem for Linux) and follow Ubuntu steps.
- **Alternatively:** Use **MinGW** and manually compile OpenSSL libraries.

---

## Exercise 1: Encryption Algorithms Comparison

### Related Files:
- `code_practice1.cpp`
- `code_practice1` (Executable)

### How to Compile:
```bash
g++ -o code_practice1 code_practice1.cpp -lcrypto
```

### How to Run:
```bash
./code_practice1
```

### Output:
The program will print encryption times for:
- DES
- 3DES
- AES-256

---

## Exercise 2: File Hashing and Timing

### Related Files:
- `code_practice2.cpp`
- `code_practice2` (Executable)
- `input.txt` (File to be hashed)

### How to Prepare Input File:
Make sure `input.txt` is **not empty**.
Example (if empty):
```bash
echo "Test data for hashing." > input.txt
```

### How to Compile:
```bash
g++ -o code_practice2 code_practice2.cpp -lcrypto
```

### How to Run:
```bash
./code_practice2
```

### Output:
The program will print:
- MD5 hash and computation time
- SHA1 hash and computation time
- SHA256 hash and computation time
- SHA512 hash and computation time

---

## Important Notes:
- Always compile C++ source files using **g++**, not **gcc**.
- Always link OpenSSL with `-lcrypto`.
- If any `undefined reference` errors occur, verify that **libssl-dev** is installed.
- Ensure `input.txt` contains some data before running the hashing program.

---

## Example Test File Creation
```bash
echo "Hello OpenSSL Testing" > input.txt
```

---

## Final Reminder
- Ensure OpenSSL is properly installed.
- Ensure you use correct compilation commands.
- Both programs will display timing results for performance comparison.

---
