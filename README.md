# Contact Management System

## Project Overview
This project is a Contact Management System implemented in C. Users can add, delete, modify, and view contacts, with all data being stored in a binary file.

## Key Features
- Contact Addition: Add new contacts with name, age, and phone number information
- Contact Deletion: Remove existing contacts
- Contact Modification: Update existing contact information
- Contact Viewing: Display all stored contact information
- Data Persistence: Save all contact information to a binary file upon program termination

## Technical Features
- Linked List data structure implementation
- Binary file I/O operations
- Colored console output support
- Input validation and exception handling

## File Structure
- `personal.h/c`: Main program and core functionality
- `personal_add.h/c`: Contact addition functionality
- `personal_delete.h/c`: Contact deletion functionality
- `personal_modify.h/c`: Contact modification functionality
- `personal_print.h/c`: Contact display functionality
- `personal_load.h/c`: Data loading functionality
- `get_string_int.h/c`: Input processing utilities
- `node.h`: Linked list node structure definition

## Build and Execution
1. Build the project using Makefile:
```bash
make
```
2. Run the executable:
```bash
./personal
```

## Data Storage
- All contact information is stored in `data.bin` file in binary format
- Previous data is automatically loaded when the program starts

## Author
- Kim Hyo Jin