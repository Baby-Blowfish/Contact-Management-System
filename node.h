#ifndef NODE_H
#define NODE_H

#include "personal.h"

typedef struct _tPersonalInfo {
    int nAge;
    char szName[MAX_NAME_LENGH];
    char szPhone[MAX_PHONE_LENGTH];
} PERSON_INFO, *PPERSON_INFO;

typedef struct node_ {
    PERSON_INFO data;
    struct node_ *next;
} Node;

#endif  // NODE_H
