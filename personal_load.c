#include "personal_load.h"

// Load(): 데이터 불러오기
Node* Load(Node** tail, const char* filename) {

    Node* head = NULL;
    PERSON_INFO temp = { 0, "", ""};

    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("[Warning] No previous data found. Starting with an empty contact list.\n");
        *tail = NULL;
        return NULL;
    }

    *tail = NULL;

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
