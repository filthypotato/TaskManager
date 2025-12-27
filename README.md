# TaskManager

A C++ command-line task management application with file manipulation and encryption capabilities.

## Features

- **File Manipulation**
  - Create new files with custom content
  - Read and display file contents
  - Update/append to existing files
  - Delete files
  - Encrypt/decrypt files using XOR cipher with a passphrase

- **Input Validation**
  - Integer-only input validation for menu selections
  - File existence checking
  - Error handling for file operations

## Building

### Linux/macOS

Use the provided build script:

```bash
./build.sh          # Build only
./build.sh --run    # Build and run
```

The script compiles with:
- C++20 standard
- `-Wall -Wextra` warnings enabled
- Output: `build/TaskManager`

### Manual Build

```bash
g++ -std=c++20 -Wall -Wextra -I./src ./src/*.cpp -o build/TaskManager
```

### Windows (Visual Studio)

Open `TaskManager.sln` in Visual Studio and build from there.

## Usage

Run the executable:

```bash
./build/TaskManager
```

### Main Menu Options

1. **File manipulation** - Access file operations
2. **Get system information** - (Work in Progress)
3. **Set a reminder** - (Work in Progress)
4. **Exit** - Quit the program

### File Manipulation Options

1. **Create a file** - Create a new file and write content (type 'done' to finish)
2. **Read a file** - Display the contents of an existing file
3. **Update a file** - Append new content to an existing file
4. **Delete a file** - Remove a file from the filesystem
5. **Encryption/Decryption** - Encrypt or decrypt files using XOR cipher

### Encryption/Decryption

- **Encryption**: Creates a `.enc` file with encrypted content
- **Decryption**: Creates a `.dec` file with decrypted content
- Uses XOR cipher with a user-provided passphrase
- Works with any file type (binary-safe)

## Requirements

- C++20 compatible compiler (g++, clang++, MSVC)
- Linux, macOS, or Windows

## Notes

- File encryption creates new files (`.enc` for encrypted, `.dec` for decrypted)
- Original files are preserved after encryption/decryption
- The encryption uses XOR cipher - suitable for basic obfuscation but not cryptographically secure for sensitive data

