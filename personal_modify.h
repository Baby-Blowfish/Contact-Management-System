/**
 * @file personal_modify.h
 * @brief Header file for modifying personal information.
 * @details Declares the function to search and modify an entry in the personal information list.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef MODIFY_H
#define MODIFY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal.h"
#include "get_string_int.h"

/**
 * @brief Modifies a personal information entry in the list.
 * @param head Pointer to the head of the linked list.
 * @param keyword Keyword to match name, age, or phone number for modification.
 * @return 1 if modification was successful, 0 otherwise.
 * @details Searches for an entry using the keyword and allows modification of name, age, and phone. Skips fields if left empty or unchanged.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
int Modify(Node *head);

#endif // MODIFY_H
