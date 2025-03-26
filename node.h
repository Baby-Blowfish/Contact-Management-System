/**
 * @file node.h
 * @brief Defines the Node structure and personal info data structure.
 * @details Contains the data structure for handling a linked list of personal information entries.
 * @date 2025-03-26
 * @author Kim Hyo Jin
 */

#ifndef NODE_H
#define NODE_H

#include "personal.h"

/**
 * @struct _tPersonalInfo
 * @brief Stores personal information.
 * @details Includes age, name, and phone number fields.
 */
typedef struct _tPersonalInfo
{
    int nAge;
    char szName[MAX_NAME_LENGH];
    char szPhone[MAX_PHONE_LENGTH];
} PERSON_INFO, *PPERSON_INFO;

/**
 * @struct node_
 * @brief Node structure for singly linked list.
 * @details Each node holds personal info and a pointer to the next node.
 */
typedef struct node_
{
    PERSON_INFO data;
    struct node_ *next;
} Node;

#endif // NODE_H
