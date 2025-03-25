#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personal_load.h"

#define FILE_NAME "data.bin"

// Load(): 데이터 불러오기
Node* Load(Node** tail) {
    FILE* file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("[Warning] No previous data found. Starting with an empty contact list.\n");
        *tail = NULL;
        return NULL;
    }

    Node* head = NULL;
    *tail = NULL;

    PERSON_INFO temp;
    while (fread(&temp, sizeof(PERSON_INFO), 1, file)) {
        Node *newnode = (Node*)malloc(sizeof(Node));
        if (!newnode) {
            perror("[Error] Memory allocation failed");
            fclose(file);
            return head;
        }

        newnode->data = temp;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            (*tail)->next = newnode;
        }

        *tail = newnode;
    }

    fclose(file);

    // 데이터가 없는 경우 tail을 명시적으로 NULL로 설정
    if (!head) {
        *tail = NULL;
    }

    printf("Data loaded successfully.\n");
    return head;
}
