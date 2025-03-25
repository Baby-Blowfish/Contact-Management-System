#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal.h"
#include "personal_add.h"

// Add(): 데이터 추가
Node* Add(Node* head, Node** tail, int age, const char* name, const char* phone) {
    if (age <= 0) {
        printf("[Error] Invalid age entered.\n");
        return head;
    }

    if (strlen(name) == 0 || strlen(phone) == 0) {
        printf("[Error] Name or phone cannot be empty.\n");
        return head;
    }

    Node *newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        perror("[Error] Memory allocation failed");
        return head;
    }

    newnode->data.nAge = age;
    strncpy(newnode->data.szName, name, MAX_NAME_LENGH);
    strncpy(newnode->data.szPhone, phone, MAX_PHONE_LENGTH);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }

    printf("[Success] '%s' added successfully.\n", name);
    return head;
}

