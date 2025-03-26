/**
 * @file personal_delete.h
 * @brief Header file for deleting personal information.
 * @details Declares the function to delete a personal info node from the linked list based on a keyword.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef DELETE_H
#define DELETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal.h"

/**
 * @brief Deletes a personal information entry from the list.
 * @param head Double pointer to the head of the linked list.
 * @param tail Double pointer to the tail of the linked list.
 * @param keyword Keyword to match name, age, or phone number.
 * @return 1 if deletion was successful, 0 otherwise.
 * @details Searches the list for a matching entry using the keyword and deletes the node if found. Updates head or tail if necessary.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
int Delete(Node **head, Node **tail);

#endif // DELETE_H
