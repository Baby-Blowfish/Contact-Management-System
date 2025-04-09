# Contact Management System

A C-based contact management system that implements a robust data management solution using linked list data structures and binary file I/O operations.

## Technology Stack

### Core Technologies
- **Language**: C (ANSI C)
- **Build System**: GNU Make
- **Documentation**: Doxygen
- **Version Control**: Git
- **IDE Support**: VSCode

### Development Tools
- **Compiler**: GCC (GNU Compiler Collection)
- **Debugger**: GDB (GNU Debugger)
- **Build Tools**: Make
- **Documentation Generator**: Doxygen

## System Architecture

### 1. Core Components

#### Data Management Layer
- **Data Structure**: Singly Linked List
  - Implements dynamic memory allocation
  - Supports efficient insertion and deletion
  - Maintains data integrity through pointer management

#### File I/O Layer
- **Storage Format**: Binary File
  - Direct memory-to-disk mapping
  - Efficient data serialization
  - Platform-independent data storage

#### User Interface Layer
- **Console Interface**
  - Color-coded output for better readability
  - Input validation and sanitization
  - Interactive menu system

### 2. Module Architecture

#### Core Modules
1. **Personal Information Management** (`personal.c/h`)
   - Main program logic
   - Menu system implementation
   - Program flow control
   - Memory management

2. **Data Structure Definition** (`node.h`)
   - Linked list node structure
   - Personal information structure
   - Type definitions and constants

#### Functional Modules
1. **Contact Operations**
   - Addition (`personal_add.c/h`)
   - Deletion (`personal_delete.c/h`)
   - Modification (`personal_modify.c/h`)
   - Display (`personal_print.c/h`)

2. **Data Persistence**
   - File Loading (`personal_load.c/h`)
   - Data Serialization
   - Error Handling

3. **Utility Functions**
   - Input Processing (`get_string_int.c/h`)
   - Validation Routines
   - Error Checking

## Component Details

### 1. Data Structures

#### Personal Information Structure
```c
typedef struct _tPersonalInfo {
    int nAge;                    // Age of the contact
    char szName[MAX_NAME_LENGH]; // Contact name
    char szPhone[MAX_PHONE_LENGTH]; // Phone number
} PERSON_INFO, *PPERSON_INFO;
```

#### Linked List Node
```c
typedef struct node_ {
    PERSON_INFO data;           // Personal information
    struct node_ *next;         // Pointer to next node
} Node;
```

### 2. File Operations

#### Binary File Format
- **File Name**: `data.bin`
- **Storage Method**: Direct binary writing
- **Data Organization**: Sequential storage of PERSON_INFO structures
- **Error Handling**: File existence checks and error reporting

### 3. Build System

#### Makefile Configuration
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = personal.c personal_load.c personal_add.c personal_print.c \
      personal_delete.c personal_modify.c get_string_int.c
OBJ = $(SRC:.c=.o)
TARGET = contact_manager
```

#### Compilation Process
1. Source file compilation
2. Object file generation
3. Dependency resolution
4. Final binary creation

### 4. Documentation System

#### Doxygen Configuration
- **Input**: All source and header files
- **Output**: HTML and LaTeX documentation
- **Documentation Style**: Javadoc-style comments
- **Output Directory**: `docs/`

## Implementation Details

### 1. Memory Management
- Dynamic allocation for new contacts
- Proper deallocation during deletion
- Memory leak prevention
- Pointer validation

### 2. Error Handling
- Input validation
- File operation checks
- Memory allocation verification
- Pointer validity checks

### 3. Data Validation
- Name length verification
- Phone number format checking
- Age range validation
- Duplicate entry prevention

### 4. User Interface
- Color-coded messages
  - Red: Error messages
  - Green: Success messages
  - Yellow: Warnings
  - Blue: Information
- Input prompts
- Status messages
- Error notifications

## Build and Execution

### Prerequisites
- GCC compiler (version 4.8 or higher)
- GNU Make (version 3.81 or higher)
- Doxygen (version 1.8 or higher)

### Building the Project
```bash
# Compile the project
make

# Clean build files
make clean

# Generate documentation
doxygen Doxyfile
```

### Running the Application
```bash
# Execute the program
./contact_manager
```

## Development Guidelines

### 1. Code Style
- ANSI C compliance
- Consistent indentation
- Clear naming conventions
- Comprehensive comments

### 2. Documentation
- Function documentation
- Parameter descriptions
- Return value documentation
- Error condition documentation

### 3. Error Handling
- Graceful error recovery
- User-friendly error messages
- Proper resource cleanup
- State consistency maintenance

## Author

Kim Hyo Jin

## License

This project is open source and available under the MIT License.