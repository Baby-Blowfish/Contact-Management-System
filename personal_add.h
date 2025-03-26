/**
 * @file personal_add.h
 * @brief Header file for adding personal information.
 * @details Declares the function to add a new personal info node to the linked list.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal.h"

/**
 * @brief Adds a new personal information entry to the list.
 * @param head Pointer to the head of the linked list.
 * @param tail Double pointer to the tail of the linked list.
 * @param age Age of the person to add.
 * @param name Name of the person to add.
 * @param phone Phone number of the person to add.
 * @return Updated head pointer after addition.
 * @details Creates a new node with the given data and appends it to the list. If the list is empty, the new node becomes the head.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
Node *Add(Node *head, Node **tail, int age, const char *name, const char *phone);

#endif // ADD_H
