#include "personal_add.h"

// Add(): 데이터 추가
Node* Add(Node* head, Node** tail, int age, const char* name, const char* phone) {
    if (age <= 0) {
        printf("\n\033[31m[Error] Invalid age entered.\033[0m\n\n");
        return head;
    }

    if (strlen(name) == 0 || strlen(phone) == 0) {
        printf("\n\033[31m[Error] Name or phone cannot be empty.\033[0m\n\n");
        return head;
    }

    Node *newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        perror("\n\033[31m[Error] Memory allocation failed\033[0m\n\n");
        return head;
    }

    memset(newnode, 0, sizeof(Node));

    newnode->data.nAge = age;
    strncpy(newnode->data.szName, name, MAX_NAME_LENGH);
    newnode->data.szName[MAX_NAME_LENGH - 1] = '\0';
    strncpy(newnode->data.szPhone, phone, MAX_PHONE_LENGTH);
    newnode->data.szPhone[MAX_PHONE_LENGTH - 1] = '\0';

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }

    printf("\n\033[1;32m [Success] '%s' added successfully.\033[0m\n\n", name);
    return head;
}

