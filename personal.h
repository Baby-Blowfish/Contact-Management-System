#ifndef PERSONAL_H
#define PERSONAL_H

#define MAX_NAME_LENGH 10
#define MAX_PHONE_LENGTH 20

typedef struct _tPersonalInfo{

    int nAge;

    char szName[MAX_NAME_LENGH];
    char szPhone[MAX_PHONE_LENGTH];
}PERSON_INFO, *PPERSON_INFO;

typedef struct node_{
    PERSON_INFO data;
    struct node_ *next;
} Node;

#endif
