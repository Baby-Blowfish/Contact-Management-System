/**
 * @file personal_load.h
 * @brief Header file for loading personal information from a file.
 * @details Declares the function to load personal info data from a binary file and reconstruct the linked list.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef LOAD_H
#define LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal.h"

/**
 * @brief Loads personal information from a binary file.
 * @param tail Double pointer to the tail of the linked list.
 * @param filename Name of the binary file to load data from.
 * @return Head pointer to the reconstructed linked list.
 * @details Reads `PERSON_INFO` records from the specified file and creates a linked list. Updates tail as the list is reconstructed.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */
Node *Load(Node **tail, const char *filename);

#endif // LOAD_H
