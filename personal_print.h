/**
 * @file personal_print.h
 * @brief Header file for printing personal information.
 * @details Declares the function to print all personal info stored in the linked list.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include "personal.h"

/**
 * @brief Prints all personal information in the list.
 * @param head Pointer to the head of the linked list.
 * @return None
 * @details Iterates through the linked list and prints each person's name, age, and phone number.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
// PrintInfo(): 모든 데이터 출력
void PrintInfo(Node *head);

#endif