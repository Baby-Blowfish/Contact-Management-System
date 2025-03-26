#include "personal_delete.h"

// Delete(): 다중 검색 기반 삭제 기능
int Delete(Node** head, Node** tail) {

    int mode = 0;
    char keyword[MAX_PHONE_LENGTH] = {0};
    char confirm[MAX_NAME_LENGH] = {0};
    Node* cur = *head;
    Node* prev = NULL;
    int deleted = 0;
    int match = 0;

    // 검색 기준 입력
    printf("\nChoose search field: 1) Name  2) Age  3) Phone\n> ");
    mode = inputIntRequired();

    // 키워드 입력
    printf("Enter keyword: ");
    inputTextRequired(keyword, MAX_NAME_LENGH);

    while (cur) {
        match = 0;
        if (mode == 1 && strcmp(cur->data.szName, keyword) == 0)
            match = 1;
        if (mode == 2 && atoi(keyword) == cur->data.nAge)
            match = 1;
        if (mode == 3 && strcmp(cur->data.szPhone, keyword) == 0)
            match = 1;

        if (match) {
            printf(COLOR_CYAN "\n[Match] Name: %s, Age: %d, Phone: %s\n" COLOR_RESET,
                    cur->data.szName, cur->data.nAge, cur->data.szPhone);

            printf("Delete this entry? (yes/no): ");
            inputYesOrNo(confirm, MAX_NAME_LENGH);

            if (strcmp(confirm, "yes") == 0) {
                Node* temp = cur;
                if (prev == NULL) {
                    *head = cur->next;
                } else {
                    prev->next = cur->next;
                }
                if (cur == *tail) {
                    *tail = prev;
                }
                cur = cur->next;
                free(temp);
                deleted++;
                printf(COLOR_CYAN "[Success] Entry deleted.\n" COLOR_RESET);
                continue;
            }
            else if (strcmp(confirm, "no") == 0)
            {
                prev = cur;
                cur = cur->next; // 다음 노드로 이동
                continue;
            }
        }

        prev = cur;
        cur = cur->next;
    }

    return deleted;
}